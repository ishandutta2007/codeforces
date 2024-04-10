#include <stdio.h>

int main()
{
     int n, p = 0, i;
     int a[1000] = {0};

     a[0] = 1;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      p += i + 1;
      p %= n;

      a[p]++;
     }

     for (i = 0; i < n; i++) {
      if (a[i] == 0) {
           puts("NO");

           return 0;
      }
     }

     puts("YES");

     return 0;
}