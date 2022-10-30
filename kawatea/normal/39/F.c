#include <stdio.h>

int main()
{
     int n, m, k, min = 1e9, p = 0, i, j;
     int a[100], b[100], c[100];

     scanf("%d %d %d", &n, &m, &k);

     for (i = 0; i < m; i++) scanf("%d", &a[i]);
     for (i = 0; i < k; i++) scanf("%d", &b[i]);

     for (i = 0; i < m; i++) {
	  int x = 0;

	  for (j = 0; j < k; j++) {
	       if (b[j] % a[i] == 0) x++;
	  }

	  if (x < min) {
	       min = x;
	       p = 0;
	       c[p++] = i + 1;
	  } else if (x == min) {
	       c[p++] = i + 1;
	  }
     }

     printf("%d\n", p);

     for (i = 0; i < p; i++) {
	  if (i > 0) putchar(' ');
	  printf("%d", c[i]);
     }

     puts("");

     return 0;
}