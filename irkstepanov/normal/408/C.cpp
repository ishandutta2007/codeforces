#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool eq (double a, double b)
{
    return (abs(a - b) < 0.0001);
}

bool zed (double a)
{
    return (eq(floor(a), a) || eq(ceil(a), a));
}

bool sq (int x)
{
    double d = sqrt(x * 1.0);
    return zed (d);
}

int main()
{

    int a, b;
    cin >> a >> b;

    int x1 = 0, y1 = 0, x2, y2, x3, y3;

    y3 = 1;
    while (b > y3)
    {
        int r = b * b - y3 * y3;
        if (sq(r))
        {
            r = (int) (floor(sqrt(r * 1.0)));
            if ((a * r) % b == 0)
                {y2 = (a * r) / b;
                    x3 = r;
                if ((y2 * y3) % x3 == 0)
                    {x2 = -y2 * y3 / x3;
            if (y2 != y3 && x2 != x3) {cout << "YES" << "\n" << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n" << x3 << " " << y3; return 0;} } }
        }
        y3++;
    }

    cout << "NO";

}