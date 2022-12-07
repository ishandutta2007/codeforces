#include <cstdio>
#include <cstring>

const int MOD = 1e9 + 7;

typedef long long ll;
const int N = 100005;

int t, k, a, b;
int dp[N];

int main() {
	dp[0] = 1;
	scanf("%d%d", &t, &k);
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1];
		if (i >= k) dp[i] = (dp[i] + dp[i - k]) % MOD;
	}
	for (int i = 1; i < N; i++)
		dp[i] = (dp[i] + dp[i - 1]) % MOD;
	int m;
	while (t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", ((dp[b] - dp[a - 1]) % MOD + MOD) % MOD);
	}
	return 0;
}