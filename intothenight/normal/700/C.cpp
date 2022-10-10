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
template<class T>
struct dfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
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
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	template<class U>
	void dfs(const graph<U> &g, int u, bool clear_order = true, function<T(U, T)> UT = plus<>()){
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
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
				dist[v] = UT(e.cost, dist[u]);
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
	template<class U>
	void dfs_all(const graph<U> &g, function<T(U, T)> UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(g, u, false, UT);
	}
};

// Requires graph
template<class T> // O(V + E)
void biconnected_components(graph<T> &g, auto act_comp, auto act_bridge){
	int n = g.n, it = 0;
	vector<int> pos(n), s;
	function<int(int, int)> dfs = [&](int u, int pe){
		int top = pos[u] = ++ it;
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id) || id == pe) continue;
			int v = u ^ g.edges[id].from ^ g.edges[id].to;
			if(pos[v]){
				top = min(top, pos[v]);
				if(pos[v] < pos[u]) s.push_back(id);
			}
			else{
				int sz = (int)s.size(), up = dfs(v, id);
				top = min(top, up);
				if(up == pos[u]){
					s.push_back(id);
					act_comp({s.begin() + sz, s.end()}); // Processes edgelist
					s.resize(sz);
				}
				else if(up < pos[u]) s.push_back(id);
				else act_bridge(id);
			}
		}
		return top;
	};
	for(int u = 0; u < n; ++ u) if(!pos[u]) dfs(u, -1);
}
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, s, t;
	cin >> n >> m >> s >> t, -- s, -- t;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	dfs_forest<int> df(n);
	df.dfs(g, s);
	if(!~df.depth[t]){
		cout << "0\n0\n";
		return 0;
	}
	vector<int> cut;
	for(auto u = t; u != s; u = df.pv[u]){
		cut.push_back(df.pe[u]);
	}
	pair<int, array<int, 2>> res{numeric_limits<int>::max(), {}};
	for(auto e: cut){
		g.ignore = [&](int id){ return id == e; };
		df.init(n);
		df.dfs(g, s);
		if(!~df.depth[t]){
			ctmin(res, pair{g.edges[e].cost, array{e, -1}});
			continue;
		}
		bitset<30000> onpath;
		for(auto u = t; u != s; u = df.pv[u]){
			onpath.set(df.pe[u]);
		}
		auto act = [&](int id){
			if(onpath[id]){
				ctmin(res, pair{g.edges[e].cost + g.edges[id].cost, array{e, id}});
			}
		};
		biconnected_components(g, [&](const vector<int> &){  }, act);
	}
	if(res.first == numeric_limits<int>::max()){
		cout << "-1\n";
		return 0;
	}
	cout << res.first << "\n" << !!~res.second[0] + !!~res.second[1] << "\n";
	for(auto id: res.second){
		if(~id){
			cout << id + 1 << " ";
		}
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////