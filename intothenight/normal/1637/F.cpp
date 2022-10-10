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

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
	int n;
	vector<vector<T>> data;
	Compare cmp;
	T T_id;
	range_minmax_query_solver(){ }
	// O(n log n)
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	// O(1)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};

// Requires graph and range_minmax_query_solver
struct lca_solver{
	int n;
	vector<int> pv, pe, pos, end, depth, order, pos_order;
	range_minmax_query_solver<int> rmq;
	// O(|V| log |V|)
	template<class T>
	lca_solver(const graph<T> &g, const vector<int> &roots): n(g.n), pv(n, -1), pe(n, -1), depth(n), pos(n, -1), end(n, -1){
		int it = 0;
		auto dfs = [&](auto self, int u)->void{
			pos[u] = (int)order.size();
			order.push_back(u), pos_order.push_back(pos[u]);
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				pv[v] = u;
				pe[v] = id;
				depth[v] = depth[u] + 1;
				self(self, v);
				order.push_back(u), pos_order.push_back(pos[u]);
			}
			end[u] = (int)order.size();
		};
		for(auto root: roots) if(!~pos[root]) dfs(dfs, root);
		rmq = {pos_order};
	}
	// assumes u and v are on the same component
	// O(1)
	int lca(int u, int v) const{
		if(u == v) return u;
		tie(u, v) = minmax(pos[u], pos[v]);
		return order[rmq.query(u, v)];
	}
	// assumes u and v are on the same component
	// O(1)
	int steps(int u, int v, int w = -1) const{
		return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
	}
	// O(1)
	bool ancestor_of(int u, int v) const{
		return pos[u] <= pos[v] && end[v] <= end[u];
	}
};

// Requires graph
template<int h = 20>
struct binary_lifting{
	int n = 0;
	vector<int> depth;
	vector<array<int, h>> lift;
	binary_lifting(){ }
	// pv: parent vertex (-1 if root of an arborescence)
	binary_lifting(const vector<int> &pv): n((int)pv.size()), depth(n, numeric_limits<int>::max()), lift(n){
		for(auto u = 0; u < n; ++ u) lift[u][0] = ~pv[u] ? pv[u] : u;
		for(auto bit = 1; bit < h; ++ bit) for(auto u = 0; u < n; ++ u) lift[u][bit] = lift[lift[u][bit - 1]][bit - 1];
	}
	template<class T>
	binary_lifting(const graph<T> &g, const vector<int> &roots){
		vector<int> pv(g.n, -1), depth(g.n);
		auto dfs = [&](auto self, int u, int pe)->void{
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				depth[v] = depth[u] + 1;
				pv[v] = u;
				self(self, v, id);
			}
		};
		for(auto u: roots) assert(!depth[u]), pv[u] = u, dfs(dfs, u, -1);
		*this = binary_lifting(pv, depth);
	}
	// pv: parent vertex (-1 if root of an arborescence)
	binary_lifting(const vector<int> &pv, const vector<int> &depth): n((int)pv.size()), depth(depth){
		lift.resize(n);
		for(auto u = 0; u < n; ++ u) lift[u][0] = ~pv[u] ? pv[u] : u;
		for(auto d = 1; d < h; ++ d) for(auto u = 0; u < n; ++ u) lift[u][d] = lift[lift[u][d - 1]][d - 1];
	}
	// Index becomes the current number of nodes
	// O(log n)
	int add_root(){
		int u = n ++;
		depth.push_back(0);
		lift.emplace_back();
		fill(lift.back().begin(), lift.back().end(), u);
		return u;
	}
	// Index becomes the current number of nodes
	// O(log n)
	int add_child(int p){
		assert(0 <= p && p < n);
		int u = n ++;
		depth.push_back(depth[p] + 1);
		lift.emplace_back();
		lift[u][0] = p;
		for(auto d = 1; d < h; ++ d) lift[u][d] = lift[lift[u][d - 1]][d - 1];
	}
	// Get the k-th ancestor of u
	// O(log n)
	int ancestor(int u, int k) const{
		for(auto d = 0; d < h; ++ d) if(k & 1 << d) u = lift[u][d];
		return u;
	}
	// Assumes u and v lies on the same arboresence
	// O(log n)
	int lca(int u, int v) const{
		if(depth[u] < depth[v]) swap(u, v);
		u = ancestor(u, depth[u] - depth[v]);
		if(u == v) return u;
		for(auto d = h - 1; d >= 0; -- d) if(lift[u][d] != lift[v][d]) u = lift[u][d], v = lift[v][d];
		return lift[u][0];
	}
	// Get # of edges between u and v
	// Assumes u and v lies on the same arboresence
	// O(log n)
	int steps(int u, int v, int w = -1) const{
		return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
	}
	// For an ancestor p of u, pred(p) is T, ..., T, F, ..., F in decreasing order of depth. Returns the highest p with T
	// O(log n)
	int find_highest(int u, auto pred) const{
		assert(pred(u));
		for(auto d = h - 1; d >= 0; -- d) if(pred(lift[u][d])) u = lift[u][d];
		return u;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> w(n);
	map<int, vector<int>> appear;
	for(auto u = 0; u < n; ++ u){
		cin >> w[u];
		appear[w[u]].push_back(u);
	}
	auto cw = w;
	cw.push_back(0);
	ranges::sort(cw);
	cw.erase(unique(cw.begin(), cw.end()), cw.end());
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	lca_solver ls(g, {0});
	binary_lifting lift(g, {0});
	long long res = 0;
	vector<int> deg(n);
	int leaf_cnt = 0, init = -1;
	vector<int> color(n);
	for(auto t = (int)cw.size() - 1; t; -- t){
		for(auto u: appear[cw[t]]){
			if(!~init){
				init = u;
				color[init] = true;
			}
			else if(!color[u]){
				deg[u] = 1;
				++ leaf_cnt;
				static vector<int> path;
				path.clear();
				while(!color[u]){
					color[u] = true;
					path.push_back(u);
					if(!ls.ancestor_of(u, init)){
						u = ls.pv[u];
					}
					else{
						u = lift.ancestor(init, lift.depth[init] - lift.depth[u] - 1);
					}
				}
				leaf_cnt -= deg[u] == 1;
				++ deg[u];
				leaf_cnt += deg[u] == 1;
				for(auto t = 1; t < (int)path.size(); ++ t){
					deg[path[t]] = 2;
				}
			}
		}
		res += 1LL * (cw[t] - cw[t - 1]) * max(leaf_cnt, 2);
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