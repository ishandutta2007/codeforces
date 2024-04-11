#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 5;
int dp[125][125][300], n, m;
vector<vpi> g;
int dfs(int v, int u, int p) {
	if(dp[v][u][p]!=-1) return dp[v][u][p];
	dp[v][u][p] = 0;
	for(auto i : g[v]) {
		if(i.second<p) continue;
		dp[v][u][p] = max(dp[v][u][p], 1 ^ dfs(u, i.first, i.second));
	}

	return dp[v][u][p];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	char c;
	g.resize(n+1);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t>> c;
		g[f].pb({t, c});
	}
	for(int i = 1; i <= n; i++, cout << '\n')
		for(int j = 1; j <= n; j++) {
			cout << (dfs(i, j, 0)?'A':'B');
		}
}