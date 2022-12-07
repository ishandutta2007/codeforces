#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n, a[N], sum[N];
int dp[N][90 * 2][90][2];

int dfs(int l, int r, int k, int f) {
	int &ans = dp[l][r][k][f];
	if (ans != -1) return ans;
	int rr = l + r - (f ? k : 0);
	int tot = l + rr;
	int L = l, R = n - rr;
	if (f) {
		ans = INF;
		if (tot + k <= n) ans = min(ans, dfs(l, r, k, f^1) - (sum[R] - sum[R - k]));
		if (tot + k + 1 <= n) ans = min(ans, dfs(l, r + 1, k + 1, f^1) - (sum[R] - sum[R - k - 1]));
		if (ans == INF) ans = 0;
	} else {
		ans = -INF;
		if (tot + k <= n) ans = max(ans, dfs(l + k, r, k, f^1) + sum[L + k] - sum[L]);
		if (tot + k + 1 <= n) ans = max(ans, dfs(l + k + 1, r, k + 1, f ^1) + sum[L + k + 1] - sum[L]);
		if (ans == -INF) ans = 0;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(0, 0, 1, 0));
	return 0;
}