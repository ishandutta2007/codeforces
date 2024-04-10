#include <stdio.h>

int main()
{
     int n, m, x;

     scanf("%d %d %d", &n, &m, &x);

     n -= 2 * (x - 1);
     m -= 2 * (x - 1);

     if (n <= 0 || m <= 0) {
	  puts("0");
     } else {
	  n += m - 2;

	  if (n == 0) n = 1;

	  printf("%d\n", n);
     }

     return 0;
}