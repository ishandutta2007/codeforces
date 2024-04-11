#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 5e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ld = long double;
struct dsu
{
	int sz;
	vector<int> par, psz;

	void init(int n)
	{
		sz = n;
		par.assign(sz + 1, 0);
		psz.assign(sz + 1, 0);
		for(int i = 0; i <= sz; i++)
			par[i] = i, psz[i] = 1;
	}

	int root(int u) { return par[u] = ((u == par[u]) ? u : root(par[u])); }

	bool connected(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y)
	{
		x = root(x), y = root(y);
		if(x == y) return;
		if(psz[x] > psz[y]) swap(x, y);
		par[x] = y, psz[y] += psz[x];
	}
};
map<pair<int, int>, ld> memo;
int n, m, q;
vector<pi> dp;
vi g[maxn], l[maxn], sl[maxn];
dsu d;
void merge(pi& a, int b) {
	if(a.first < b) a.second = a.first, a.first = b;
	else if(a.second < b) a.second = b;
}
void merge(pi &a, pi &b) {
	merge(a, 1+b.first);
// 	merge(a, 1+b.second);
}
void dfs1(int v, int p) {
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs1(i, v);
		merge(dp[v], dp[i]);
	}
}
void dfs2(int v, int p) {
//	cout << v << " " << dp[v].first << " " << dp[v].second << "\n";
	if(v!=p) {
//		cout << v << " " << dp[v].first << " " << dp[p].second << "\n";
		if(dp[v].first+1==dp[p].first)
			merge(dp[v], 1+dp[p].second);
		else
			merge(dp[v], 1+dp[p].first);
	}
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs2(i, v);
	}
}
ld calc(int a, int b) {
//	cout << a << " "  << b << "QUERY:\n";
	if(l[a].size() > l[b].size())
		swap(a, b);
	ll tot = l[a].size()*1ll*l[b].size(), sm = 0, D = max(l[a].front(), l[b].front());
	for(auto i : l[a]) {
		int j = 0;
		for(int z = 1<<17; z>>=1;)
			if(j+z<l[b].size()&&i+l[b][j+z]>=D)
				j+=z;
		if(l[b][j]+i<D)
			sm += (l[b].size())*1ll*D;
		else
			sm += sl[b][j] + (l[b].size()-j-1)*1ll*D;
		sm += (i+1)*1ll*(j+1);
//		cout << i << " " << j << " " << sm << "\n";
	}
	return (ld)sm/(ld)tot;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	dp.resize(n+1, {0, -(1<<20)});
	d.init(n);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
		d.unite(f, t);
	}
	for(int i = 1; i <= n; i++) {
		if(d.root(i)==i) {
			dfs1(i, i);
			dfs2(i, i);
		}
	}
	for(int i = 1; i <= n; i++) {
		l[d.root(i)].pb(dp[i].first);
//		cout << i << " " << dp[i].first << "\n";
	}
	for(int i = 1; i <= n; i++)
		if(d.root(i)==i) {
//			cout << i << "yay\n";
//			cout << i << ": ";
//			for(auto j : l[i]) cout << j << " ";
//			cout << endl;
			sort(rall(l[i]));
			sl[i].resize(l[i].size());
			sl[i][0] = l[i][0];
			for(int j = 1; j < sl[i].size(); j++)
				sl[i][j] = sl[i][j-1] + l[i][j];
		}
	cout << fixed << setprecision(15);
	for(int f, t, i = 0; i < q; i++) {
		cin >> f >> t;
		if(d.connected(t, f)) {
			cout << "-1\n";
			continue;
		}
		f = d.root(f), t = d.root(t);
		if(f>t) swap(f, t);
		if(memo.count({f, t})) {
			cout << memo[{f, t}] << "\n";
			continue;
		}
		cout << (memo[{f, t}]=calc(f, t)) << "\n";
	}
	return 0;
}