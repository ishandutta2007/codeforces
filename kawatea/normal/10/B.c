#include <stdio.h>
#include <stdlib.h>

int main()
{
     int N, K, i, j, k, l;
     int a[100][100] = {0};

     scanf("%d %d", &N, &K);

     for (i = 0; i < N; i++) {
	  int m, min = 1e9, x = 0, yl = 0, yr = 0;

	  scanf("%d", &m);

	  for (j = 1; j <= K; j++) {
	       for (k = 1; k + m <= K + 1; k++) {
		    for (l = k; l < k + m; l++) {
			 if (a[j][l] == 1) break;
		    }

		    if (l == k + m) {
			 int c = 0;

			 for (l = k; l < k + m; l++) {
			      c += abs(j - (K + 1) / 2) + abs(l - (K + 1) / 2);
			 }

			 if (c < min) {
			      min = c;
			      x = j; yl = k; yr = k + m - 1;
			 }
		    }
	       }
	  }

	  if (min == 1e9) {
	       puts("-1");
	  } else {
	       printf("%d %d %d\n", x, yl, yr);

	       for (j = yl; j <= yr; j++) a[x][j] = 1;
	  }
     }

     return 0;
}