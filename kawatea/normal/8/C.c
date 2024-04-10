#include <stdio.h>

int dp[1 << 24];
int p[1 << 24][3];

int dist(int x1, int y1, int x2, int y2)
{
     return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
     int x, y, n, i, j, k;
     int a[24], b[24], d[25][25];

     scanf("%d %d", &x, &y);
     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);

     for (i = 0; i < n; i++) {
	  for (j = i + 1; j < n; j++) {
	       d[i][j] = d[j][i] = dist(a[i], b[i], a[j], b[j]);
	  }

	  d[i][n] = d[n][i] = dist(x, y, a[i], b[i]);
     }

     for (i = 1; i < (1 << n); i++) dp[i] = 1e9;

     for (i = 0; i < (1 << n) - 1; i++) {
	  for (j = 0; j < n; j++) {
	       if (((i >> j) & 1) == 0) {
		    int c = i ^ (1 << j);

		    for (k = j + 1; k < n; k++) {
			 if (((i >> k) & 1) == 0) {
			      int c = i ^ (1 << j) ^ (1 << k);

			      if (dp[i] + d[j][k] + d[j][n] + d[k][n] < dp[c]) {
				   dp[c] = dp[i] + d[j][k] + d[j][n] + d[k][n];

				   p[c][0] = j + 1;
				   p[c][1] = k + 1;
				   p[c][2] = i;
			      }
			 }
		    }

		    if (dp[i] + d[j][n] * 2 < dp[c]) {
			 dp[c] = dp[i] + d[j][n] * 2;

			 p[c][0] = j + 1;
			 p[c][1] = -1;
			 p[c][2] = i;
		    }

		    break;
	       }
	  }
     }

     printf("%d\n", dp[(1 << n) - 1]);

     i = (1 << n) - 1;

     while (i > 0) {
	  if (p[i][1] == -1) {
	       printf("0 %d ", p[i][0]);
	  } else {
	       printf("0 %d %d ", p[i][0], p[i][1]);
	  }

	  i = p[i][2];
     }
     puts("0");

     return 0;
}