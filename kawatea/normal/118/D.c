#include <stdio.h>

int max(int a, int b)
{
    if (a > b) {
	return a;
    } else {
	return b;
    }
}

int main()
{
    int n1, n2, k1, k2, m = 100000000, i, j, k, l;
    long long sum = 0;
    long long dp[300][300][2][15] = {0};

    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);

    dp[1][0][0][0] = dp[0][1][1][0] = 1;

    for (i = 1; i < n1 + n2; i++) {
	for (j = 0; j <= i; j++) {
	    for (k = 0; k < 2; k++) {
		for (l = 0; l < max(k1, k2); l++) {
		    if (k == 0 && l + 1 < k1) {
			dp[j + 1][i - j][k][l + 1] += dp[j][i - j][k][l];
			dp[j + 1][i - j][k][l + 1] %= m;
		    }

		    if (k == 1 && l + 1 < k2) {
			dp[j][i - j + 1][k][l + 1] += dp[j][i - j][k][l];
			dp[j][i - j + 1][k][l + 1] %= m;
		    }

		    if (k == 0) {
			dp[j][i - j + 1][(k + 1) % 2][0] += dp[j][i - j][k][l];
			dp[j][i - j + 1][(k + 1) % 2][0] %= m;
		    }

		    if (k == 1) {
			dp[j + 1][i - j][(k + 1) % 2][0] += dp[j][i - j][k][l];
			dp[j + 1][i - j][(k + 1) % 2][0] %= m;
		    }
		}
	    }
	}
    }

    for (i = 0; i < 2; i++) {
	for (j = 0; j < 15; j++) {
	    sum += dp[n1][n2][i][j];
	    sum %= m;
	}
    }

    printf("%d\n", (int)sum);

    return 0;
}