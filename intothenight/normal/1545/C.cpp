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

template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> MOD_INV;
	constexpr Z_p(): value(){ }
	template<typename U> Z_p(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
	template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
	Z_p &operator++(){ return *this += 1; }
	Z_p &operator--(){ return *this -= 1; }
	Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
	Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
	Z_p operator-() const{ return Z_p(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
		#ifdef _WIN32
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		#else
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		#endif
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	Z_p &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		Z_p res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	Z_p operator^(U e) const{
		return Z_p(*this) ^= e;
	}
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)MOD_INV.size()) return *this *= MOD_INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
	typename common_type<typename Z_p<T>::Type, int64_t>::type x;
	in >> x;
	number.value = Z_p<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/

// constexpr int mod = 1e9 + 7; // 1000000007
constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::MOD_INV;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(int SZ){
	auto &inv = Z_p<T>::MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) % mod);
}

template<typename T>
vector<T> precalc_power(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
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

// Requires graph
template<class T> // O(V^3)
vector<int> blossom_maximum_unweighted_matching(const graph<T> &g){
	vector<int> mate(g.n, -1), label(g.n), parent(g.n), orig(g.n);
	queue<int> q;
	vector<int> aux(g.n, -1);
	int aux_time = -1;
	auto lca = [&](int x, int y){
		++ aux_time;
		while(true){
			if(x != -1){
				if(aux[x] == aux_time) return x;
				aux[x] = aux_time;
				if(mate[x] == -1) x = -1;
				else x = orig[parent[mate[x]]];
			}
			swap(x, y);
		}
	};
	auto blossom = [&](int v, int w, int a){
		while(orig[v] != a){
			parent[v] = w, w = mate[v];
			if(label[w] == 1) label[w] = 0, q.push(w);
			orig[v] = orig[w] = a, v = parent[w];
		}
	};
	auto augment = [&](int v){
		while(v != -1){
			int pv = parent[v], nv = mate[pv];
			mate[v] = pv, mate[pv] = v, v = nv;
		}
	};
	auto bfs = [&](int root){
		fill(label.begin(), label.end(), -1);
		iota(orig.begin(), orig.end(), 0);
		while(!q.empty()) q.pop();
		q.push(root);
		label[root] = 0;
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int id : g.adj[v]){
				auto &e = g.edges[id];
				int x = e.from ^ e.to ^ v;
				if(label[x] == -1){
					label[x] = 1, parent[x] = v;
					if(mate[x] == -1){
						augment(x);
						return true;
					}
					label[mate[x]] = 0, q.push(mate[x]);
					continue;
				}
				if(label[x] == 0 && orig[v] != orig[x]){
					int a = lca(orig[v], orig[x]);
					blossom(x, v, a), blossom(v, x, a);
				}
			}
		}
		return false;
	};
	auto greedy = [&](){
		vector<int> order(g.n);
		iota(order.begin(), order.end(), 0);
		shuffle(order.begin(), order.end(), mt19937(787788));
		for(int i: order) if(mate[i] == -1) for(int id: g.adj[i]){
			auto &e = g.edges[id];
			int to = e.from ^ e.to ^ i;
			if(mate[to] == -1){
				mate[i] = to, mate[to] = i;
				break;
			}
		}
	};
	greedy();
	for(int i = 0; i < g.n; ++ i) if(mate[i] == -1) bfs(i);
	return mate;
}

struct two_sat_solver{
	int n;
	vector<vector<int>> adj;
	vector<int> value, val, comp, z;
	two_sat_solver(int n = 0): n(n), adj(n << 1){ }
	int time = 0;
	int add_var(){
		adj.emplace_back();
		adj.emplace_back();
		return ++ n;
	}
	void either(int u, int v){
		u = max(2 * u, -1 - 2 * u);
		v = max(2 * v, -1 - 2 * v);
		adj[u].push_back(v ^ 1);
		adj[v].push_back(u ^ 1);
	}
	void set_value(int u){
		either(u, u);
	}
	void at_most_one(const vector<int> &arr){
		if((int)arr.size() <= 1) return;
		int cur = ~arr[0];
		for(int u = 2; u < (int)arr.size(); ++ u){
			int next = add_var();
			either(cur, ~arr[u]), either(cur, next), either(~arr[u], next);
			cur = ~next;
		}
		either(cur, ~arr[1]);
	}
	int dfs(int u){
		int low = val[u] = ++ time, v;
		z.push_back(u);
		for(auto v: adj[u]) if(!comp[v]) low = min(low, val[v] ?: dfs(v));
		++ time;
		if(low == val[u]) do{
			v = z.back();
			z.pop_back();
			comp[v] = time;
			if(value[v >> 1] == -1) value[v >> 1] = v & 1;
		}while(v != u);
		return val[u] = low;
	}
	bool solve(){
		value.assign(n, -1), val.assign(2 * n, 0), comp = val;
		for(int u = 0; u < n << 1; ++ u) if(!comp[u]) dfs(u);
		for(int u = 0; u < n; ++ u) if(comp[u << 1] == comp[u << 1 ^ 1]) return false;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<vector<int>> a(n << 1, vector<int>(n));
		for(auto i = 0; i < n << 1; ++ i){
			for(auto j = 0; j < n; ++ j){
				cin >> a[i][j], -- a[i][j];
			}
		}
		graph<int> g(n << 1);
		vector<vector<bool>> dif(n << 1, vector<bool>(n << 1));
		for(auto i = 0; i < n << 1; ++ i){
			for(auto j = i + 1; j < n << 1; ++ j){
				bool flag = true;
				for(auto k = 0; k < n; ++ k){
					if(a[i][k] == a[j][k]){
						flag = false;
					}
				}
				if(flag){
					dif[i][j] = dif[j][i] = true;
				}
				else{
					g.link(i, j);
				}
			}
		}
		vector<int> pu = blossom_maximum_unweighted_matching(g);
		vector<array<int, 2>> p;
		for(auto u = 0; u < n << 1; ++ u){
			assert(~pu[u]);
			if(u < pu[u]){
				p.push_back({u, pu[u]});
			}
		}
		two_sat_solver solver(n);
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				for(auto x = 0; x < 2; ++ x){
					i = ~i;
					for(auto y = 0; y < 2; ++ y){
						j = ~j;
						if(!dif[p[max(i, ~i)][x]][p[max(j, ~j)][y]]){
							solver.either(~i, ~j);
						}
					}
				}
			}
		}
		assert(solver.solve());
		for(auto i = 0; i < n; ++ i){
			if(solver.value[i]){
				swap(p[i][0], p[i][1]);
			}
		}
		debug(p);
		#ifdef LOCAL
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				assert(dif[p[i][0]][p[j][0]]);
			}
		}
		#endif
		Zp res = 1;
		vector<vector<int>> tot;
		for(auto i = 0; i < n; ++ i){
			vector<int> cur;
			vector<vector<bool>> found(n, vector<bool>(n));
			vector<vector<bool>> found2(n, vector<bool>(n));
			vector<bool> vis(n);
			bool fail = false;
			y_combinator([&](auto self, int i)->void{
				vis[i] = true;
				cur.push_back(i);
				for(auto t = 0; t < n; ++ t){
					found[t][a[p[i][0]][t]] = true;
				}
				for(auto t = 0; t < n; ++ t){
					if(found2[t][a[p[i][1]][t]]){
						fail = true;
					}
					found2[t][a[p[i][1]][t]] = true;
				}
				for(auto t = 0; t < n; ++ t){
					if(!found[t][a[p[i][1]][t]]){
						for(auto j = 0; j < n; ++ j){
							if(a[p[j][0]][t] == a[p[i][1]][t]){
								assert(i != j);
								assert(!vis[j]);
								self(j);
								break;
							}
						}
					}
				}
			})(i);
			if(!fail){
				sort(cur.begin(), cur.end());
				tot.push_back(cur);
			}
		}
		sort(tot.begin(), tot.end());
		tot.erase(unique(tot.begin(), tot.end()), tot.end());
		cout << (Zp(2) ^ (int)tot.size()) << "\n";
		for(auto [i, j]: p){
			cout << i + 1 << " ";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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