#include <stdio.h>

int main()
{
     int n, d, sum = 0, i;
     int a[2001] = {0};

     scanf("%d %d", &n, &d);

     for (i = 1; i <= n; i++) scanf("%d", &a[i]);

     for (i = 1; i <= n; i++) {
	  if (a[i] <= a[i - 1]) {
	       int x = a[i - 1] - a[i];

	       a[i] += (x / d + 1) * d;
	       sum += x / d + 1;
	  }
     }

     printf("%d\n", sum);

     return 0;
}