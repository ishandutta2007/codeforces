#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, min = 10000, num1 = 0, num2 = 0, i;
     int a[101];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     a[n] = a[0];

     for (i = 0; i < n; i++) {
      if (abs(a[i] - a[i + 1]) < min) {
           min = abs(a[i] - a[i + 1]);

           num1 = i;
           num2 = i + 1;
      }
     }

     if (num1 == n - 1) num2 = 0;

     printf("%d %d\n", num1 + 1, num2 + 1);

     return 0;
}