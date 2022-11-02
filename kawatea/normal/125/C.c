#include <stdio.h>

int main()
{
     int n, k, c = 1, i, j;
     int a[150][150], p[150] = {0};

     scanf("%d", &n);

     for (i = 3; i <= n; i++) {
	  if (i * (i - 1) > 2 * n) break;
     }

     k = i - 1;

     for (i = 0; i < k; i++) {
	  for (j = i + 1; j < k; j++) {
	       a[i][p[i]++] = c;
	       a[j][p[j]++] = c++;
	  }
     }

     printf("%d\n", k);

     for (i = 0; i < k; i++) {
	  for (j = 0; j < p[j]; j++) {
	       if (j > 0) putchar(' ');

	       printf("%d", a[i][j]);
	  }
	  puts("");
     }

     return 0;
}