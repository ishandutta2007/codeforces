#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

const int MOD = 1000000007;

const int N = 5005;
int n, a, b, k;

int dp[2][N];
int now = 0, pre = 1;
int main() {
	scanf("%d%d%d%d", &n, &a, &b, &k);
	memset(dp[now], 0, sizeof(dp[now]));
	dp[now][a] = 1;
	for (int s = 1; s <= k; s++) {
		swap(now, pre);
		memset(dp[now], 0, sizeof(dp[now]));
		for (int i = 1; i <= n; i++) {
			if (i == b) continue;
			int l, r;
			if (i < b) {
				l = max(1, i - (b - i - 1));
				r = b - 1;
			} else {
				l = b + 1;
				r = min(n, i + (i - b - 1));
			}
			dp[now][l] = (dp[now][l] + dp[pre][i]) % MOD;
			dp[now][r + 1] = (dp[now][r + 1] - dp[pre][i] + MOD) % MOD;
		}
		for (int i = 1; i <= n; i++)
			dp[now][i] = (dp[now][i] + dp[now][i - 1]) % MOD;
		for (int i = 1; i <= n; i++)
			dp[now][i] = (dp[now][i] - dp[pre][i] + MOD) % MOD;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp[now][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}