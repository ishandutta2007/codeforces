#include <stdio.h>

int main()
{
     int n, i, j, k;
     int a[300][300];
     int p[300];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       scanf("%d", &a[i][j]);
	  }
     }

     for (i = 0; i < n; i++) scanf("%d", &p[i]);

     for (i = 0; i < n; i++) {
	  int x = -1;

	  for (j = 0; j < n; j++) {
	       if (a[i][j] == i + 1) continue;

	       for (k = 0; k < n; k++) {
		    if (p[k] == i + 1) continue;

		    if (p[k] < a[i][j]) break;

		    if (p[k] == a[i][j]) {
			 x = a[i][j];

			 break;
		    }
	       }

	       if (x != -1) break;
	  }

	  if (i > 0) putchar(' ');

	  printf("%d", x);
     }

     return 0;
}