#include <stdio.h>

int main()
{
     int n, m, i, j, k;
     int a[100], b[100][100];
     int max[100][101];
     int dp[10001] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  for (j = 0; j < a[i]; j++) {
	       scanf("%d", &b[i][j]);
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j <= a[i]; j++) {
	       int tmp = 0;

	       for (k = 0; k < j; k++) {
		    tmp += b[i][k];
	       }

	       max[i][j] = tmp;

	       for (k = j - 1; k >= 0; k--) {
		    tmp -= b[i][k];

		    tmp += b[i][a[i] - j + k];

		    if (tmp > max[i][j]) max[i][j] = tmp;
	       }
	  }
     }

     dp[0] = 1;

     for (i = 0; i < n; i++) {
	  for (j = m; j >= 0; j--) {
	       for (k = 1; k <= a[i] && j + k <= m; k++) {
		    if (dp[j] == 0) continue;

		    if (dp[j] + max[i][k] > dp[j + k]) dp[j + k] = dp[j] + max[i][k];
	       }
	  }
     }

     printf("%d\n", dp[m] - 1);

     return 0;
}