#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int t;
    int d;
} call;

int cmp(const void *a, const void *b)
{
    if (((call *)a)->t != ((call *)b)->t) {
	return ((call *)a)->t - ((call *)b)->t;
    } else {
	return ((call *)a)->d - ((call *)b)->d;
    }
}

int max(int a, int b)
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

int main()
{
    int n, k, ans = 0, i, j;
    call c[4000];
    int dp[4001][2];

    scanf("%d %d", &n, &k);

    k = n - k;

    for (i = 0; i < n; i++) scanf("%d %d", &c[i].t, &c[i].d);

    qsort(c, n, sizeof(call), cmp);

    for (i = 0; i <= k; i++) {
	dp[i][0] = -1;
	dp[i][1] = 1e9;
    }

    dp[0][0] = dp[0][1] = 0;

    for (i = 0; i < n; i++) {
	for (j = k - 1; j >= 0; j--) {
	    int x = 0;

	    if (dp[j][0] == -1) continue;

	    if (c[i].t > dp[j][1]) x = c[i].t - dp[j][1] - 1;

	    dp[j + 1][0] = max(dp[j + 1][0], x);

	    dp[j + 1][0] = max(dp[j + 1][0], dp[j][0]);

	    if (c[i].t > dp[j][1]) {
		dp[j + 1][1] = min(dp[j + 1][1], c[i].t + c[i].d - 1);
	    } else {
		dp[j + 1][1] = min(dp[j + 1][1], dp[j][1] + c[i].d);
	    }
	}
    }

    ans = max(ans, dp[k][0]);
    ans = max(ans, 86400 - dp[k][1]);

    printf("%d\n", ans);

    return 0;
}