#include <stdio.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, x = 0, y = 0, f, p = 0, q = 0, i, j;
     int a, b, c;
     int d[100][100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       d[i][j] = 10000;
	  }
     }

     for (i = 0; i < n; i++) {
	  scanf("%d %d %d", &a, &b, &c);

	  d[a - 1][b - 1] = 0;
	  d[b - 1][a - 1] = c;
     }

     while (1) {
	  for (i = 0; i < n; i++) {
	       if (i == y) continue;

	       if (d[x][i] < 10000) break;
	  }

	  p += d[x][i];

	  y = x; x = i;

	  if (x == 0) break;
     }

     i = x; x = y; y = i;
     f = x;

     while (1) {
	  for (i = 0; i < n; i++) {
	       if (i == y) continue;

	       if (d[x][i] < 10000) break;
	  }

	  q += d[x][i];

	  y = x; x = i;

	  if (x == f) break;
     }

     printf("%d\n", min(p, q));

     return 0;
}