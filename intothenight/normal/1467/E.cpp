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
	void dfs(const graph<U> &g, int u, function<T(U, T)> UT = plus<>(), bool clear_order = true){
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
	void dfs_all(const graph<U> &g, function<T(U, T)> UT){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(g, u, UT, false);
	}
};

template<class T>
struct sparse_table{
	int n;
	vector<vector<T>> data;
	function<T(T, T)> TT; // monoid operation (must be idempotent)
	T T_id; // monoid identity
	sparse_table(){ }
	sparse_table(const vector<T> &a, function<T(T, T)> TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = TT(data[i - 1][j], data[i - 1][j + p]);
		}
	}
	T query(int l, int r){ // O(1)
		if(l >= r) return T_id;
		int d = __lg(r - l);
		return TT(data[d][l], data[d][r - (1 << d)]);
	}
};

// Requires graph and sparse_table
struct lca_solver{
	int n;
	vector<int> pos, depth, order, porder;
	sparse_table<int> rmq;
	template<class T>
	lca_solver(const graph<T> &g, const vector<int> &roots = {0}): n(g.n), depth(n), pos(n, -1){
		int it = 0;
		function<void(int, int)> dfs = [&](int u, int pe){
			pos[u] = it ++;
			for(auto id: g.adj[u]) if(id != pe){
				if(g.ignore && g.ignore(id)) continue;
				order.push_back(u), porder.push_back(pos[u]);
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				depth[v] = depth[u] + 1;
				dfs(v, id);
			}
		};
		for(auto root: roots) if(!~pos[root]) dfs(root, -1);
		rmq = {porder, [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2};
	}
	int query(int u, int v){
		if(u == v) return u;
		tie(u, v) = minmax(pos[u], pos[v]);
		return order[rmq.query(u, v)];
	}
	int steps(int u, int v, int w = -1){ return depth[u] + depth[v] - 2 * depth[~w ? w : query(u, v)]; }
};

// Requires graph, sparse_table and lca_solver
vector<array<int, 2>> compressed_tree(lca_solver &lca, const vector<int> &subset){ // build the minimal tree containing all the nodes in O(|subset| log |subset|)
	vector<int> order = subset, &p = lca.pos;
	auto cmp = [&](int u, int v){ return p[u] < p[v]; };
	sort(order.begin(), order.end(), cmp);
	for(int i = 1, sz = (int)order.size(); i < sz; ++ i) order.push_back(lca.query(order[i - 1], order[i]));
	sort(order.begin(), order.end(), cmp), order.erase(unique(order.begin(), order.end()), order.end());
	vector<array<int, 2>> edges;
	for(int i = 1; i < (int)order.size(); ++ i) edges.push_back({lca.query(order[i - 1], order[i]), order[i]});
	return edges; // return edgelists
}

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, vector<int>> mp;
	for(auto u = 0; u < n; ++ u){
		cin >> a[u];
		mp[a[u]].push_back(u);
	}
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	dfs_forest<int> df(n);
	df.dfs<int>(g, 0);
	lca_solver ls(g);
	vector<int> val(n);
	for(auto [ignore, L]: mp){
		if((int)L.size() >= 2){
			auto e = compressed_tree(ls, L);
			static vector<int> cnt(n);
			for(auto [u, v]: e){
				++ cnt[u], ++ cnt[v];
			}
			for(auto u: L){
				if(cnt[u] >= 2){
					cout << "0\n";
					return 0;
				}
			}
			for(auto [u, v]: e){
				-- cnt[u], -- cnt[v];
			}
			int root = L[0];
			for(auto i = 1; i < (int)L.size(); ++ i){
				root = ls.query(root, L[i]);
			}
			sort(L.begin(), L.end());
			for(auto u: L){
				if(u == root){
					++ val[0];
					int w = L[0];
					if(w == u){
						w = L[1];
					}
					for(auto id: g.adj[u]){
						auto &e = g.edges[id];
						int v = u ^ e.from ^ e.to;
						if(ls.query(u, v) == u && ls.query(w, v) == v){
							-- val[v];
							break;
						}
					}
				}
				else{
					++ val[u];
				}
			}
		}
	}
	function<void(int, int)> dfs = [&](int u, int pe){
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			val[v] += val[u];
			dfs(v, id);
		}
	};
	debug(val);
	dfs(0, -1);
	debug(val);
	cout << count_if(val.begin(), val.end(), [&](int x){ assert(x >= 0); return !x; }) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////