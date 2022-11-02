#include <stdio.h>

int main()
{
     int n, i;

     scanf("%d", &n);

     for (i = 0; i <= n / 4; i++) {
	  if ((n - 4 * i) % 3 == 0) {
	       int x = (n - 4 * i) / 3;
	       int y = i - x;

	       if (y >= 0) break;
	  }
     }

     if (i > n / 4) {
	  puts("-1");
     } else {
	  int x = (n - 4 * i) / 3;
	  int y = i - x;

	  for (i = 0; i < y; i++) putchar('4');
	  for (i = 0; i < x; i++) putchar('7');
	  puts("");
     }

     return 0;
}