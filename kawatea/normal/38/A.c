#include <stdio.h>

int main()
{
     int n, a, b, s = 0, i;
     int d[100];

     scanf("%d", &n);

     for (i = 0; i < n - 1; i++) scanf("%d", &d[i]);

     scanf("%d %d", &a, &b);

     for (i = a; i < b; i++) s += d[i - 1];

     printf("%d\n", s);

     return 0;
}