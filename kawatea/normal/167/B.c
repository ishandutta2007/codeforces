#include <stdio.h>

double max(double a, double b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

double dp[201][201][401];

int main()
{
     int n, l, K, i, j, k;
     double ans = 0;
     int a[200];
     double p[200];

     scanf("%d %d %d", &n, &l, &K);

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%d", &x);

	  p[i] = x / 100.0;
     }

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     dp[0][0][200 + K] = 1;

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       for (k = 0; k <= 400; k++) {
		    dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i]);

		    dp[i + 1][j + 1][min(k + a[i], 400)] += dp[i][j][k] * p[i];
	       }
	  }
     }

     for (i = l; i <= n; i++) {
	  for (j = 200; j <= 400; j++) {
	       ans += dp[n][i][j];
	  }
     }

     printf("%.10lf\n", ans);

     return 0;
}