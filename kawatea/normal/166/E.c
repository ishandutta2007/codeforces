#include <stdio.h>

int main()
{
     int n, m = 1000000007, i, j, k;
     long long dp[4][2] = {0};

     scanf("%d", &n);

     dp[0][0] = 1;

     for (i = 0; i < n; i++) {
	  for (j = 0; j < 4; j++) {
	       for (k = 0; k < 4; k++) {
		    if (j == k) continue;

		    dp[j][1] += dp[k][0];
	       }
	  }

	  for (j = 0; j < 4; j++) {
	       dp[j][0] = dp[j][1] % m;
	       dp[j][1] = 0;
	  }
     }

     printf("%d\n", (int)dp[0][0]);

     return 0;
}