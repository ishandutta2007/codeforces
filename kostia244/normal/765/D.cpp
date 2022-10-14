#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<ll>>;
const ll mod = (1e9 + 7);
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vi f, g, h, z;
	int n;
	cin >> n;
	h.pb({-1});
	f.resize(n+1);
	g.resize(n+1, -1);
	z.resize(n+1, -1);
	int m = 0;
	for(int i = 1; i <= n; i++) {
		cin >> f[i];
		if(f[i] == i)
			h.pb(i);
	}
	m=h.size()-1;
	for(int i = 1; i <= m; i++) g[h[i]] = i;
	for(int i = 1; i <= n; i++) if(g[i]==-1)g[i]=g[f[i]];
	for(int i = 1; i <= n; i++) if(g[i]==-1)return cout << -1, 0;
	for(int i = 1; i <= n; i++)
	if(h[g[i]]!=f[i])return cout << -1, 0;
	for(int i = 1; i <= m; i++)
	if(g[h[i]]!=i)return cout << -1, 0;
	cout << m << "\n";
	for(int j = 1; j <= n; j++) cout << g[j] << " ";
	cout << "\n";
	for(int j = 1; j <= m; j++) cout << h[j] << " ";

}