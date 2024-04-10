#include <stdio.h>

int main()
{
     int n, p = 0, i, j;

     scanf("%d", &n);

     for (i = 1; i <= n; i++) {
      int m = i, x = 0;

      for (j = 2; j <= m; j++) {
           if (m % j == 0) {
            x++;

            while (m % j == 0) m /= j;
           }
      }

      if (m == 1 && x == 2) p++;
     }

     printf("%d\n", p);

     return 0;
}