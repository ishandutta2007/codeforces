#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7;
int n, m, k;
vi g[maxn];
int p[maxn], h[maxn];
void path(int v) {
	cout << "PATH\n" << h[v] << '\n';
	while(v != -1) {
		cout << v << " ";
		v = p[v];
	}
	exit(0);
}
vector<vi> cyc;
void add_cycle(int v, int x) {
	if(h[v]<h[x]) swap(v, x);
	cyc.push_back({});
	auto &t = cyc.back();
	while(1) {
		t.pb(v);
		if(x==v) break;
		v = p[v];
	}
}
void dfs(int v) {
	if(h[v] >= (n+k-1)/k) path(v);
	int leaf = 1;
	for(auto i : g[v]) {
		if(h[i]) continue;
		p[i] = v, h[i] = h[v] + 1;
		dfs(i);
		leaf = 0;
	}
	if(!leaf) return;
	if(g[v][0] == p[v]) swap(g[v][0], g[v].back()), g[v].pop_back();
	if(g[v][1] == p[v]) swap(g[v][1], g[v].back()), g[v].pop_back();
	int x = g[v][0], y = g[v][1];
	if((h[v]-h[x]+1)%3 == 0) swap(x, y);
	if((h[v]-h[x]+1)%3 != 0) add_cycle(v, x);
	else add_cycle(x, y), cyc.back().push_back(v);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	h[1] = 1;
	p[1] = -1;
	dfs(1);
	cout << "CYCLES\n";
	for(int i = 0; i < k; i++) {
		cout << cyc[i].size() << '\n';
		for(auto j : cyc[i]) cout << j << " "; cout << '\n';
	}
}