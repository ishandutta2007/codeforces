#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int a[500][500], b[500][501], c[500][501];
int dp[500][500][250];

int main()
{
     int n, m, sum = -1e9, i, j, k;

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       scanf("%d", &a[i][j]);
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       b[i][j + 1] = b[i][j] + a[i][j];
	  }
     }

     for (i = 0; i < m; i++) {
	  for (j = 0; j < n; j++) {
	       c[i][j + 1] = c[i][j] + a[j][i];
	  }
     }

     for (i = 2; i < n; i += 2) {
	  int s = 0;

	  for (j = 0; j <= i; j++) s += b[j][i + 1] - b[j][0];

	  dp[0][0][i / 2] = s;
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       for (k = 2; i + k < n && j + k < m; k += 2) {
		    if (i == 0 && j == 0) break;

		    if (j == 0) {
			 dp[i][j][k / 2] = dp[i - 1][j][k / 2] + b[i + k][j + k + 1] - b[i + k][j] - b[i - 1][j + k + 1] + b[i - 1][j];
		    } else {
			 dp[i][j][k / 2] = dp[i][j - 1][k / 2] + c[j + k][i + k + 1] - c[j + k][i] - c[j - 1][i + k + 1] + c[j - 1][i];
		    }
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       dp[i][j][0] = a[i][j];
	  }
     }

     for (i = 2; i < 500; i += 2) {
	  for (j = 0; i + j < n; j++) {
	       for (k = 0; i + k < m; k++) {
		    dp[j][k][i / 2] -= dp[j + 1][k + 1][i / 2 - 1] + a[j + 1][k];

		    sum = max(sum, dp[j][k][i / 2]);
	       }
	  }
     }

     printf("%d\n", sum);

     return 0;
}