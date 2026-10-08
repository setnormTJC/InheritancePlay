#include <iostream>

class Rectangle
{
protected:
    int length = 0;
    int width = 0;

public:
    Rectangle() = default;
    Rectangle(int length, int width)
        :
    length(length),
    width(width)
    {
    }

    //example of a "custom copy constructor"
    // Rectangle(const Rectangle& rectangle) //or set = default since "trivial"
    //     :
    // length(rectangle.length),
    // width(rectangle.width)
    // {
    // }

};

class Box : public Rectangle
{
    int height = 0;

public:
    Box() = default;
    Box(int length, int width, int height)
        :
    Rectangle(length, width),
    height(height)
    {
    }

    Box(const Rectangle& rectangle, int height)
        :
    Rectangle(rectangle), //THIS is the code that I couldn't remember how to write properly
    //it is calling the "default copy constructor" of the Rectangle class (defining a custom copy constructor is sometimes useful)
    height(height)
    {
    }
};


int main()
{
    Rectangle rectangle(1, 2);
    Box box(1, 2, 3);

    Box otherBox(rectangle, 3);

    return 0;
}
