#include <stdio.h>
#include <math.h>

int main()
{
     int x, y, d, i;

     scanf("%d %d", &x, &y);

     d = (int)sqrt(x * x + y * y);

     for (i = 0; i * i <= x * x + y * y; i++) {
      if (i * i == x * x + y * y) {
           puts("black");

           return 0;
      }
     }

     if (x * y > 0) {
      if (d % 2 == 0) {
           puts("black");
      } else {
           puts("white");
      }
     } else {
      if (d % 2 == 0) {
           puts("white");
      } else {
           puts("black");
      }
     }

     return 0;
}