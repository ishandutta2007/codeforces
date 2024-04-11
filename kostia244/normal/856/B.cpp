#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, maxa = 1e7 + 333, mod = 1e9 + 7, i2 = (mod+1)/2;
int to[maxn][26], sz = 0;
void nn() {
	memset(to[sz], 0, sizeof to[sz]);
	sz++;
}
void add(string a) {
	int cur = 0;
	for(auto i : a) {
		i -= 'a';
		if(!to[cur][i]) to[cur][i] = sz, nn();
		cur = to[cur][i];
	}
}
vector<vector<int>> g;
void mark(string a) {
	int x = 0, y = to[0][a[0]-'a'];
	for(int i = 1; i < a.size(); i++) {
		x = to[x][a[i]-'a'];
		y = to[y][a[i]-'a'];
		if(x == 0) break;
		if(x && y) {
			g[x].pb(y);
			g[y].pb(x);
		}
	}
}
vector<int> vis;

int dp[maxn][2];
void dfs(int v, int p) {
	vis[v]  = 1;
	dp[v][0] = 0;
	dp[v][1] = 1;
	for(auto i : g[v]) if(!vis[i]) {
		dfs(i, v);
		dp[v][0] += max(dp[i][0], dp[i][1]);
		dp[v][1] += dp[i][0];
	}
	//cout << v << " " << dp[v][0] << " " << dp[v][1] << '\n';
}
void solve() {
	int n;
	cin >> n;
	sz = 0;
	nn();
	vector<string> s(n);
	for(auto &t : s)
		cin >> t,
		add(t);
	vis.assign(sz, 0);
	g.assign(sz, {});
	int ans = 0;
	for(auto &t : s) mark(t);
	for(int i = 1; i < sz; i++) if(!vis[i]) {
		dfs(i, i);
		ans += max(dp[i][0], dp[i][1]);
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}