#include <stdio.h>

int main()
{
     int w;

     scanf("%d", &w);

     if (w % 2 == 0 && w >= 4) {
	  puts("YES");
     } else {
	  puts("NO");
     }

     return 0;
}