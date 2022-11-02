#include <stdio.h>

int main()
{
     int x, i;
     long long n = 0;

     scanf("%d", &x);

     if (x < 0) x *= -1;

     for (i = 0; ; i++) {
	  n += i;

	  if ((n == x) || (n > x && (n - x) % 2 == 0)) {
	       printf("%d\n", i);

	       return 0;
	  }
     }

     return 0;
}