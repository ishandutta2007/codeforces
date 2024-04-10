#include <stdio.h>

int main()
{
     int n, m, a;
     long long x, y;

     scanf("%d %d %d", &n, &m, &a);

     x = n / a;
     if (n % a != 0) x++;

     y = m / a;
     if (m % a != 0) y++;

     printf("%I64d\n", x * y);

     return 0;
}