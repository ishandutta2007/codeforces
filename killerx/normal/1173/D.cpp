#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
#define pb push_back
#define mp make_pair
using ll = long long;
using vi = vector <int>;
using pii = pair <int, int>;
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (auto it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int qp(int x, int n) {return !n ? 1 : 1LL * qp(1LL * x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod;}
int inv(int x) {return qp(x, mod - 2);}
int fac[200005], invfac[200005];
vector <int> g[200005], son[200005];
int dp[200005];
vector <int> dp1[200005];
void dfs(int u, int p) {
	dp[u] = 1;
	rep(i, g[u].size()) {
		int v = g[u][i];
		if (v != p) {
			dfs(v, u);
			son[u].pb(v);
			dp[u] = 1LL * dp[u] * dp[v] % mod;
		}
	}
	dp[u] = 1LL * dp[u] * fac[son[u].size() + 1] % mod;
}
int ans;
void dfs1(int u, int p, int sonid) {
	rep(i, son[u].size()) {
		int v = son[u][i];
		dp1[u].pb(1LL * dp[u] * invfac[son[u].size() + 1] % mod * fac[son[u].size() + (~p ? 1 : 0)] % mod * inv(dp[v]) % mod);
		if (~p) dp1[u].back() = 1LL * dp1[u].back() * dp1[p][sonid] % mod;
		dfs1(v, u, i);
	}
	ans = (ans + (1LL * dp[u] * invfac[son[u].size() + 1] % mod * fac[son[u].size() + (~p ? 1 : 0)] % mod * (~p ? dp1[p][sonid] : 1))) % mod;
}
int main() {
	int n = read();
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		invfac[i] = inv(fac[i]);
	}
	rep(i, n - 1) {
		int u = read() - 1;
		int v = read() - 1;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, -1);
	dfs1(0, -1, -1);
	printf("%d\n", ans);
	return 0;
}