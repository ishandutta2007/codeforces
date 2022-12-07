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

const int N = 500005;
int n, q, a[N], vis[N];
vi pri[N], fac[N], f[N];
int dp[N];

int get(int x) {
	int ans = 0;
	for (int i = 0; i < sz(fac[x]); i++)
		ans += dp[fac[x][i]] * f[x][i];
	return ans;
}

void dfs(int u, int mul, int F, int i) {
	if (u == sz(pri[i])) {
		fac[i].pb(mul);
		f[i].pb(F);
		return;
	}
	dfs(u + 1, mul * pri[i][u], -F, i);
	dfs(u + 1, mul, F, i);
}

int main() {
	for (int i = 2; i < N; i++) {
		if (vis[i]) continue;
		for (int j = i; j < N; j += i) {
			pri[j].pb(i);
			vis[j] = 1;
		}
	}
	for (int i = 1; i < N; i++)
		dfs(0, 1, 1, i);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int x;
	ll ans = 0;
	memset(vis, 0, sizeof(vis));
	while (q--) {
		scanf("%d", &x);
		if (!vis[x]) {
			ans += get(a[x]);
			for (int i = 0; i < sz(fac[a[x]]); i++) dp[fac[a[x]][i]]++;
		} else {
			for (int i = 0; i < sz(fac[a[x]]); i++) dp[fac[a[x]][i]]--;
			ans -= get(a[x]);
		}
		vis[x] ^= 1;
		printf("%lld\n", ans);
	}
	return 0;
}