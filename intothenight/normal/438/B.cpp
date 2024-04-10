#include <bits/stdc++.h>
using namespace std;

struct disjoint_set{
	int n;
	vector<int> p;
	disjoint_set(int n): n(n), p(n, -1){ }
	// Amortized O(alpha(n))
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	// Amortized O(alpha(n))
	bool share(int a, int b){
		return root(a) == root(b);
	}
	// Amortized O(alpha(n))
	int size(int u){
		return -p[root(u)];
	}
	// Amortized O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	// Amortized O(alpha(n))
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	// O(n)
	void clear(){
		fill(p.begin(), p.end(), -1);
	}
	// O(n)
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto u = 0; u < n; ++ u){
		cin >> a[u];
	}
	vector<array<int, 3>> edge;
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		edge.push_back({min(a[u], a[v]), u, v});
	}
	sort(edge.rbegin(), edge.rend());
	disjoint_set dsu(n);
	vector<array<int, 3>> mst;
	for(auto [w, u, v]: edge){
		if(dsu.merge(u, v)){
			mst.push_back({w, u, v});
		}
	}
	double res = 0;
	dsu.clear();
	for(auto [w, u, v]: mst){
		res += 2LL * w * dsu.size(u) * dsu.size(v);
		dsu.merge(u, v);
	}
	cout << fixed << setprecision(15);
	cout << res / n / (n - 1) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////