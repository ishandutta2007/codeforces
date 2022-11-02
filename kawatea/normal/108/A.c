#include <stdio.h>

int main()
{
     int h, m;
     
     scanf("%d:%d", &h, &m);

     while (1) {
      int c = h % 10 * 10 + h / 10;

      if (c > m && c < 60) {
           printf("%02d:%02d\n", h, c);

           break;
      }

      h++;
      h %= 24;
      m = -1;
     }

     return 0;
}