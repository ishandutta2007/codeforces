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

template<bool Enable_small_to_large = true>
struct disjoint_set{
	int n, _classes;
	vector<int> p;
	disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	int make_set(){
		p.push_back(-1);
		++ _classes;
		return n ++;
	}
	int classes() const{
		return _classes;
	}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	bool share(int a, int b){
		return root(a) == root(b);
	}
	int size(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		bool swapped = false;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v), swapped = true;
		p[u] += p[v], p[v] = u;
		act(u, v, swapped);
		return true;
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

// Requires graph and disjoint_set
template<class T>
vector<int> minimum_spanning_forest(const graph<T> &g){
	vector<int> order((int)g.edge.size());
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){ return g.edge[i].cost < g.edge[j].cost; });
	disjoint_set dsu(g.n);
	vector<int> res;
	for(auto id: order){
		if(g.ignore && g.ignore(id)) continue;
		auto &e = g.edge[id];
		if(dsu.merge(e.from, e.to)) res.push_back(id);
	}
	return res;
}

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
	// Requires graph
	template<class Graph>
	binary_lifting(const Graph &g, const vector<int> &roots){
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

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, i);
	}
	vector<int> in_mst(m);
	graph<int> h(n);
	for(auto id: minimum_spanning_forest(g)){
		in_mst[id] = true;
		auto [u, v, w] = g.edge[id];
		h.link(u, v, w);
	}
	binary_lifting lift(h, {0});
	vector<int> good(n), update(n);
	int cnt = 0;
	for(auto id = 0; id < m; ++ id){
		if(!in_mst[id]){
			++ cnt;
			auto [u, v, w] = g.edge[id];
			if(lift.depth[u] > lift.depth[v]){
				swap(u, v);
			}
			w = lift.lca(u, v);
			if(u == w){
				++ good[0];
				-- good[lift.ancestor(v, lift.steps(u, v) - 1)];
				++ good[v];
			}
			else{
				++ good[u];
				++ good[v];
			}
		}
	}
	y_combinator([&](auto self, int u, int p)->void{
		for(auto id: h.adj[u]){
			int v = h(u, id);
			if(v != p){
				good[v] += good[u];
				self(v, u);
			}
		}
	})(0, -1);
	for(auto u = 0; u < n; ++ u){
		cout << (good[u] == cnt);
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