#include <stdio.h>

int main()
{
     int h, m;
     double a, b;

     scanf("%d:%d", &h, &m);

     a = h * 30 + m * 30 / 60.0;
     b = m * 6;

     if (a >= 360) a -= 360;

     printf("%f %f\n", a, b);

     return 0;
}