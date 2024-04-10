#include <stdio.h>

int main()
{
     int n, p, i;
     int a, b, d, t = 0;
     int c[1001][3] = {0};
     int m[1000][3];

     scanf("%d %d", &n, &p);

     for (i = 0; i < p; i++) {
	  scanf("%d %d %d", &a, &b, &d);

	  c[a][1] = b;
	  c[a][2] = d;
	  c[b][0] = a;
     }

     for (i = 1; i <= n; i++) {
	  if (c[i][0] == 0 && c[i][1] != 0) {
	       int max = 10000000, x = i;

	       while (c[x][1] != 0) {
		    if (c[x][2] < max) max = c[x][2];

		    x = c[x][1];
	       }

	       m[t][0] = i;
	       m[t][1] = x;
	       m[t++][2] = max;
	  }
     }

     printf("%d\n", t);
     for (i = 0; i < t; i++) printf("%d %d %d\n", m[i][0], m[i][1], m[i][2]);

     return 0;
}