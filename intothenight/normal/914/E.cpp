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
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	T query(int l, int r) const{ // O(1)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};

// Requires graph and range_minmax_query_solver
struct lca_solver{
	int n;
	vector<int> pv, pe, pos, depth, order, pos_order;
	range_minmax_query_solver<int> rmq;
	template<class T>
	lca_solver(const graph<T> &g, const vector<int> &roots): n(g.n), pv(n, -1), pe(n, -1), depth(n), pos(n, -1){
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
	template<class U, class F = plus<>>
	void dfs(const graph<U> &g, int u, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto recurse, int u)->void{
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
				recurse(recurse, v);
				sz[u] += sz[v];
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

// Requires graph
// O(V log V)
template<class T>
struct centroid_decomposition{
	int n, root; // the root of the arborescence
	graph<int> abr; // stores the arborescence
	vector<int> sz;
	vector<vector<T>> dist; // dist[u][i]: sum of weights from u to its i-th centroid parent
	T T_id;
	template<class U, class F = plus<>>
	centroid_decomposition(const graph<U> &g, T T_id = {}, F UT = plus<>()): n(g.n), abr(g.n), T_id(T_id), dist(g.n), sz(g.n){
		vector<int> dead(n), sz(n);
		auto centroid = [&](int s){
			int u = s, pe = -1;
			while(true){
				for(auto id: g.adj[u]){
					if(id == pe || g.ignore && g.ignore(id)) continue;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					if(dead[v]) continue;
					if(sz[v] > sz[s] >> 1){
						u = v, pe = id;
						goto NEXT;
					}
				}
				break;
				NEXT:;
			}
			return u;
		};
		auto dfs_sz = [&](auto self, int u, int p)->void{
			sz[u] = 1;
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(p == v || dead[v]) continue;
				self(self, v, u);
				sz[u] += sz[v];
			}
		};
		auto set_distance = [&](auto self, int u, int pe)->void{
			int p = u ^ g.edges[pe].from ^ g.edges[pe].to;
			dist[u].push_back(UT(g.edges[pe].cost, dist[p].back()));
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(dead[v]) continue;
				self(self, v, id);
			}
		};
		auto construct = [&](auto self, int u, int p)->void{
			dfs_sz(dfs_sz, u, p);
			dead[u = centroid(u)] = true;
			this->sz[u] = sz[u];
			if(~p) abr.orient(p, u);
			else root = u;
			dist[u].push_back(T_id);
			for(auto id: g.adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(!dead[v]) set_distance(set_distance, v, id);
			}
			for(auto id: g.adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(!dead[v]) self(self, v, u);
			}
		};
		construct(construct, 0, -1);
		for(auto u = 0; u < n; ++ u) reverse(dist[u].begin(), dist[u].end());
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	centroid_decomposition<int> CD(g);
	dfs_forest<int> df(n);
	df.dfs<int>(CD.abr, CD.root);
	lca_solver ls(g, {0});
	string s;
	cin >> s;
	const int mx = 20;
	vector<int> pref(n);
	y_combinator([&](auto self, int u, int pe)->void{
		pref[u] ^= 1 << s[u] - 'a';
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			pref[v] ^= pref[u];
			self(v, id);
		}
	})(0, -1);
	auto get = [&](int u, int v)->int{
		int w = ls.lca(u, v), res = pref[u] ^ pref[v] ^ pref[w];
		if(~ls.pv[w]){
			res ^= pref[ls.pv[w]];
		}
		return res;
	};
	vector<long long> res(n);
	auto update = [&](int u, int v, long long x)->void{
		int w = ls.lca(u, v);
		res[u] += x, res[v] += x, res[w] -= x;
		if(~ls.pv[w]){
			res[ls.pv[w]] -= x;
		}
	};
	for(auto u = 0; u < n; ++ u){
		update(u, u, 1);
	}
	for(auto r = 0; r < n; ++ r){
		static vector<int> cnt(1 << mx);
		for(auto rep = 0; rep < 2; ++ rep){
			// update dp
			for(auto id: CD.abr.adj[r]){
				int nr = CD.abr.edges[id].to;
				for(auto i = df.pos[nr]; i < df.end[nr]; ++ i){
					int u = df.order[i], x = get(r, u);
					if(!rep && __builtin_popcount(x) <= 1){
						update(r, u, 1);
					}
					// update ^ path
					x ^= 1 << s[r] - 'a';
					update(r, u, cnt[x]);
					if(rep){
						update(r, r, -cnt[x]);
					}
					for(auto bit = 0; bit < mx; ++ bit){
						update(r, u, cnt[x ^ 1 << bit]);
						if(rep){
							update(r, r, -cnt[x ^ 1 << bit]);
						}
					}
				}
				// update cnt
				for(auto i = df.pos[nr]; i < df.end[nr]; ++ i){
					++ cnt[r, get(r, df.order[i])];
				}
			}
			// clean up cnt
			for(auto id: CD.abr.adj[r]){
				int nr = CD.abr.edges[id].to;
				for(auto i = df.pos[nr]; i < df.end[nr]; ++ i){
					-- cnt[r, get(r, df.order[i])];
				}
			}
			reverse(CD.abr.adj[r].begin(), CD.abr.adj[r].end());
		}
	}
	y_combinator([&](auto self, int u, int pe)->void{
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			self(v, id);
			res[u] += res[v];
		}
	})(0, -1);
	for(auto x: res){
		cout << x << " ";
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