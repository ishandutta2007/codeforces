#include <stdio.h>

int main()
{
     int n, max = 0, i, j;
     int a[1000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) {
	  int c = a[i];
	  int x = 1;

	  for (j = i - 1; j >= 0; j--) {
	       if (a[j] > c) break;

	       c = a[j];
	  }

	  x += i - j - 1;

	  c = a[i];

	  for (j = i + 1; j < n; j++) {
	       if (a[j] > c) break;

	       c = a[j];
	  }

	  x += j - i - 1;

	  if (x > max) max = x;
     }

     printf("%d\n", max);

     return 0;
}