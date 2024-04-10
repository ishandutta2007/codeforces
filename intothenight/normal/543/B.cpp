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
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edges[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

// Requires graph
template<class T>
struct bfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, root, depth, was;
	T T_id;
	bfs_forest(int n, T T_id = 0): T_id(T_id){
		init(n);
	}
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		root.assign(n, -1);
		depth.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt = 0;
	template<class U, class F = plus<>>
	void bfs(const graph<U> &g, vector<int> src, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		if(clear_order) order.clear();
		deque<int> dq;
		for(auto u: src){
			was[u] = attempt;
			depth[u] = 0;
			dist[u] = T_id;
			root[u] = u;
			pv[u] = pe[u] = -1;
			dq.push_back(u);
		}
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			pos[u] = (int)order.size();
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] == attempt) continue;
				was[v] = attempt;
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				dq.push_back(v);
			}
		}
	}
	template<class U, class F = plus<>>
	void bfs_all(const graph<U> &g, F UT = plus<>()){
		for(int u = 0; u < n; ++ u) if(!~depth[u]) bfs<U, F>(g, {u}, false, UT);
	}
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	array<array<int, 3>, 2> q;
	for(auto &[u, v, t]: q){
		cin >> u >> v >> t, -- u, -- v;
	}
	bfs_forest<int> bf(n);
	vector<vector<int>> dist(n);
	for(auto u = 0; u < n; ++ u){
		bf.bfs<int>(g, {u});
		dist[u] = bf.depth;
	}
	int res = m;
	for(auto [u, v, t]: q){
		if(dist[u][v] > t){
			cout << "-1\n";
			return 0;
		}
		res -= dist[u][v];
	}
	auto [u0, v0, t0] = q[0];
	auto [u1, v1, t1] = q[1];
	for(auto rep = 0; rep < 2; ++ rep){
		swap(u0, v0);
		for(auto u = 0; u < n; ++ u){
			for(auto v = 0; v < n; ++ v){
				if(dist[u0][u] + dist[u][v] + dist[v][v0] <= t0 && dist[u1][u] + dist[u][v] + dist[v][v1] <= t1){
					ctmax(res, m - dist[u0][u] - dist[u1][u] - dist[u][v] - dist[v][v0] - dist[v][v1]);
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////