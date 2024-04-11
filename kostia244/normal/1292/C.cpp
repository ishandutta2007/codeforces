#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<vi> g;
void read() {
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
}
ll dp[3030][3030], p[3030][3030], sz[3030][3030];
void dfs(int v, int pr, int c) {
	p[c][v] = pr;
	sz[c][v] = 1;
	for(auto i : g[v]) {
		if(i==pr) continue;
		dfs(i, v, c);
		sz[c][v] += sz[c][i];
	}
}
ll f(int l, int r) {
	if(l==r) {
		return 0;
	}
	if(dp[l][r]!=-1) return dp[l][r];
	ll a, b;
	a = f(l, p[l][r]) + sz[l][r]*sz[r][l];
	b = f(p[r][l], r) + sz[l][r]*sz[r][l];
	dp[l][r] = max(a, b);
//	cout << l << " " << r << " " << dp[l][r] << "\n";
 	return dp[l][r];
}
ll solve() {
	memset(dp, -1, sizeof dp);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		dfs(i, i, i);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans = max(ans, f(i, j));
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	cout << solve();
}