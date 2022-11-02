#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
      return a;
     } else {
      return b;
     }
}

int main()
{
     int y, w, m;

     scanf("%d %d", &y, &w);

     m = max(y, w);

     switch (m) {
     case 1 : puts("1/1"); break;
     case 2 : puts("5/6"); break;
     case 3 : puts("2/3"); break;
     case 4 : puts("1/2"); break;
     case 5 : puts("1/3"); break;
     case 6 : puts("1/6"); break;
     }

     return 0;
}