#include <stdio.h>

int main()
{
     int n, i;

     scanf("%d", &n);

     n *= 2;

     for (i = 0; i < n; i++) {
      if (i * (i + 1) == n) {
           puts("YES");

           return 0;
      }
     }

     puts("NO");

     return 0;
}