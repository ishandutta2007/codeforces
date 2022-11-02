#include <stdio.h>

int main()
{
     int n, d, sum = 0, i, j;
     int a[1000];

     scanf("%d %d", &n, &d);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       if (i == j) continue;

	       if (a[i] - d <= a[j] && a[i] + d >= a[j]) sum++;
	  }
     }

     printf("%d\n", sum);

     return 0;
}