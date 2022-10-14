#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k, x;
vvi g;
ll dp[100100][11][3], tdp[100100][11][3];
void dfs(int v, int p) {
	dp[v][0][0] = k - 1;
	dp[v][1][1] = 1;
	dp[v][0][2] = m - k;
	for (auto i : g[v]) {
		if (i == p)
			continue;
		dfs(i, v);
		memset(tdp[v], 0, sizeof tdp[v]);
		for (int a = 0; a <= x; a++)
			for (int b = 0; a + b <= x; b++) {
				(tdp[v][a + b][0] += (dp[v][a][0] * dp[i][b][0]) % mod) %= mod;
				(tdp[v][a + b][0] += (dp[v][a][0] * dp[i][b][1]) % mod) %= mod;
				(tdp[v][a + b][0] += (dp[v][a][0] * dp[i][b][2]) % mod) %= mod;
				(tdp[v][a + b][1] += (dp[v][a][1] * dp[i][b][0]) % mod) %= mod;
				(tdp[v][a + b][2] += (dp[v][a][2] * dp[i][b][0]) % mod) %= mod;
				(tdp[v][a + b][2] += (dp[v][a][2] * dp[i][b][2]) % mod) %= mod;
			}
		swap(tdp[v], dp[v]);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	cin >> k >> x;
	dfs(1, 1);
	ll ans = 0;
	for (int i = 0; i <= x; i++) {
		ans = (ans + dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % mod;
	}
	cout << ans;
}