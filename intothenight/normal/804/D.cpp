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
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
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
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

// Requires graph
template<class T, T (*merge)(T, T), T (*identity)()>
struct dfs_forest{
	int n;
	graph<T> *g;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	void init(graph<T> *h){
		g = h;
		n = g->n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, identity());
		was.assign(n, -1);
		attempt = 0;
	}
	void clear(){
		pv.clear();
		pe.clear();
		order.clear();
		pos.clear();
		end.clear();
		sz.clear();
		root.clear();
		depth.clear();
		min_depth.clear();
		dist.clear();
		was.clear();
	}
	int attempt = 0;
	void dfs(int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order){
			order.clear();
		}
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g->adj[u]){
				if(id == pe[u] || g->ignore && g->ignore(id)){
					continue;
				}
				auto &e = g->edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = merge(dist[u], e.cost);
				pv[v] = u;
				pe[v] = id;
				root[v] = ~root[u] ? root[u] : v;
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(){
		order.clear();
		for(auto u = 0; u < n; ++ u){
			if(!~depth[u]){
				dfs(u, false);
			}
		}
		assert((int)order.size() == n);
	}
};
int add_merge(int x, int y){
	return x + y;
}
int add_id(){
	return {};
}
//	dfs_forest<int, add_merge, add_id> df;

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	int n, m, qn;
	cin >> n >> m >> qn;
	graph<int> g(n);
	disjoint_set dsu(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
		dsu.merge(u, v);
	}
	vector<vector<int>> comp(n);
	vector<int> pos(n);
	for(auto u = 0; u < n; ++ u){
		pos[u] = (int)comp[dsu.root(u)].size();
		comp[dsu.root(u)].push_back(u);
	}
	dfs_forest<int, add_merge, add_id> df;
	df.init(&g);
	vector<int> diam(n, -1);
	vector<vector<int>> dist(n);
	vector<vector<long long>> pref(n, {0});
	for(auto r = 0; r < n; ++ r){
		if(!comp[r].empty()){
			df.dfs(r);
			dist[r].resize((int)comp[r].size());
			int x = comp[r][0];
			for(auto u: comp[r]){
				if(df.depth[u] > df.depth[x]){
					x = u;
				}
			}
			df.dfs(x);
			debug(x, df.depth);
			for(auto u: comp[r]){
				dist[r][pos[u]] = df.depth[u];
			}
			int y = comp[r][0];
			for(auto u: comp[r]){
				if(df.depth[u] > df.depth[y]){
					y = u;
				}
			}
			diam[r] = df.depth[y];
			df.dfs(y);
			debug(y, df.depth);
			for(auto u: comp[r]){
				ctmax(dist[r][pos[u]], df.depth[u]);
			}
			sort(dist[r].begin(), dist[r].end());
			for(auto x: dist[r]){
				pref[r].push_back(pref[r].back() + x);
			}
		}
	}
	cout << fixed << setprecision(15);
	vector<double> res(qn, -1);
	vector<map<int, vector<int>>> q(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int u, v;
		cin >> u >> v, -- u, -- v;
		u = dsu.root(u), v = dsu.root(v);
		if(u != v){
			if(dsu.sz(u) > dsu.sz(v)){
				swap(u, v);
			}
			q[u][v].push_back(qi);
		}
	}
	for(auto u = 0; u < n; ++ u){
		for(auto [v, qL]: q[u]){
			int d = max(diam[u], diam[v]);
			debug(d);
			debug(dist[u]);
			debug(pref[u]);
			debug(dist[v]);
			debug(pref[v]);
			long long tot = 0;
			for(auto x: dist[u]){
				int pivot = lower_bound(dist[v].begin(), dist[v].end(), d - x - 1) - dist[v].begin();
				tot += 1LL * pivot * d + 1LL * (x + 1) * ((int)dist[v].size() - pivot) + pref[v].back() - pref[v][pivot];
				debug(pivot, tot);
			}
			debug(u, v, tot);
			for(auto qi: qL){
				res[qi] = 1.0 * tot / (1LL * dsu.sz(u) * dsu.sz(v));
			}
		}
	}
	for(auto x: res){
		cout << x << "\n";
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