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
     int n, m, c0, d0, max = 0, i, j, k;
     int a[10], b[10], c[10], d[10];
     int dp[1005] = {0};

     scanf("%d %d %d %d", &n, &m, &c0, &d0);

     for (i = 0; i < m; i++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

     for (i = 0; i < m; i++) {
	  for (j = n; j > 0; j--) {
	       if (dp[j] > 0) {
		    for (k = min((n - j) / c[i], a[i] / b[i]); k > 0; k--) {
			 if (j + k * c[i] > n) continue;

			 if (dp[j + k * c[i]] < dp[j] + d[i] * k) {
			      dp[j + k * c[i]] = dp[j] + d[i] * k;
			 }
		    }
	       }
	  }

	  for (k = min(n / c[i], a[i] / b[i]); k > 0; k--) {
	       if (k * c[i] > n) continue;

	       if (dp[k * c[i]] < d[i] * k) {
		    dp[k * c[i]] = d[i] * k;
	       }
	  }
     }

     for (j = n; j > 0; j--) {
	  if (dp[j] > 0) {
	       for (k = (n - j) / c0; k > 0; k--) {
		    if (j + k * c0 > n) continue;

		    if (dp[j + k * c0] < dp[j] + d0 * k) {
			 dp[j + k * c0] = dp[j] + d0 * k;
		    }
	       }
	  }
     }

     for (k = (n - j) / c0; k > 0; k--) {
	  if (k * c0 > n) continue;

	  if (dp[k * c0] < d0 * k) {
	       dp[k * c0] = d0 * k;
	  }
     }

     for (i = 0; i <= n; i++) {
	  if (dp[i] > max) max = dp[i];
     }

     printf("%d\n", max);

     return 0;
}