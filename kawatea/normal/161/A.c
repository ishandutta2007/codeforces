#include <stdio.h>

int main()
{
     int n, m, x, y, k = 0, i, j = 0;
     int a[100000], b[100000], c[100000];

     scanf("%d %d %d %d", &n, &m, &x, &y);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < m; i++) scanf("%d", &b[i]);

     for (i = 0; i < n; i++) c[i] = -1;

     for (i = 0; i < n; i++) {
	  for (; j < m; j++) {
	       if (a[i] - x <= b[j] && a[i] + y >= b[j]) {
		    c[i] = ++j;

		    k++;

		    break;
	       } else if (a[i] + y < b[j]) {
		    break;
	       }
	  }
     }

     printf("%d\n", k);

     for (i = 0; i < n; i++) {
	  if (c[i] != -1) printf("%d %d\n", i + 1, c[i]);
     }

     return 0;
}