#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n = 0): n(n), adj(n){ }
	graph(const vector<vector<int>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) if(u < v) link(u, v);
		else for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) orient(u, v);
	}
	graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) if(u < v) link(u, v, w);
		else for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) orient(u, v, w);
	}
	graph(int n, vector<array<int, 2>> &edge, bool undirected = true): n(n){
		for(auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
	}
	graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true): n(n){
		for(auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
	}
	int operator()(int u, int id) const{
		#ifdef LOCAL
		assert(0 <= id && id < (int)edge.size());
		assert(edge[id].from == u || edge[id].to == u);
		#endif
		return u ^ edge[id].from ^ edge[id].to;
	}
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
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
			auto &e = edge[id];
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
	friend ostream &operator<<(ostream &out, const graph &g){
		for(auto id = 0; id < (int)g.edge.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
		}
		return out;
	}
};

template<class T>
struct dfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv;
	vector<int> pe;
	vector<int> order;
	vector<int> pos;
	vector<int> end;
	vector<int> size;
	vector<int> root;
	vector<int> depth;
	vector<int> min_depth;
	vector<int> min_depth_origin;
	vector<int> min_depth_spanning_edge;
	vector<int> was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		size.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		min_depth_origin.assign(n, -1);
		min_depth_spanning_edge.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	// O(n + m)
	// Requires graph
	template<class Graph, class F = plus<>>
	void dfs(const Graph &g, int u, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto self, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			size[u] = 1;
			min_depth[u] = depth[u];
			min_depth_origin[u] = u;
			min_depth_spanning_edge[u] = -1;
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					if(min_depth[u] > depth[v]){
						min_depth[u] = depth[v];
						min_depth_spanning_edge[u] = id;
					}
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				if(min_depth[u] > min_depth[v]){
					min_depth[u] = min_depth[v];
					min_depth_origin[u] = min_depth_origin[v];
					min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
				}
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	// O(n + m)
	template<class Graph, class F = plus<>>
	void dfs_all(const Graph &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<Graph, F>(g, u, false, UT);
	}
	// O(n + m)
	template<class F = plus<>>
	void dfs_implicitly(auto get_deg, auto get_adj, int u, bool clear_order = true, F UT = plus<>()){
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto self, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			size[u] = 1;
			min_depth[u] = depth[u];
			min_depth_origin[u] = u;
			min_depth_spanning_edge[u] = -1;
			for(auto i = 0, deg = get_deg(u); i < deg; ++ i){
				auto [v, w] = get_adj(u, i);
				if(!~v) continue;
				if(was[v] == attempt){
					if(min_depth[u] > depth[v]){
						min_depth[u] = depth[v];
						min_depth_spanning_edge[u] = i;
					}
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(w, dist[u]);
				pv[v] = u;
				pe[v] = i;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				if(min_depth[u] > min_depth[v]){
					min_depth[u] = min_depth[v];
					min_depth_origin[u] = min_depth_origin[v];
					min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
				}
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	// O(n + m)
	template<class F = plus<>>
	void dfs_all_implicitly(auto get_deg, auto get_adj, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<F>(get_deg, get_adj, u, false, UT);
	}
};

template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		graph<int> g(n);
		for(auto u = 1; u < n; ++ u){
			int p;
			cin >> p, -- p;
			g.orient(p, u);
		}
		dfs_forest<int> df(n);
		df.dfs(g, 0);
		// impossible to achieve < th height
		vector<int> depth(n);
		auto bad = [&](int th)->bool{
			int req = 0;
			for(auto u: df.order | ranges::views::reverse){
				depth[u] = 0;
				for(auto id: g.adj[u]){
					int v = g(u, id);
					if(u && depth[v] + 1 >= th){
						++ req;
					}
					else{
						ctmax(depth[u], depth[v] + 1);
					}
				}
			}
			return req > k;
		};
		cout << *ranges::partition_point(ranges::iota_view(1, n - 1), bad) << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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