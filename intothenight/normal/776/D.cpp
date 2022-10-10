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
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
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
};

// Requires graph
template<class T, T (*merge)(T, T), T (*identity)()>
struct dfs_forest_base{
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, identity());
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	void dfs(const graph<T> &g, int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = merge(dist[u], e.cost);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(const graph<T> &g){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(g, u, false);
	}
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	dfs_forest_base(int n){ init(n); }
};
template<class T> T add_merge(T x, T y){
	return x ^ y;
}
template<class T> T add_id(){
	return {};
}
template<class T>
using dfs_forest = dfs_forest_base<T, add_merge<T>, add_id<T>>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> m >> n;
	vector<int> w(m);
	for(auto i = 0; i < m; ++ i){
		cin >> w[i], w[i] = !w[i];
	}
	vector<vector<int>> edges(m);
	for(auto i = 0; i < n; ++ i){
		int k;
		cin >> k;
		for(auto j = 0; j < k; ++ j){
			int u;
			cin >> u, -- u;
			edges[u].push_back(i);
		}
	}
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u = edges[i][0], v = edges[i][1];
		g.link(u, v, w[i]);
	}
	dfs_forest<int> df(n);
	df.dfs_all(g);
	for(auto i = 0; i < m; ++ i){
		int u = edges[i][0], v = edges[i][1];
		if(df.dist[u] ^ df.dist[v] ^ w[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////