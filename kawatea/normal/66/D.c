#include <stdio.h>

int main()
{
     int n, i;
     long long a[50];

     scanf("%d", &n);

     if (n == 2) {
	  puts("-1");
     } else {
	  long long x = 1;

	  for (i = 0; i < n; i++) {
	       a[i] = x;

	       x *= 2;
	  }

	  for (i = 0; i < n - 1; i++) {
	       a[i] *= 3;
	  }

	  a[0] *= 5;
	  a[n - 1] *= 5;

	  for (i = 0; i < n; i++) printf("%I64d\n", a[i]);
     }

     return 0;
}