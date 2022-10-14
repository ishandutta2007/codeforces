#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
vector<vector<int>> g;
int n;
vector<int> vis, loop, trace;
void dfs(int v, int p) {
	trace.push_back(v);
	vis[v] = 2;
	for(auto &i : g[v]) if(!vis[i]) dfs(i, v); else if(i != p && vis[i] == 2) {
		int x = trace.size()-1;
		while(trace[x] != i) x--;
		for(; x < trace.size(); x++) loop[trace[x]] = 1;
	}
	vis[v] = 1;
	trace.pop_back();
}
ll fuck(int v) {
	vis[v] = 1;
	ll u = 1;
	for(auto &i : g[v]) if(!loop[i] && !vis[i]) u += fuck(i);
	return u;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--) {
		cin >> n;
		vis.assign(n+1, 0);
		loop.assign(n+1, 0);
		g.assign(n+1, {});
		for(int f, t, i = 0; i < n; i++) {
			cin >> f >> t;
			g[f].push_back(t);
			g[t].push_back(f);
		}
		dfs(1, -69);
		ll cur = n * 1ll * (n-1);
		vis.assign(n+1, 0);
		for(int i = 1; i <= n; i++) if(!vis[i] && loop[i]) {
			ll t = fuck(i);
			cur -= t*(t-1)/2;
		}
		cout << cur << '\n';
	}
}