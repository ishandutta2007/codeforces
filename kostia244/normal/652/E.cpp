//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 3e5 + 55, mod = 998244353;

struct dsu {
	vi r, p, sm;
	void init(int n) {
		r.resize(n+1);
		p.resize(n+1);
		sm.resize(n+1);
		iota(all(p), 0);
	}
	int par(int i) {
		if(i == p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(j==i) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
		sm[i] += sm[j];
	}
	void inc(int x) {x = par(x); sm[x]++;}
};
int n, m;;
vpi g[maxn];
vi h, dp, cost;
dsu d;
void dfs(int v, int le, int P) {
	dp[v] = 0;
	for (auto i : g[v]) {
		int nxt = i.first;
		if (h[nxt] == 0) { /* edge to child */
			h[nxt] = h[v] + 1;
			dfs(nxt, i.second, v);
			dp[v] += dp[nxt];
		} else if (h[nxt] < h[v]) { /* edge upwards */
			dp[v]++;
		} else if (h[nxt] > h[v]) { /* edge downwards */
			dp[v]--;
		}
	}
 
	/* the parent edge isn't a back-edge, subtract 1 to compensate */
	dp[v]--;
	if (h[v] > 1 && dp[v]) {
		//cout << "PANICC";
		//cout << v << " " << P << '\n';
		d.unite(v, P);
	}
}
int a, b;
vi vis;
bool check(int v, int p, int c) {
	c += d.sm[v];
//	cout << v << " : " << c << ":\n";
	if(v==d.par(b)) {
		cout << (c?"YES":"NO"), exit(0);
	}
	vis[v] = 1;
	for(auto to : g[v]) {
		int i = to.first;
		i = d.par(i);
		if(vis[i]) continue;
		//cout << i << " " << v << '\n';
		check(i, v, c + to.second);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vpi ee;
	vector<pair<pi, int>> fu;
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		g[f].pb({t, c});
		g[t].pb({f, c});
		if(c) ee.pb({f, t});
		fu.pb({{f, t}, c});
	}
	
	cin >> a >> b;
	d.init(n+1);
	h = vi(n+1);
	dp = vi(n+1);
	vis = vi(n+1);
	h[1] = 1;
	dfs(1, 0, 0);
	vis = vi(n+1);
	for(int i = 1; i <= n; i++) g[i].clear();
	for(auto i : ee) if(d.par(i.first)==d.par(i.second)) d.inc(d.par(i.first));
	for(auto i : fu) {
		int f = i.first.first = d.par(i.first.first);
		int t = i.first.second = d.par(i.first.second);
		if(i.first.first==i.first.second) continue;
		g[f].pb({t, i.second});
		g[t].pb({f, i.second});
	}
		
	check(d.par(a), d.par(a), 0);
}