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
	graph(int n): n(n), adj(n){ }
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
};

// Requires graph
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
	template<class U, class F = plus<>>
	void dfs(const graph<U> &g, int u, bool clear_order = true, F UT = plus<>()){
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
	template<class U, class F = plus<>>
	void dfs_all(const graph<U> &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<U, F>(g, u, false, UT);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	graph<int> g(n * m);
	auto ind = [&](int i, int j)->int{
		return i * m + j;
	};
	int ri = -1, rj = -1;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '.'){
				ri = i, rj = j;
				if(i + 1 < n && a[i + 1][j] == '.'){
					g.link(ind(i, j), ind(i + 1, j));
				}
				if(j + 1 < m && a[i][j + 1] == '.'){
					g.link(ind(i, j), ind(i, j + 1));
				}
			}
		}
	}
	dfs_forest<int> df(n * m);
	df.dfs(g, ind(ri, rj));
	for(auto u: df.order | ranges::views::reverse | ranges::views::take(k)){
		auto [i, j] = div(u, m);
		a[i][j] = 'X';
	}
	ranges::copy(a, ostream_iterator<string>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////