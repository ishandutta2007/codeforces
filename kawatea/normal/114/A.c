#include <stdio.h>

int main()
{
     int k, l, n = 0;

     scanf("%d %d", &k, &l);

     while (l > 1) {
	  if (l % k != 0) {
	       puts("NO");

	       return 0;
	  }

	  l /= k;

	  n++;
     }

     puts("YES");

     printf("%d\n", n - 1);

     return 0;
}