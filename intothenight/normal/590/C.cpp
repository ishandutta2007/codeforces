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
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	vector<vector<int>> cnumb(n, vector<int>(m, -1));
	int c = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(isdigit(a[i][j]) && !~cnumb[i][j]){
				function<void(int, int)> dfs = [&](int i, int j){
					cnumb[i][j] = c;
					for(auto [di, dj]: dr){
						int ni = i + di, nj = j + dj;
						if(0 <= ni && ni < n && 0 <= nj && nj < m && isdigit(a[ni][nj]) && !~cnumb[ni][nj]){
							dfs(ni, nj);
						}
					}
				};
				dfs(i, j);
				++ c;
			}
		}
	}
	vector<vector<int>> vis(n, vector<int>(m));
	vector<vector<int>> dist(n, vector<int>(m, -1));
	vector<vector<int>> dist2(3, vector<int>(3, numeric_limits<int>::max()));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(isdigit(a[i][j]) && !vis[i][j]){
				vector<vector<int>> cur(n, vector<int>(m, -1));
				deque<array<int, 2>> dq;
				function<void(int, int)> dfs = [&](int i, int j){
					vis[i][j] = true;
					dq.push_back({i, j});
					cur[i][j] = 0;
					for(auto [di, dj]: dr){
						int ni = i + di, nj = j + dj;
						if(0 <= ni && ni < n && 0 <= nj && nj < m && isdigit(a[ni][nj]) && !vis[ni][nj]){
							dfs(ni, nj);
						}
					}
				};
				dfs(i, j);
				int color = cnumb[i][j];
				while(!dq.empty()){
					auto [i, j] = dq.front(); dq.pop_front();
					for(auto [di, dj]: dr){
						int ni = i + di, nj = j + dj;
						if(0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] != '#' && !~cur[ni][nj]){
							dq.push_back({ni, nj});
							cur[ni][nj] = cur[i][j] + 1;
						}
					}
				}
				for(auto i = 0; i < n; ++ i){
					for(auto j = 0; j < m; ++ j){
						if(!~cur[i][j] && isdigit(a[i][j])){
							cout << "-1\n";
							return 0;
						}
						if(~cur[i][j]){
							dist[i][j] = max(dist[i][j], 0) + cur[i][j];
							if(~cnumb[i][j] && cnumb[i][j] != color){
								int color2 = cnumb[i][j];
								dist2[color2][color] = ctmin(dist2[color][color2], cur[i][j]);
							}
						}
					}
				}
			}
		}
	}
	debug(c);
	debug2(dist);
	if(c == 1){
		cout << "0\n";
		return 0;
	}
	int res = numeric_limits<int>::max();
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(~dist[i][j] && a[i][j] == '.'){
				assert(dist[i][j] >= c);
				ctmin(res, dist[i][j] - c + 1);
			}
		}
	}
	if(c == 3){
		ctmin(res, min({dist2[0][1] + dist2[1][2] - 2, dist2[1][2] + dist2[2][0] - 2, dist2[2][0] + dist2[0][1] - 2}));
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