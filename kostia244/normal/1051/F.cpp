#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pb push_back
using namespace std;using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<17, mlg = 17, mod = 998244353;
namespace sovlerr {
int n, h[maxn], p[maxn][mlg];
struct solver {
	vector<vi> tree;
	void init(int _n, vector<vi> t) {
		memset(p, 0, sizeof p);
		memset(h, 0, sizeof h);
		n = _n;
		tree = t;
		dfs(1, 0);
	}
	void dfs(int v, int pr) {
		p[v][0] = pr;
		for(int i = 1; i < mlg; i++)
			p[v][i] = p[p[v][i-1]][i-1];
		for(auto i : tree[v]) {
			if(i==pr) continue;
			h[i] = h[v]+1;
			dfs(i, v);
		}
	}
	int lca(int u, int v) {
		if(h[u]<h[v]) swap(u, v);
		int d = h[u]-h[v];
		for(int i = 0; i < mlg; i++)
			if((d>>i)&1)
				u = p[u][i];
		if(u==v) return u;
		for(int i = mlg; i--;)
			if(p[u][i]!=p[v][i])
				u = p[u][i], v = p[v][i];
		return p[u][0];
	}
};
};
ll n, m;
ll dst[maxn];
vector<pair<ll, ll>> g[maxn], wt[maxn];
vector<ll> vis, ex, dr;
vector<vi> t;
vector<array<ll, 3>> tmp;
void extra(int v, int p = -1) {
	vis[v] = 1;
	for(auto [i, c] : g[v]) {
		if(i == p) continue;
		if(!vis[i]) {
			t[v].pb(i);
			wt[v].pb({i, c});
			wt[i].pb({v, c});
			dst[i] = dst[v] + c;
			extra(i, v);
		} else ex.pb(i), tmp.pb({i, v, c});
	}
}
ll D[44][maxn], T = 0, C[44][44];
void get(int v, int p = -1) {
	for(auto &i : wt[v]) {
		if(i.first == p) continue;
		D[T][i.first] = D[T][v] + i.second;
		get(i.first, v);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(C, 0x3f, sizeof C);
	cin >> n >> m;
	for(ll f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		g[f].pb({t, c});
		g[t].pb({f, c});
	}
	vis.assign(n+1, 0);
	t.resize(n+1);
	extra(1);
	sort(all(ex));
	ex.erase(unique(all(ex)), ex.end());
	sovlerr::solver s;
	s.init(n, t);
	for(auto i : tmp) {
		int a = find(all(ex), i[0])-ex.begin();
		int b = find(all(ex), i[1])-ex.begin();
		//cout << a << " " << b << " " << i[2] << " " << C[a][b] << '\n';
		C[a][b] = min(C[a][b], i[2]);
		C[b][a] = min(C[b][a], i[2]);
	}
	for(int i = 0; i < ex.size(); i++) {
		T = i;
		get(ex[i]);
		for(int j = 0; j < ex.size(); j++) {
			C[i][j] = min(C[i][j], D[i][ex[j]]);
		}
	}
	for(int i = 0; i < ex.size(); i++)
		for(int j = 0; j < ex.size(); j++)
			for(int k = 0; k < ex.size(); k++)
				C[j][k] = min(C[j][k], C[j][i] + C[i][k]);
	int q, a, b;
	cin >> q;
	while(q--) {
		cin >> a >> b;
		int t = s.lca(a, b);
		ll ans = dst[a] + dst[b] - 2ll*dst[t];
		for(int i = 0; i < ex.size(); i++)
			for(int j = 0; j < ex.size(); j++) {
				ans = min(ans, C[i][j] + D[i][a] + D[j][b]);
			}
		cout << ans << '\n';
	}
}