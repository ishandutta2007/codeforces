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
ostream &operator<<(ostream &out, __int128_t x){
	if(!x) return out << 0;
	if(x < 0) out << "-", x = -x;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, __uint128_t x){
	if(!x) return out << 0;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCYELLOW) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCYELLOW) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		char c;
		cin >> u >> v >> c, -- u, -- v;
		adj[u].push_back({v, c == 'R'}), adj[v].push_back({u, c == 'R'});
	}
	graph<int> g(n);
	for(auto u = 0; u < n; ++ u){
		if((int)adj[u].size() >= 2){
			auto t = adj[u];
			t.push_back(t.front());
			for(auto i = 1; i < (int)t.size(); ++ i){
				debug(t[i - 1][0], t[i][0], t[i - 1][1] ^ t[i][1]);
				g.link(t[i - 1][0], t[i][0], t[i - 1][1] ^ t[i][1]);
			}
		}
	}
	vector<bool> vis(n);
	vector<int> state(n, -1), col(n);
	array<vector<int>, 2> res;
	int ans_col = -1;
	for(auto u = 0; u < n; ++ u){
		if(vis[u]){
			continue;
		}
		vector<int> comp;
		y_combinator([&](auto self, int u, int p)->void{
			vis[u] = true;
			comp.push_back(u);
			for(auto [v, w]: adj[u]){
				if(vis[v]) continue;
				self(v, u);
			}
		})(u, -1);
		if((int)comp.size() == 1){
			continue;
		}
		vector<array<vector<int>, 2>> splits;
		for(auto u: comp){
			if(!~state[u]){
				array<vector<int>, 2> split;
				state[u] = 0;
				y_combinator([&](auto self, int u, int pe)->void{
					split[state[u]].push_back(u);
					for(auto id: g.adj[u]){
						if(id == pe || g.ignore && g.ignore(id)) continue;
						auto &e = g.edges[id];
						int v = u ^ e.from ^ e.to;
						if(~state[v]){
							if(state[u] ^ state[v] ^ e.cost){
								cout << "-1\n";
								exit(0);
							}
							continue;
						}
						state[v] = state[u] ^ e.cost;
						self(v, id);
					}
				})(u, -1);
				splits.push_back(split);
			}
		}
		auto [v, w] = adj[u][0];
		debug(u, splits);
		if((int)splits.size() == 1){
			if((int)splits[0][0].size() > (int)splits[0][1].size()){
				swap(splits[0][0], splits[0][1]);
			}
			for(auto u: splits[0][0]){
				col[u] = 1;
			}
			int e = col[u] ^ col[v] ^ w;
			if(~ans_col && ans_col != e){
				cout << "-1\n";
				return 0;
			}
			ans_col = e;
			res[e].insert(res[e].end(), splits[0][0].begin(), splits[0][0].end());
		}
		else{
			assert((int)splits.size() == 2);
			array<array<int, 2>, 2> best{{{numeric_limits<int>::max(), -1}, {numeric_limits<int>::max(), -1}}};
			for(auto mask = 0; mask < 4; ++ mask){
				for(auto u: splits[0][mask & 1]){
					col[u] = 1;
				}
				for(auto u: splits[0][~mask & 1]){
					col[u] = 0;
				}
				for(auto u: splits[1][mask >> 1 & 1]){
					col[u] = 1;
				}
				for(auto u: splits[1][~mask >> 1 & 1]){
					col[u] = 0;
				}
				ctmin(best[col[u] ^ col[v] ^ w], array{(int)splits[0][mask & 1].size() + (int)splits[1][mask >> 1 & 1].size(), mask});
			}
			debug(best);
			if(ans_col != 1){
				int mask = best[0][1];
				for(auto u: splits[0][mask & 1]){
					res[0].push_back(u);
				}
				for(auto u: splits[1][mask >> 1 & 1]){
					res[0].push_back(u);
				}
			}
			if(ans_col != 0){
				int mask = best[1][1];
				for(auto u: splits[0][mask & 1]){
					res[1].push_back(u);
				}
				for(auto u: splits[1][mask >> 1 & 1]){
					res[1].push_back(u);
				}
			}
		}
	}
	if(ans_col == 1 || !~ans_col && (int)res[0].size() > (int)res[1].size()){
		swap(res[0], res[1]);
	}
	cout << (int)res[0].size() << "\n";
	for(auto u: res[0]){
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