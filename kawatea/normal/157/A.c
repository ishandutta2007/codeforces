#include <stdio.h>

int main()
{
     int n, c = 0, i, j, k;
     int a[30][30];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       scanf("%d", &a[i][j]);
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       int x = 0, y = 0;

	       for (k = 0; k < n; k++) x += a[i][k];

	       for (k = 0; k < n; k++) y += a[k][j];

	       if (x < y) c++;
	  }
     }

     printf("%d\n", c);

     return 0;
}