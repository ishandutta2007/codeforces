#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
int n;
vi sz;
vector<vi> g;
vector<pair<pi, ll>> edges;
void dfs(int v = 1, int p = 1) {
	sz[v] = 1;
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs(i, v);
		sz[v] += sz[i];
	}
}
void solve() {
	cin >> n;
	edges.clear();
	g.assign(2*n+1, {});
	sz.assign(2*n+1, 0);
	ll f, t, c;
	for(int i = 1; i < 2*n; i++) {
		cin >> f >> t >> c;
		g[f].pb(t);
		g[t].pb(f);
		edges.pb({{f, t}, c});
	}
	dfs();
	ll g = 0, b = 0;
	for(auto i : edges) {
		f = i.first.first, t = i.first.second, c = i.second;
		if(sz[f]<sz[t]) swap(f, t);
		g += (sz[t]&1)*1ll*c;
		b += min(sz[t], 2*n - sz[t])*1ll*c;
	}
	cout << g << " " << b << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}