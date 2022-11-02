#include <stdio.h>

int main()
{
     int n, x, y;

     scanf("%d %d %d", &n, &x, &y);

     if ((x == n / 2 || x - 1 == n / 2) && (y == n / 2 || y - 1 == n / 2)) {
	  puts("NO");
     } else {
	  puts("YES");
     }

     return 0;
}