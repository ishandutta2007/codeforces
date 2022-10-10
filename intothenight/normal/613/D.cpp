#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	template<class T>
	lca_solver(const graph<T> &g, const vector<int> &roots): n(g.n), pv(n, -1), pe(n, -1), depth(n), pos(n, -1), end(n, -1){
		int it = 0;
		auto dfs = [&](auto self, int u)->void{
			pos[u] = (int)order.size();
			order.push_back(u), pos_order.push_back(pos[u]);
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
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
	int lca(int u, int v) const{
		if(u == v) return u;
		tie(u, v) = minmax(pos[u], pos[v]);
		return order[rmq.query(u, v)];
	}
	// assumes u and v are on the same component
	int steps(int u, int v, int w = -1) const{
		return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
	}
	bool ancestor_of(int u, int v) const{
		return pos[u] <= pos[v] && end[v] <= end[v];
	}
};

// Requires graph, range_minmax_query_solver, and lca_solver
vector<array<int, 2>> compressed_tree(const lca_solver &lca, const vector<int> &subset){ // build the minimal tree containing all the nodes in O(|subset| log |subset|)
	auto order = subset;
	const auto &p = lca.pos;
	auto cmp = [&](int u, int v){ return p[u] < p[v]; };
	sort(order.begin(), order.end(), cmp);
	for(auto i = 1, sz = (int)order.size(); i < sz; ++ i) order.push_back(lca.lca(order[i - 1], order[i]));
	sort(order.begin(), order.end(), cmp), order.erase(unique(order.begin(), order.end()), order.end());
	vector<array<int, 2>> edges;
	for(auto i = 1; i < (int)order.size(); ++ i) edges.push_back({lca.lca(order[i - 1], order[i]), order[i]});
	return edges;
}

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
	int n;
	cin >> n;
	graph<int> g(n);
	set<array<int, 2>> s;
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
		s.insert({u, v}), s.insert({v, u});
	}
	lca_solver ls(g, {0});
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		static graph<int> cg(n);
		static vector<array<int, 2>> dp(n);
		int m;
		cin >> m;
		vector<int> a(m);
		for(auto i = 0; i < m; ++ i){
			cin >> a[i], -- a[i];
		}
		if(m == 1){
			cout << "0\n";
			continue;
		}
		sort(a.begin(), a.end());
		auto e = compressed_tree(ls, a);
		bool fin = false;
		vector<int> extra;
		for(auto [u, v]: e){
			if(binary_search(a.begin(), a.end(), u) && binary_search(a.begin(), a.end(), v)){
				if(s.count({u, v})){
					fin = true;
					break;
				}
				if(ls.depth[u] < ls.depth[v]){
					swap(u, v);
				}
				cg.link(u, ls.pv[u]), cg.link(ls.pv[u], v);
				extra.push_back(ls.pv[u]);
			}
			else{
				cg.link(u, v);
			}
		}
		auto clear = [&]()->void{
			cg.edges.clear();
			for(auto [u, v]: e){
				cg.adj[u].clear();
				cg.adj[v].clear();
			}
			for(auto u: extra){
				cg.adj[u].clear();
			}
		};
		if(fin){
			cout << "-1\n";
			clear();
			continue;
		}
		int res = numeric_limits<int>::max(), root = e[0][0];
		y_combinator([&](auto self, int u, int pe)->void{
			if(binary_search(a.begin(), a.end(), u)){
				dp[u] = {numeric_limits<int>::max() / 2, 0};
				for(auto id: cg.adj[u]){
					if(id == pe || cg.ignore && cg.ignore(id)) continue;
					auto &e = cg.edges[id];
					int v = u ^ e.from ^ e.to;
					self(v, id);
					dp[u][1] = min(dp[u][1] + dp[v][0], numeric_limits<int>::max() / 2);
				}
			}
			else{
				dp[u] = {0, numeric_limits<int>::max() / 2};
				int sum = 0;
				for(auto id: cg.adj[u]){
					if(id == pe || cg.ignore && cg.ignore(id)) continue;
					auto &e = cg.edges[id];
					int v = u ^ e.from ^ e.to;
					self(v, id);
					dp[u] = {
						min(dp[u][0] + dp[v][0], numeric_limits<int>::max() / 2),
						min({dp[u][0] + dp[v][1], dp[u][1] + dp[v][0], numeric_limits<int>::max() / 2})
					};
					sum = min(sum + min(dp[v][0], dp[v][1]), numeric_limits<int>::max() / 2);
				}
				ctmin(dp[u][0], 1 + sum);
			}
		})(root, -1);
		cout << min(dp[root][0], dp[root][1]) << "\n";
		clear();
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