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
	int n;
	cin >> n;
	vector<int> type(n);
	for(auto u = 0; u < n; ++ u){
		cin >> type[u];
	}
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	dfs_forest<int> df(n);
	df.dfs(g, 0);
	vector<int> subtr_cnt = type;
	for(auto u: df.order | ranges::views::reverse){
		for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
			if(id == df.pe[u]){
				continue;
			}
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			subtr_cnt[u] += subtr_cnt[v];
		}
	}
	auto count_after_cut = [&](int u, int v)->int{
		if(df.pv[u] == v){
			return subtr_cnt[u];
		}
		else{
			assert(df.pv[v] == u);
			return subtr_cnt[0] - subtr_cnt[v];
		}
	};
	vector<int> res = type, update(n);
	for(auto u = 0; u < n; ++ u){
		if(type[u]){
			for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				res[v] = true;
				if(type[v]){
					++ update[0];
				}
			}
		}
		else{
			int cnt = 0;
			for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				cnt += type[v];
			}
			if(cnt >= 2){
				ranges::fill(res, 1);
				break;
			}
			if(cnt == 1){
				for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
					auto &e = g.edge[id];
					int v = u ^ e.from ^ e.to;
					if(count_after_cut(u, v) >= 2){
						if(df.pv[u] == v){
							++ update[0];
							-- update[u];
						}
						else{
							++ update[v];
						}
					}
				}
			}
		}
	}
	for(auto u: df.order){
		for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
			if(id == df.pe[u]){
				continue;
			}
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			update[v] += update[u];
		}
		res[u] |= !!update[u];
	}
	ranges::copy(res, ostream_iterator<int>(cout, " "));
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