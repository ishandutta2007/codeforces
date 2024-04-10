#include <bits/stdc++.h>
using namespace std;

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
	vector<int> pv, pe, order, pos, end, size, root, depth, min_depth, was;
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
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
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
				self(self, v);
				size[u] += size[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
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
	graph<int> g(n);
	disjoint_set dsu(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
		dsu.merge(u, v);
	}
	vector<int> state(n), flag(n);
	for(auto u = 0; u < n; ++ u){
		cin >> state[u];
		if(state[u]){
			flag[dsu.root(u)] = true;
		}
	}
	if(accumulate(flag.begin(), flag.end(), 0) >= 2){
		cout << "-1\n";
		return 0;
	}
	if(accumulate(flag.begin(), flag.end(), 0) == 0){
		cout << "0\n";
		return 0;
	}
	int r = 0;
	while(r < n - 1 && !flag[r]){
		++ r;
	}
	dfs_forest<int> df(n);
	df.dfs(g, r);
	list<int> order;
	vector<list<int>::iterator> lastpos(n);
	y_combinator([&](auto self, int u)->void{
		order.push_back(u);
		state[u] ^= 1;
		lastpos[u] = prev(order.end());
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			if(df.pv[v] != u) continue;
			self(v);
			order.push_back(u);
			state[u] ^= 1;
			lastpos[u] = prev(order.end());
		}
	})(r);
	for(auto it = order.begin(); it != order.end(); ++ it){
		int u = *it;
		if(it == lastpos[u] && state[u]){
			if(next(it) != order.end()){
				int v = *next(it);
				it = order.insert(next(order.insert(next(it), v)), u);
				state[u] ^= 1, state[v] ^= 1;
			}
			else{
				int v = *prev(it);
				order.push_back(v);
				order.push_back(u);
				order.push_back(v);
				it = prev(order.end());
				state[u] ^= 1;
			}
		}
	}
	assert((int)order.size() <= 4 * n);
	cout << (int)order.size() << "\n";
	for(auto u: order){
		cout << u + 1 << " ";
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