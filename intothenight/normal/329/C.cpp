#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<bool Enable_small_to_large = true>
struct disjoint_set{
	int n, _classes;
	vector<int> p;
	disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	int classes() const{
		return _classes;
	}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	bool share(int a, int b){
		return root(a) == root(b);
	}
	int size(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
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
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
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
void debug_frac_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_frac_out(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	debug_frac_out(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> deg(n);
	vector<vector<int>> adj(n);
	disjoint_set dsu(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
		++ deg[u], ++ deg[v];
		dsu.merge(u, v);
	}
	auto g = dsu.group_up();
	ranges::sort(g, [&](auto x, auto y){ return (int)x.size() < (int)y.size(); });
	vector<int> cycle((int)g.size(), true);
	for(auto i = 0; i < (int)g.size(); ++ i){
		for(auto u: g[i]){
			if(deg[u] != 2){
				cycle[i] = false;
				break;
			}
		}
		static vector<int> vis(n);
		vector<int> path;
		y_combinator([&](auto self, int u)->void{
			path.push_back(u);
			vis[u] = true;
			for(auto v: adj[u]){
				if(!vis[v]){
					self(v);
				}
			}
		})(ranges::min(g[i], [&](int u, int v){ return deg[u] < deg[v]; }));
		g[i] = path;
	}
	if((int)g.size() == 1){
		if(cycle[0]){
			if((int)g[0].size() <= 4){
				cout << "-1\n";
				return 0;
			}
			for(auto i = 0; i < n; ++ i){
				cout << g[0][i] + 1 << " " << g[0][(i + 2) % n] + 1 << "\n";
			}
		}
		else{
			if((int)g[0].size() <= 3){
				cout << "-1\n";
				return 0;
			}
			if((int)g[0].size() == 4){
				cout << g[0][0] + 1 << " " << g[0][2] + 1 << "\n";
				cout << g[0][0] + 1 << " " << g[0][3] + 1 << "\n";
				cout << g[0][1] + 1 << " " << g[0][3] + 1 << "\n";
			}
			else{
				for(auto i = 0; i < n - 1; ++ i){
					cout << g[0][i] + 1 << " " << g[0][(i + 2) % n] + 1 << "\n";
				}
			}
		}
	}
	else{
		if((int)g.size() == 2 && (int)g[0].size() == 1 && (int)g[1].size() == 3){
			if(cycle[1]){
				cout << "-1\n";
			}
			else{
				int a = g[1][0], b = g[1][1], c = g[1][2], d = g[0][0];
				assert(m == 2);
				cout << a + 1 << " " << d + 1 << "\n" << d + 1 << " " << b + 1 << "\n";
			}
			return 0;
		}
		ranges::reverse(g);
		if((int)g[0].size() >= 5){
			int cnt = (int)g[0].size();
			vector<vector<int>> res(cnt);
			if(cnt & 1){
				for(auto i = 0; i < cnt; ++ i){
					res[i].push_back(g[0][i * 2 % cnt]);
				}
			}
			else{
				for(auto i = 0; i < cnt / 2; ++ i){
					res[i].push_back(g[0][i * 2]);
				}
				for(auto i = 0; i < cnt / 2; ++ i){
					res[cnt / 2 + i].push_back(g[0][(1 - 2 * i % cnt + cnt) % cnt]);
				}
			}
			debug(res);
			for(auto t = 1; t < (int)g.size(); ++ t){
				for(auto i = 0; i < (int)g[t].size(); ++ i){
					res[i].push_back(g[t][i]);
				}
			}
			vector<int> path;
			for(auto u: ranges::views::join(res)){
				path.push_back(u);
			}
			assert((int)path.size() == n);
			for(auto i = 0; i < m; ++ i){
				cout << path[i] + 1 << " " << path[(i + 1) % n] + 1 << "\n";
			}
		}
		else if((int)g[0].size() * 2 <= n){
			int cnt = (int)g[0].size();
			vector<vector<int>> res(cnt);
			for(auto i = 0; i < cnt; ++ i){
				res[i].push_back(g[0][i]);
			}
			for(auto t = 1; t < (int)g.size(); ++ t){
				static int it = 0;
				for(auto u: g[t]){
					res[it].push_back(u);
					it = (it + 1) % cnt;
				}
			}
			vector<int> path;
			for(auto u: ranges::views::join(res)){
				path.push_back(u);
			}
			assert((int)path.size() == n);
			for(auto i = 0; i < m; ++ i){
				cout << path[i] + 1 << " " << path[(i + 1) % n] + 1 << "\n";
			}
		}
		else if((int)g[0].size() == 4){
			if(n >= 6){
				// (4, 3), (4, 2, 1), (4, 2), (4, 1, 1)
				int cnt = 4;
				vector<vector<int>> res(cnt);
				res[0].push_back(g[0][0]);
				res[1].push_back(g[0][1]);
				res[2].push_back(g[0][3]);
				res[3].push_back(g[0][2]);
				debug(res);
				vector<int> put{0, 2, 1, 3};
				for(auto t = 1; t < (int)g.size(); ++ t){
					for(auto u: g[t]){
						static int it = 0;
						res[put[it]].push_back(u);
						++ it;
					}
				}
				debug(res);
				vector<int> path;
				for(auto u: ranges::views::join(res)){
					path.push_back(u);
				}
				assert((int)path.size() == n);
				for(auto i = 0; i < m; ++ i){
					cout << path[i] + 1 << " " << path[(i + 1) % n] + 1 << "\n";
				}
			}
			else{
				// (4, 1)
				int a = g[0][0], b = g[1][0], c = g[0][2];
				int d = g[0][1], e = g[0][3];
				vector<array<int, 2>> edge({{a, b}, {b, c}, {c, a}, {d, e}});
				assert((int)edge.size() >= m);
				edge.resize(m);
				for(auto [u, v]: edge){
					cout << u + 1 << " " << v + 1 << "\n";
				}
			}
		}
		else if((int)g[0].size() == 3){
			// (3, 2), (3, 1, 1)
			int a = g[0][0], b = g[0][1], c = g[0][2];
			int d = g[1][0], e = (int)g[1].size() == 1 ? g[2][0] : g[1][1];
			vector<array<int, 2>> edge{{a, d}, {d, b}, {b, e}, {e, c}};
			assert((int)edge.size() >= m);
			edge.resize(m);
			for(auto [u, v]: edge){
				cout << u + 1 << " " << v + 1 << "\n";
			}
		}
		else{
			assert((int)g[0].size() == 2 && (int)g[1].size() == 1 && m == 1);
			int a = g[0][0], b = g[0][1], c = g[1][0];
			cout << a + 1 << " " << c + 1 << "\n";
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