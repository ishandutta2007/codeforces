#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <bitset>
#include <cmath>

#define pb push_back

using namespace std;

const double eps = 0.00000001;

bool geq (double a, double b)
{
    return (a - b >= eps || abs(a - b) <= eps);
}

bool f (double a, double l, double r)
{
    return (geq(a, l) && !geq(a, r));
}

int main()
{

    double a, d;
    int n;

    scanf("%lf", &a);
    scanf("%lf", &d);
    scanf("%d", &n);

    double x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += d;
        x = fmod (x, 4 * a);
        //while (geq(x, 4 * a))
        //    x -= 4 * a;
        if (f(x, 0, a)) printf("%.4lf %.4lf\n", x, 0.0);
        else if (f(x, a, 2 * a)) printf("%.4lf %.4lf\n", a, x - a);
        else if (f(x, 2 * a, 3 * a)) printf("%.4lf %.4lf\n", 3 * a - x, a);
        else printf("%.4lf %.4lf\n", 0.0, 4 * a - x);
    }

}