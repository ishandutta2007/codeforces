#include <stdio.h>

int main()
{
     int n, b, max = 0, i, j;
     int a[2000];

     scanf("%d %d", &n, &b);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) {
	  int p = a[i], m;

	  for (j = i + 1; j < n; j++) {
	       if (a[j] > p) p = a[j];
	  }

	  m = b % a[i] + b / a[i] * p;

	  if (m > max) max = m;
     }

     printf("%d\n", max);

     return 0;
}