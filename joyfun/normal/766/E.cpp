#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 100005;
int n, aa[N], a[N], dp[N][2];
ll cnt;
vi g[N];

void dfs(int u, int p) {
	dp[u][0] = dp[u][1] = 0;
	int sb = a[u];
	a[u] ^= a[p];
	dp[u][a[u]]++;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		cnt += 1ll * dp[u][1] * dp[v][sb] + 1ll * dp[u][0] * dp[v][sb^1];
		dp[u][0] += dp[v][0];
		dp[u][1] += dp[v][1];
	}
	cnt += sb;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &aa[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= n; j++) a[j] = aa[j]>>i&1;
		cnt = 0;
		dfs(1, 0);
		ans += cnt * (1<<i);
	}
	printf("%lld\n", ans);
	return 0;
}