#include <stdio.h>

int main()
{
     int n, x, y, p = 0;

     scanf("%d %d %d", &n, &x, &y);

     while ((x + p) * 100 < n * y) p++;

     printf("%d\n", p);

     return 0;
}