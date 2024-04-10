#include <stdio.h>

int main()
{
     int n, c, i, j;

     scanf("%d", &n);

     c = n / 2;

     printf("%d\n", c * (n - c));

     for (i = 0; i < c; i++) {
	  for (j = c; j < n; j++) {
	       printf("%d %d\n", i + 1, j + 1);
	  }
     }

     return 0;
}