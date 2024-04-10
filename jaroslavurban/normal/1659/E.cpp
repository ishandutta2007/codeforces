#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100100;

struct DSU{
	int cmp;
	vector<int>p; // -size if self, parent otherwise
	DSU(int n = N):cmp(n),p(n,-1){}
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
	vector<vector<pair<int, int>>> g(n);
	array<DSU, 30> dsu;
	vector<int> out(n), good(n);
	for (int u, v, w, i = 0; i < m; ++i) {
		cin >> u >> v >> w, --u, --v;
		for (int j = 0; j < 30; ++j) if (w & (1 << j)) dsu[j].uni(u, v);
		if (!(w & 1)) out[u] = out[v] = 1;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	for (int t = 1; t < 30; ++t) {
		vector<int> vis(n);
		queue<int> q;
		for (int i = 0; i < n; ++i) if (out[i]) {
			q.push(i);
			vis[i] = true;
		}
		while (q.size()) {
			int u = q.front(); q.pop();
			good[u] = true;
			for (auto [w, v] : g[u]) if (dsu[0].same(u, v) && (w & (1 << t)) && !vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v, --u, --v;
		bool same = false;
		for (int i = 0; i < 30; ++i) if (dsu[i].same(u, v)) same = true;
		if (same) cout << "0\n";
		else if (good[u]) cout << "1\n";
		else cout << "2\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}