#include <stdio.h>

int main()
{
     int n, p = 0, q = 0, i, j;
     int a[50][50] = {0};

     scanf("%d", &n);

     for (i = 0; i < n * (n - 1) / 2 - 1; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  a[x - 1][y - 1] = 1;
	  a[y - 1][x - 1] = -1;
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       if (i == j) continue;

	       if (a[i][j] == 0) {
		    p = i; q = j;

		    break;
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  if (i == p || i == q) continue;

	  if (a[p][i] * a[q][i] == -1) {
	       if (a[p][i] == 1) {
		    printf("%d %d\n", p + 1, q + 1);
	       } else {
		    printf("%d %d\n", q + 1, p + 1);
	       }

	       return 0;
	  }
     }

     printf("%d %d\n", p + 1, q + 1);

     return 0;
}