#include <stdio.h>

int diff(int a, int b)
{
     int c = 0, i;

     for (i = 0; i < 4; i++) {
	  if (a % 10 != b % 10) c++;

	  a /= 10; b/= 10;
     }

     return c;
}

int main()
{
     int n, i, j;
     int a[1001] = {1000};

     scanf("%d", &n);

     for (i = 1; i <= n; i++) scanf("%d", &a[i]);

     for (i = 1; i <= n; i++) {
	  for (j = a[i - 1]; j <= 2011; j++) {
	       if (diff(a[i], j) <= 1) {
		    a[i] = j;

		    break;
	       }
	  }

	  if (j > 2011) {
	       puts("No solution");

	       return 0;
	  }
     }

     for (i = 1; i <= n; i++) printf("%d\n", a[i]);

     return 0;
}