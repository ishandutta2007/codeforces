#pragma GCC optimize("trapv")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
vector<vi> g;
vi h, a[2];
int n, m;
void dfs(int v) {
	a[h[v]&1].pb(v);
	for(auto i : g[v]) {
		if(h[i]) continue;
		h[i] = h[v] + 1;
		dfs(i);
	}
}
void solve() {
	cin >> n >> m;
	g.assign(n+1, {});
	h.assign(n+1, 0);
	a[0].clear();
	a[1].clear();
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	h[1] = 1;
	dfs(1);
	if(a[0].size()>a[1].size()) swap(a[0], a[1]);
	cout << a[0].size() << "\n";
	for(auto i : a[0]) cout << i << " ";cout << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}