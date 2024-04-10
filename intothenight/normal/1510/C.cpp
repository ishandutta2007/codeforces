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
template<class T> // O(V + E)
void biconnected_components(const graph<T> &g, auto act_comp, auto act_bridge){
	int n = g.n, it = 0;
	vector<int> pos(n), s;
	auto dfs = [&](int u, int pe, auto dfs)->int{
		int top = pos[u] = ++ it;
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id) || id == pe) continue;
			int v = u ^ g.edges[id].from ^ g.edges[id].to;
			if(pos[v]){
				top = min(top, pos[v]);
				if(pos[v] < pos[u]) s.push_back(id);
			}
			else{
				int sz = (int)s.size(), up = dfs(v, id, dfs);
				top = min(top, up);
				if(up == pos[u]){
					s.push_back(id);
					act_comp({s.begin() + sz, s.end()}); // Processes edgelist
					s.resize(sz);
				}
				else if(up < pos[u]) s.push_back(id);
				else act_bridge(id);
			}
		}
		return top;
	};
	for(auto u = 0; u < n; ++ u) if(!pos[u]) dfs(u, -1, dfs);
}
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
	for(int n, m; cin >> n >> m, n; ){
		graph<int> g(n);
		int e = 0;
		for(auto rep = 0; rep < m; ++ rep){
			int len;
			cin >> len;
			vector<int> p(len);
			for(auto &u: p){
				cin >> u, -- u;
			}
			for(auto i = 1; i < len; ++ i){
				g.link(p[i - 1], p[i]);
				++ e;
			}
		}
		vector<int> oncycle(e);
		auto act_c = [&](const vector<int> &c){
			for(auto id: c){
				oncycle[id] = true;
			}
		};
		biconnected_components(g, act_c, [&](int){  });
		vector<int> vis(n), pairings(n, -1), rem(n, -1), depth(n), pv(n, -1);
		for(auto u = 0; u < n; ++ u){
			if(!vis[u]){
				debug("root", u);
				function<void(int)> dfs = [&](int u){
					vis[u] = true;
					debug(u, pairings[u], rem[u]);
					for(auto id: g.adj[u]){
						if(oncycle[id] || g.ignore && g.ignore(id)) continue;
						auto &e = g.edges[id];
						int v = u ^ e.from ^ e.to;
						if(vis[v]) continue;
						depth[v] = depth[u] + 1;
						pv[v] = u;
						dfs(v);
						debug("updating", u, "from", v, pairings[v], rem[v]);
						if(~pairings[u] && ~rem[u]){
							if(~pairings[v]){
								pairings[pairings[u]] = pairings[v];
								pairings[pairings[v]] = pairings[u];
								pairings[u] = -1;
								pairings[v] = -1;
							}
							else if(~rem[v]){
								pairings[pairings[u]] = rem[v];
								pairings[rem[v]] = pairings[u];
								pairings[u] = -1;
								rem[v] = -1;
							}
							else{
								pairings[pairings[u]] = v;
								pairings[v] = pairings[u];
								pairings[u] = -1;
							}
						}
						else if(~pairings[u]){
							if(~pairings[v]){
								pairings[pairings[u]] = pairings[v];
								pairings[pairings[v]] = pairings[u];
								pairings[u] = -1;
								pairings[v] = -1;
							}
							else if(~rem[v]){
								pairings[pairings[u]] = rem[v];
								pairings[rem[v]] = pairings[u];
								pairings[u] = -1;
								rem[v] = -1;
							}
							else{
								rem[u] = v;
							}
						}
						else if(~rem[u]){
							if(~pairings[v]){
								pairings[u] = pairings[v];
								pairings[pairings[v]] = pairings[u];
								pairings[v] = -1;
							}
							else if(~rem[v]){
								pairings[u] = rem[v];
								pairings[rem[v]] = u;
								rem[v] = -1;
							}
							else{
								pairings[u] = v;
								pairings[v] = u;
							}
						}
						else{
							if(~pairings[v]){
								pairings[u] = pairings[v];
								pairings[pairings[v]] = u;
								pairings[v] = -1;
							}
							else if(~rem[v]){
								pairings[u] = rem[v];
								pairings[rem[v]] = u;
								rem[v] = -1;
							}
							else{
								rem[u] = v;
							}
						}
						debug("After update:", u, pairings[u], rem[u]);
					}
				};
				dfs(u);
			}
		}
		vector<array<int, 2>> res;
		debug(pairings);
		debug(rem);
		for(auto u = 0; u < n; ++ u){
			if(~pairings[u] && pair{depth[u], u} < pair{depth[pairings[u]], pairings[u]}){
				if(pv[pairings[u]] == u){
					assert(~rem[u]);
					res.push_back({pairings[u], rem[u]});
				}
				else{
					res.push_back({u, pairings[u]});
				}
			}
		}
		cout << (int)res.size() << "\n";
		for(auto [u, v]: res){
			cout << u + 1 << " " << v + 1 << "\n";
		}
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