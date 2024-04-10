#include <stdio.h>

int main()
{
     int n, s = 1, i;

     scanf("%d", &n);

     for (i = 0; i < n - 1; i++) {
      if (i != 0) putchar(' ');

      s += i + 1;

      s %= n;

      if (s == 0) s = n;

      printf("%d", s);
     }

     puts("");

     return 0;
}