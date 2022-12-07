#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 222222;
const int mod = 1e9+7;

int a, b, k, t;
int w[105], wn;
int dp[2][N], sum[N];

void build(int *dp, int a) {
	dp[a] = 1;
	for (int j = 1; j <= a + k; j++) sum[j] = (sum[j - 1] + dp[j]) % mod;
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= a + k * i; j++) {
			dp[j] = sum[j];
			if (j - k - 1 >= 0) dp[j] = (dp[j] - sum[j - k - 1] + mod) % mod;
		}
		for (int j = 1; j <= a + k * (i + 1); j++) sum[j] = (sum[j - 1] + dp[j]) % mod;
	}
}

int main() {
	scanf("%d%d%d%d", &a, &b, &k, &t);
	k *= 2;
	build(dp[0], a); build(dp[1], b);
	for (int i = 1; i < N; i++) dp[1][i] = (dp[1][i] + dp[1][i - 1]) % mod;
	int ans = 0;
	for (int i = 1; i < N; i++) ans = (ans + 1ll * dp[0][i] * dp[1][i - 1] % mod) % mod;
	printf("%d\n", ans);
	return 0;
}