#include <bits/stdc++.h>
using namespace std;

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
struct dfs_forest_base{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	dfs_forest_base(int n){ init(n); }
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
		dist.assign(n, identity());
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	void dfs(graph<T> &g, int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
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
	void dfs_all(graph<T> &g){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(u, false);
	}
};
int add_merge(int x, int y){
	return x + y;
}
int add_id(){
	return {};
}
using dfs_forest = dfs_forest_base<int, add_merge, add_id>;

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
	if(n == 2){
		cout << "1\n";
		return 0;
	}
	int root = 0;
	while((int)g.adj[root].size() == 1){
		++ root;
	}
	dfs_forest df(n);
	df.dfs(g, root);
	array<vector<int>, 2> leaves;
	for(auto u = 0; u < n; ++ u){
		if((int)g.adj[u].size() == 1){
			leaves[df.depth[u] & 1].push_back(u);
		}
	}
	debug(leaves[0]);
	debug(leaves[1]);
	int p = (int)leaves[0].size() <= 1;
	df.dfs(g, leaves[p][0]);
	int t = 0;
	for(auto i = 1; i < (int)leaves[p].size(); ++ i){
		if(df.depth[leaves[p][i]] >  df.depth[leaves[p][t]]){
			t = i;
		}
	}
	df.dfs(g, leaves[p][t]);
	int s = t;
	t = 0;
	for(auto i = 1; i < (int)leaves[p].size(); ++ i){
		if(df.depth[leaves[p][i]] >  df.depth[leaves[p][t]]){
			t = i;
		}
	}
	int x = leaves[p][s], y = leaves[p][t], d = df.depth[y];
	int u = y;
	while(df.depth[u] != df.depth[y] / 2){
		u = df.pv[u];
	}
	debug(x, y, u);
	df.dfs(g, u);
	vector<int> dist;
	for(auto v: leaves[p]){
		dist.push_back(df.depth[v]);
	}
	for(auto v: leaves[!p]){
		dist.push_back(df.depth[v]);
	}
	sort(dist.begin(), dist.end()), dist.erase(unique(dist.begin(), dist.end()), dist.end());
	debug(dist);
	if((int)dist.size() >= 3){
		cout << "-1\n";
		return 0;
	}
	for(auto id: g.adj[u]){
		auto &e = g.edges[id];
		int v = u ^ e.from ^ e.to;
		vector<int> cur;
		function<void(int, int)> solve = [&](int u, int pe){
			if((int)g.adj[u].size() == 1){
				cur.push_back(df.depth[u]);
			}
			for(auto id: g.adj[u]){
				if(id == pe) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				solve(v, id);
			}
		};
		solve(v, id);
		cur.erase(unique(cur.begin(), cur.end()), cur.end());
		if((int)cur.size() >= 2){
			cout << "-1\n";
			return 0;
		}
	}
	int res = (int)dist.size() == 1 ? dist[0] * 2 : dist[0] + dist[1];
	res >>= __builtin_ctz(res);
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