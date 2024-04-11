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
const int maxn = 1<<19, mod = (119<<23)+1;
int n, m, k = 0;
int h[maxn], p[maxn], b[maxn];
vi g[maxn];
void cyc(int x, int y) {
	cout << "2\n";
	vi t;
	while(1) {
		t.pb(x);
		if(x == y) break;
		x = p[x];
	}
	cout << t.size() << '\n';
	for(auto i : t) cout << i << " ";
	exit(0);
}
vi topo;
void dfs(int v) {
	for(auto i : g[v]) {
		if(h[i]) {
			if(h[v]-h[i]+1>=k) cyc(v, i);
			continue;
		}
		h[i] = h[v] + 1, p[i] = v;
		dfs(i);
	}
	topo.pb(v);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(k*k < n) k++;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	p[1] = -1;
	h[1] = 1;
	dfs(1);
	vi r;
	for(auto i : topo) {
		if(b[i]) continue;
		b[i] = 1;
		for(auto j : g[i]) b[j] = 1;
		r.pb(i);
	}
	cout << "1\n";
	assert(r.size()>=k);
	for(int i = 0; i < k; i++) cout << r[i] << ' ';
}