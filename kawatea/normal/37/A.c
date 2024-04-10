#include <stdio.h>

int main()
{
     int n, s = 0, max = 0, i;
     int a[1000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      int x;

      scanf("%d", &x);

      a[x - 1]++;
     }

     for (i = 0; i < 1000; i++) {
      if (a[i] > 0) s++;

      if (a[i] > max) max = a[i];
     }

     printf("%d %d\n", max, s);

     return 0;
}