#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU{
	int cmp;
	vector<int>p; // -size if self, parent otherwise
	DSU(int n):cmp(n),p(n,-1){}
	int find(int u){return p[u]<0?u:p[u]=find(p[u]);}
	int size(int u){return -p[find(u)];}
	bool same(int u,int v){return find(u)==find(v);}
	int comps(){return cmp;}
	void uni(int u,int v){
		u=find(u),v=find(v);
		if(u!=v){
			if(size(u)>size(v))swap(u,v);
			p[v]+=p[u];
			p[u]=v;
			--cmp;
		}
	}
};


void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n), tg(n);
	DSU dsu(n);
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		if (!dsu.same(u, v)) {
			tg[u].push_back(v);
			tg[v].push_back(u);
			dsu.uni(u, v);
		}
	}
	int cntout = 0;
	vector<int> par(n), cnt(n), mup(n, INT_MAX), vis(n), depth(n);
	function<int(int, int, int)> dfs = [&] (int u, int p, int d) {
		par[u] = true;
		depth[u] = d;
		for (int v : tg[u]) if (v != p) mup[u] = min(mup[u], dfs(v, u, d + 1));
		for (int v : g[u]) {
			if (par[v]) {
				if (v != p) mup[u] = min(mup[u], depth[v]);
				--cnt[u]; --cnt[v];
				--cntout;
			} else if (vis[v]) {
				++cnt[u]; ++cnt[v];
				++cntout;
			}
		}
		par[u] = false;
		vis[u] = true;
		return mup[u];
	};
	dfs(0, 0, 0);
	string res(n, '0');
	function<void(int, int, int)> dfs2 = [&] (int u, int c, int p) {
		c += cnt[u];
		int cntup = 0, who = 0;
		for (int v : tg[u]) if (v != p && mup[v] < depth[u]) ++cntup, who = v;
		if (!cntup && c == cntout) res[u] = '1';
		for (int v : tg[u]) if (v != p && (!cntup || (cntup == 1 && who == v))) dfs2(v, c, u);
	};
	dfs2(0, 0, 0);
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	//cin >> tc;
	while (tc--) ProGamerMove();
}