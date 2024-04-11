#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
const int maxn = 1e6 + 3;
#define left bsalkfjdasld
int n;
vector<vi> g;
vi dp[3], fr;
void dfs(int v, int p) {//0 - unused, covered, 1 - used, covered, 2 - unused, uncovered but children are
	dp[1][v] = p!=1;
	int t = (1<<30), fl = 0;
	for(auto i : g[v]) {
		if(i == p) continue;
		dfs(i, v);
		if(dp[1][i] <= dp[0][i]) {
			dp[0][v] += dp[1][i];
			fl = 1;
		} else {
			dp[0][v] += dp[0][i];
			t = min(t, -dp[0][i] + dp[1][i]);
		}
		dp[1][v] += min({dp[0][i], dp[1][i], dp[2][i]});
		dp[2][v] += min(dp[0][i], dp[1][i]);
	}
	if(!fl) dp[0][v] += t;
}
void solve() {
	cin >> n;
	g.assign(n+1, {});
	dp[0].assign(n+1, 0);
	dp[1].assign(n+1, 0);
	dp[2].assign(n+1, 0);
	fr.assign(n+1, 0);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1, 1);
	cout << min({dp[1][1], dp[0][1], dp[2][1]}) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while(t--) solve();
}