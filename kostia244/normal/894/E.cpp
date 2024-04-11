#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1000100;
struct dsu {
	int r[maxn], p[maxn];
	void init(int n) {
		for(int i = 0; i <= n; i++)
			p[i] = i;
	}
	int par(int i) {
		if(i==p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[i]==r[j];
	}
};
int n, m, s;
vi g[maxn], gt[maxn];
vector<pair<int, int>> tree[maxn];
vector<pair<int, pair<int, int>>> edges;
vi topo;
dsu d;
bitset<1000100> vis;
void dfs(int v) {
	vis[v] = 1;
	for(auto i : gt[v]) if(!vis[i]) dfs(i);
	topo.pb(v);
}
void cfs(int v) {
	vis[v] = 1;
//	cout << v << " ";
	for(auto i : g[v]) if(!vis[i]) d.unite(v, i), cfs(i);
}
ll val[1000100], dp[1000100];
ll ans = 0;
ll go(int v) {
	if(dp[v]!=-1) {
		return dp[v];
	}
	dp[v] = 0;
//	assert(vis[v]==0);
//	cout << v << " " << vis[v] << "\n";
//	vis[v] = 1;
//	cout << v << "\n";
	s+=val[v];
	for(auto i : tree[v])
		dp[v] = max(go(i.first)+i.second, dp[v]);
	return dp[v] += val[v];
}
ll ap(ll z) {
	return z*(z+1)/2;
}
ll pref[20010];
int main() { //DINIC ORZ
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 1; i <= 20000; i++) {
		pref[i] = pref[i-1]+ap(i);
	}
	cin >> n >> m;
	d.init(n);
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		edges.pb({c, {f, t}});
		g[f].pb(t);
		gt[t].pb(f);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) dfs(i);
	}
	vis = 0;
	reverse(all(topo));
	for(auto i : topo) {
		if(!vis[i]) {
		cfs(i);
//		cout << ";\n";
		}
	}
	ll z = 0;
	sort(all(edges));
	for(auto i : edges) {
		int u = d.par(i.second.first);
		int v = d.par(i.second.second);
		if(u!=v)
		tree[u].pb({v, i.first});
		else {
			while(ap(z+1)<=i.first) z++;
//			cout << u << " " << i.second << " " << get(i.second) << "orz\n";
//			cout << i.first << " " << z << "\n";
			val[u] += (z+1)*i.first - pref[z];
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(all(tree[i]));
		tree[i].erase(unique(all(tree[i])), tree[i].end());
	}
	cin >> s;
	vis = 0;
	cout << go(d.par(s)) << "\n";
}