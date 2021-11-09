#include <SFML/Graphics.hpp>
#include <math.h>
#define pi 3.1415926536

using namespace sf; // подключаем пространство имен sf


void draw_line(int x1, int y1, int x2, int y2, RenderWindow &window){
    // Загатовка линии
    
    Vertex line[] = {
        Vertex(Vector2f(x1, y1)),
        Vertex(Vector2f(x2, y2))
    };
            
    window.draw(line, 2, Lines);
}

void square(int n, int x0, int y0, int a, double f, RenderWindow &window){
    if (n==0){return;}
    int x1, x2, x3, y1, y2, y3;
    x1 = (int)(x0 + a*cos(f));      y1 = (int)(y0 - a*sin(f));
    x2 = (int)(x1 - a*sin(f));      y2 = (int)(y1 - a*cos(f));
    x3 = (int)(x0 - a*sin(f));      y3 = (int)(y0 - a*cos(f));
    
    draw_line(x0, y0, x1, y1, window);
    draw_line(x1, y1, x2, y2, window);
    draw_line(x2, y2, x3, y3, window);
    draw_line(x3, y3, x0, y0, window);
    
    n--;
    
    square(n, x3, y3, a/2, f+0.5, window);

    
}


int main()
{
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(1000, 1000), "SFML Works!");
 
    // Главный цикл приложения: выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                window.close(); // тогда закрываем его
        }
        // Установка цвета фона
        window.clear(Color(0, 0, 0, 0));
 
        //draw_line(500, 800, 500, 400, window);
        square(5, 500, 800, 200, 0, window);

        
        // Отрисовка окна
        window.display();
    }
 
    return 0;
}




