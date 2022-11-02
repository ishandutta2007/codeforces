#include <stdio.h>

int main()
{
     int t, n, i;
 
     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  scanf("%d", &n);

	  n -= 2;

	  if (n < 0) n = 0;

	  printf("%d\n", n);
     }

     return 0;
}