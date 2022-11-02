#include <stdio.h>

int main()
{
     int n, i;

     scanf("%d", &n);

     printf("%d ", n);

     for (i = 2; i <= n; i++) {
	  if (n % i == 0) {
	       n /= i;

	       i--;

	       printf("%d", n);

	       if (n != 1) putchar(' ');
	  }
     }

     return 0;
}