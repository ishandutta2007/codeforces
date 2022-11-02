#include <stdio.h>

int main()
{
     int n, k, i, j, l;
     int a[1000], b[1000];
     int c[1000] = {0};

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d", &b[i]);

     for (i = 0; i < n; i++) {
	  if (b[i] == 0) {
	       a[0] = i + 1;

	       c[i] = 1;

	       break;
	  }
     }

     for (i = 1; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       if (c[j] == 0 && b[j] <= i) {
		    int p = b[j];
		    for (l = 0; l < i; l++) {
			 if (a[l] >= j + k + 1) p--;
		    }

		    if (p <= 0) {
			 a[i] = j + 1;

			 c[j] = 1;

			 break;
		    }
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  printf("%d", a[i]);

	  if (i < n - 1) putchar(' ');
     }

     putchar('\n');

     return 0;
}