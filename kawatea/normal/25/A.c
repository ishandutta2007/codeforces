#include <stdio.h>

int main()
{
     int n, p = 0, q = 0, i;
     int a[100];
     int b[2] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);

      if (a[i] % 2 == 0) {
           b[0]++;

           if (b[0] == 1) p = i + 1;
      } else {
           b[1]++;

           if (b[1] == 1) q = i + 1;
      }
     }

     if (b[0] == 1) {
      printf("%d\n", p);
     } else {
      printf("%d\n", q);
     }

     return 0;
}