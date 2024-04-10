#include <stdio.h>

int main()
{
     int n, x, i;
     int a[3000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      scanf("%d", &x);

      a[x - 1] = 1;
     }

     for (i = 0; i < 3000; i++) {
      if (a[i] == 0) break;
     }

     printf("%d\n", i + 1);

     return 0;
}