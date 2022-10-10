#include <bits/stdc++.h>
using namespace std;

template<class T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int size(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g((int)p.size());
		for(auto i = 0; i < (int)p.size(); ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
		}
	}
	auto ind = [&](int i, int j){
		return i * m + j;
	};
	disjoint_set dsu(n * m);
	vector<int> inext(n * m, -1), jnext(n * m, -1);
	for(auto i = 0; i < n; ++ i){
		vector<int> l(m);
		iota(l.begin(), l.end(), 0);
		sort(l.begin(), l.end(), [&](int j1, int j2){ return a[i][j1] < a[i][j2]; });
		for(auto t = 1; t < m; ++ t){
			int j1 = l[t - 1], j2 = l[t];
			jnext[ind(i, j1)] = ind(i, j2);
			if(a[i][j1] == a[i][j2]){
				dsu.merge(ind(i, j1), ind(i, j2));
			}
		}
	}
	for(auto j = 0; j < m; ++ j){
		vector<int> l(n);
		iota(l.begin(), l.end(), 0);
		sort(l.begin(), l.end(), [&](int i1, int i2){ return a[i1][j] < a[i2][j]; });
		for(auto t = 1; t < n; ++ t){
			int i1 = l[t - 1], i2 = l[t];
			inext[ind(i1, j)] = ind(i2, j);
			if(a[i1][j] == a[i2][j]){
				dsu.merge(ind(i2, j), ind(i1, j));
			}
		}
	}
	vector<array<int, 2>> order(n * m);
	for(auto u = 0; u < n * m; ++ u){
		auto [i, j] = div(u, m);
		order[u] = {i, j};
	}
	sort(order.begin(), order.end(), [&](auto p, auto q){ return a[p[0]][p[1]] < a[q[0]][q[1]]; });
	vector<int> dp(n * m, 1);
	vector<vector<int>> res(n, vector<int>(m));
	for(auto [i, j]: order){
		int u = ind(i, j);
		res[i][j] = dp[dsu.root(u)];
		for(auto v: {inext[u], jnext[u]}){
			if(~v && !dsu.share(u, v)){
				ctmax(dp[dsu.root(v)], dp[dsu.root(u)] + 1);
			}
		}
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////