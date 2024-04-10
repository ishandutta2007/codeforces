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
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
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
struct bfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, root, depth, was;
	T T_id;
	bfs_forest(int n, T T_id = 0): T_id(T_id){
		init(n);
	}
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		root.assign(n, -1);
		depth.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt = 0;
	template<class U>
	void bfs(const graph<U> &g, vector<int> src, bool clear_order = true, function<T(U, T)> UT = plus<>()){
		++ attempt;
		if(clear_order) order.clear();
		deque<int> dq;
		for(auto u: src){
			was[u] = attempt;
			depth[u] = 0;
			dist[u] = T_id;
			root[u] = u;
			pv[u] = pe[u] = -1;
			dq.push_back(u);
		}
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			pos[u] = (int)order.size();
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] == attempt) continue;
				was[v] = attempt;
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				dq.push_back(v);
			}
		}
	}
	template<class U>
	void bfs_all(const graph<U> &g, function<T(U, T)> UT = plus<>()){
		for(int u = 0; u < n; ++ u) if(!~depth[u]) bfs(g, {u}, false, UT);
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
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "[" << #__VA_ARGS__ << "]", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.orient(u, v);
	}
	vector<vector<int>> dist(n, vector<int>(n));
	bfs_forest<int> bf(n);
	for(auto u = 0; u < n; ++ u){
		bf.init(n);
		bf.bfs<int>(g, {u});
		dist[u] = bf.depth;
	}
	debug2(dist);
	vector<array<int, 3>> right(n, {-1, -1, -1});
	vector<array<int, 3>> left(n, {-1, -1, -1});
	for(auto u = 0; u < n; ++ u){
		for(auto v = 0; v < n; ++ v){
			if(u != v){
				if(~dist[v][u]){
					if(!~left[u][0] || dist[left[u][0]][u] < dist[v][u]){
						left[u][2] = left[u][1];
						left[u][1] = left[u][0];
						left[u][0] = v;
					}
					else if(!~left[u][1] || dist[left[u][1]][u] < dist[v][u]){
						left[u][2] = left[u][1];
						left[u][1] = v;
					}
					else if(!~left[u][2] || dist[left[u][2]][u] < dist[v][u]){
						left[u][2] = v;
					}
				}
				if(~dist[u][v]){
					if(!~right[u][0] || dist[u][right[u][0]] < dist[u][v]){
						right[u][2] = right[u][1];
						right[u][1] = right[u][0];
						right[u][0] = v;
					}
					else if(!~right[u][1] || dist[u][right[u][1]] < dist[u][v]){
						right[u][2] = right[u][1];
						right[u][1] = v;
					}
					else if(!~right[u][2] || dist[u][right[u][2]] < dist[u][v]){
						right[u][2] = v;
					}
				}
			}
		}
	}
	debug(left);
	debug(right);
	auto ok = [&](int x, int y, int z, int w){
		return ~x && ~y && ~z && ~w && x != y && x != z && x != w && y != z && y != w && z != w;
	};
	pair<int, array<int, 4>> res{numeric_limits<int>::min(), {}};
	for(auto u = 0; u < n; ++ u){
		for(auto v = 0; v < n; ++ v){
			if(u != v && ~dist[u][v]){
				for(auto i = 0; i < 3; ++ i){
					for(auto j = 0; j < 3; ++ j){
						if(ok(left[u][i], u, v, right[v][j])){
							ctmax(res, pair{dist[left[u][i]][u] + dist[u][v] + dist[v][right[v][j]], array{left[u][i], u, v, right[v][j]}});
						}
					}
				}
			}
		}
	}
	for(auto i = 0; i < 4; ++ i){
		cout << res.second[i] + 1 << " ";
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