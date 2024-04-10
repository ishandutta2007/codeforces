#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, p, k, pos[N], a[N], cnt[1 << 7], s[N][8];
ll dp[N][1 << 7];
bool cmp(int a, int b) {
	return ::a[a] > ::a[b];
}
int main() {
	scanf("%d%d%d", &n, &p, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i < (1 << p); i ++) cnt[i] = cnt[i & (i - 1)] + 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= p; j ++)
			scanf("%d", &s[i][j]);
	for(int i = 1; i <= n; i ++) pos[i] = i;
	sort(pos + 1, pos + n + 1, cmp);
	memset(dp[0], -1, sizeof dp[0]);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i ++) {
		memset(dp[i], -1, sizeof dp[i]);
		for(int u = 0; u < (1 << p); u ++) if(~ dp[i - 1][u]) {
			for(int v = 0; v < p; v ++) if(!(u >> v & 1)) {
				dp[i][u ^ (1 << v)] = max(dp[i][u ^ (1 << v)], dp[i - 1][u] + s[pos[i]][v + 1]);
			}
			dp[i][u] = max(dp[i][u], dp[i - 1][u] + (i - 1 - cnt[u] < k ? a[pos[i]] : 0));
		}
	}
	printf("%lld\n", dp[n][(1 << p) - 1]);
	return 0;
}