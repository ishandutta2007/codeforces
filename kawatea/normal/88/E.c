#include <stdio.h>

int g[100001], dp[100001];
int a[50001][1000];

int main()
{
     int n, i, j;

     scanf("%d", &n);

     for (i = 0; i <= n; i++) dp[i] = -1;

     for (i = 2; i <= (n + 1) / 2; i++) {
	  int sum = i, f;

	  for (j = 0; j < 1000; j++) {
	       if (a[i][j] == 0) break;
	  }

	  g[i] = f = j;

	  for (j = i - 1; j > 0; j--) {
	       sum += j;

	       f ^= g[j];

	       if (sum > n) break;

	       if (f < 1000 && sum <= (n + 1) / 2) a[sum][f] = 1;

	       if (f == 0) dp[sum] = i - j + 1;
	  }
     }

     printf("%d\n", dp[n]);

     return 0;
}