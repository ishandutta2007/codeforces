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

const int N = 200005;
const int mod = 1000000007;
int n;
vi g[N];
int dp[N];

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return ans;
}

void dfs(int u) {
	dp[u] = 1;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		dfs(v);
		dp[u] = 1ll * dp[u] * (dp[v] + 1) % mod;
	}
}

int ans[N];

void go(int u, int s) {
	int mul = 1;
	vi pr, sf;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		mul = 1ll * mul * (dp[v] + 1) % mod;
		pr.pb(mul);
	}
	mul = 1;
	for (int i = sz(g[u]) - 1; i >= 0; i--) {
		int v = g[u][i];
		mul = 1ll * mul * (dp[v] + 1) % mod;
		sf.pb(mul);
	}
	reverse(sf.begin(), sf.end());
	ans[u] = 1ll * mul * s % mod;
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		int tmp = s;
		if (i - 1 >= 0) tmp = 1ll * tmp * pr[i - 1] % mod;
		if (i + 1 < sz(g[u])) tmp = 1ll * tmp * sf[i + 1] % mod;
		go(v, (tmp + 1) % mod);
	}
}

int main() {
	scanf("%d", &n);
	int p;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p);
		g[p].pb(i);
	}
	dfs(1);
	go(1, 1);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}