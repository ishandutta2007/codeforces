/*	author:  Kite_kuma
	created: 2021.02.09 00:31:51 */

// #ifdef LOCAL
// #define _GLIBCXX_DEBUG
// #endif
#include <bits/stdc++.h>
using namespace std;

#pragma region macros

#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcnt(n) __builtin_popcountll((long long)n)

#define REPname(a, b, c, d, e, ...) e
#define rep(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int Counter_in_rep_macro = 0; Counter_in_rep_macro < (x); ++Counter_in_rep_macro)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))

#define DREPname(a, b, c, d, e, ...) e
#define drep(...) DREPname(__VA_ARGS__, DREP3, DREP2, DREP1)(__VA_ARGS__)
#define DREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define DREP2(i, l, r) for(int i = (r)-1; i >= (l); --i)
#define DREP3(i, l, r, c) for(int i = (r)-1; i >= (l); i -= (c))

#pragma endregion

#pragma region aliases

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
template <class T = ll>
using V = vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
template <class T = ll>
using pqup = priority_queue<T, vector<T>, greater<T>>;
template <class T = ll>
using pqdn = priority_queue<T>;

#pragma endregion

#pragma region constants

const int inf = 1e9;
const long long INF = 1e18;
const long double pi = acos(-1);
const char dl = '\n';
const char sp = ' ';
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int mod = 1000000007;
// const int mod = 998244353;

#pragma endregion

#pragma region basic_operation

template <class T>
inline bool in_range(T x, T lef, T rig) {
	return ((lef <= x) && (x < rig));
}

template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << '\n'; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << '\n'; }
void NO() { cout << "NO\n"; }

template <class T>
void drop(T answer) {
	cout << answer << '\n';
	exit(0);
}

void err(bool flag = true) {
	if(!flag) return;
	cout << -1 << '\n';
	exit(0);
}

template <class T>
void vout(vector<T> const &v, bool tate = 0) {
	if(tate) {
		for(auto const &a : v) {
			cout << a << '\n';
		}
		return;
	}
	for(auto it = v.begin(); it != v.end(); it++) {
		cout << (*it);
		if(it != v.end() - 1) {
			cout << ' ';
		}
	}
	cout << '\n';
	return;
}

inline void print() { cout << '\n'; }
template <class T>
inline void print(T x) {
	cout << x << '\n';
	return;
}
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
	cout << H << " ";
	print(T...);
}

template <class T>
void add(vector<T> &v, T val) {
	for(auto &a : v) a += val;
	return;
}

template <class T>
T dup(T a, T b) {
	assert(b != 0);
	return (a + b - 1) / b;
}

template <class T>
T greatest_lower_multiple(T x, T d) {
	if(d == 0) return 0;
	if(d < 0) d *= -1;
	T y = x % d;
	if(y < 0) y += d;
	return x - y;
}

template <class T>
T least_upper_multiple(T x, T d) {
	return -greatest_lower_multiple(-x, d);
}

long long POW(long long a, long long n) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

long long modpow(long long a, long long n, long long mod) {	 // a^n mod
	assert(n >= 0);
	if(mod == 1) return 0LL;
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return (res < 0 ? res + mod : res);
}

// return x such that a * x % mod == gcd(a, mod)
// not (mod divides a)
long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
}

// normal binomial coefficient
vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {
	assert(n < 100 && k < 100);
	if(n < k || k < 0 || n < 0) return 0;
	if(comb[n][k] != -1) return comb[n][k];
	ll res;
	if(n - k < k)
		res = com(n, n - k);
	else if(k == 0)
		res = 1;
	else
		res = com(n - 1, k - 1) + com(n - 1, k);
	comb[n][k] = res;
	return res;
}

const int MAX = 5100000;  // 300ms, when MAX = 3*10^7 : 1900ms
long long fac[MAX], finv[MAX], inv[MAX];

void cominit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long commod(long long n, long long k) {
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
long long pmod(long long n, long long k) {
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
// nk
long long hmod(long long n, long long k) {	// 
	return commod(n + k - 1, n);
}

template <class T>
int lb(const std::vector<T> &a, const T x) {
	return std::distance(a.begin(), std::lower_bound(a.begin(), a.end(), x));
}
template <class T>
int ub(const std::vector<T> &a, const T x) {
	return std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), x));
}
template <class T>
void unq_sort(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<int> press(std::vector<T> &a) {
	auto vec = a;
	unq_sort(vec);
	std::vector<int> ret;
	for(auto &v : a) ret.push_back(lb(vec, v));
	return ret;
}

#pragma endregion

#pragma region input
#define VEC(type, name, size) \
	vector<type> name(size);  \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                     \
	vector<vector<type>> name(h, vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHR(...)      \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DBL(...)        \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)

namespace scanner {
template <class T>
void scan(T &a) {
	cin >> a;
}
template <class T>
void scan(vector<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
#pragma endregion

#pragma region debug

#pragma region output
template <typename T1, typename T2>
std::ostream &std::operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &std::operator<<(std::ostream &os, const std::vector<T> &v) {
	for(int i = 0; i < (int)v.size(); i++) {
		if(i) os << " ";
		os << v[i];
	}
	return os;
}
#pragma endregion

#pragma region view

namespace viewer {
template <typename T>
void view(const T e) {
	std::cerr << e;
}

template <typename T, typename U>
void view(const std::pair<T, U> &p) {
	std::cerr << "(";
	view(p.first);
	std::cerr << ", ";
	view(p.second);
	std::cerr << ")";
}

template <typename T>
void view(const std::set<T> &s) {
	if(s.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::unordered_set<T> &s) {
	if(s.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::vector<T> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(const auto &e : v) {
		view(e);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	std::cerr << "{\n";
	for(const auto &v : vv) {
		std::cerr << "\t";
		view(v);
		std::cerr << '\n';
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	std::cerr << "{\n";
	for(const auto &c : v) {
		std::cerr << "\t(";
		view(c.first);
		std::cerr << ", ";
		view(c.second);
		std::cerr << ")\n";
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &t : m) {
		std::cerr << "\t[";
		view(t.first);
		std::cerr << "] : ";
		view(t.second);
		std::cerr << '\n';
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::unordered_map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &t : m) {
		std::cerr << "\t[";
		view(t.first);
		std::cerr << "] : ";
		view(t.second);
		std::cerr << '\n';
	}
	std::cerr << "}";
}
}  // namespace viewer

#pragma endregion

// when debugging : g++ foo.cpp -DLOCAL
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	viewer::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(0)
#define dump(x)                                      \
	do {                                             \
		std::cerr << __LINE__ << " " << #x << " : "; \
		view(x);                                     \
		std::cerr << '\n';                           \
	} while(0)

#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#pragma endregion

#pragma region graph

struct Edge {
	int to;
	long long cost;
	Edge() = default;
	Edge(int to_, long long cost_) : to(to_), cost(cost_) {}
	bool operator<(const Edge &a) const { return cost < a.cost; }
	bool operator>(const Edge &a) const { return cost > a.cost; }
	friend std::ostream &operator<<(std::ostream &s, Edge &a) {
		s << "to: " << a.to << ", cost: " << a.cost;
		return s;
	}
};

class Graph {
	std::vector<std::vector<Edge>> edges;

   public:
	inline const std::vector<Edge> &operator[](int k) const { return edges[k]; }
	inline std::vector<Edge> &operator[](int k) { return edges[k]; }

	int size() const { return edges.size(); }
	void resize(const int n) { edges.resize(n); }

	Graph() = default;
	Graph(int n) : edges(n) {}
	Graph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) : edges(n) { input(e, weight, directed, idx); }
	const long long INF = 3e18;

	void input(int e = -1, bool weight = 0, bool directed = false, int idx = 1) {
		if(e == -1) e = size() - 1;
		while(e--) {
			int u, v;
			long long cost = 1;
			std::cin >> u >> v;
			if(weight) std::cin >> cost;
			u -= idx, v -= idx;
			edges[u].emplace_back(v, cost);
			if(!directed) edges[v].emplace_back(u, cost);
		}
	}

	void add_edge(int u, int v, long long cost = 1, bool directed = false, int idx = 0) {
		u -= idx, v -= idx;
		edges[u].emplace_back(v, cost);
		if(!directed) edges[v].emplace_back(u, cost);
	}

	// (V+E)
	std::vector<long long> bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::queue<int> que;
		dist[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			for(auto &e : edges[v]) {
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[v] + e.cost;
				que.push(e.to);
			}
		}
		return dist;
	}

	// (V+E)
	// constraint: cost of each edge is zero or one
	std::vector<long long> zero_one_bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::deque<int> deq;
		dist[s] = 0;
		deq.push_back(s);
		while(!deq.empty()) {
			int v = deq.front();
			deq.pop_front();
			for(auto &e : edges[v]) {
				assert(0LL <= e.cost && e.cost < 2LL);
				if(e.cost && dist[e.to] > dist[v] + 1) {
					dist[e.to] = dist[v] + 1;
					deq.push_back(e.to);
				} else if(!e.cost && dist[e.to] > dist[v]) {
					dist[v] = dist[e.to];
					deq.push_front(e.to);
				}
			}
		}
		return dist;
	}

	// ((E+V)logV)
	// cannot reach: INF
	std::vector<long long> dijkstra(int s) {  // verified
		std::vector<long long> dist(size(), INF);
		const auto compare = [](const std::pair<long long, int> &a, const std::pair<long long, int> &b) { return a.first > b.first; };
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, decltype(compare)> que{compare};
		dist[s] = 0;
		que.emplace(0, s);
		while(!que.empty()) {
			std::pair<long long, int> p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(auto &e : edges[v]) {
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.emplace(dist[e.to], e.to);
				}
			}
		}
		return dist;
	}

	// (VE)
	// cannot reach: INF
	// negative cycle: -INF
	std::vector<long long> bellman_ford(int s) {  // verified
		int n = size();
		std::vector<long long> res(n, INF);
		res[s] = 0;
		for(int loop = 0; loop < n - 1; loop++) {
			for(int v = 0; v < n; v++) {
				if(res[v] == INF) continue;
				for(auto &e : edges[v]) {
					res[e.to] = std::min(res[e.to], res[v] + e.cost);
				}
			}
		}
		std::queue<int> que;
		std::vector<int> chk(n);
		for(int v = 0; v < n; v++) {
			if(res[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(res[e.to] > res[v] + e.cost && !chk[e.to]) {
					que.push(e.to);
					chk[e.to] = 1;
				}
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					que.push(e.to);
				}
			}
		}
		for(int i = 0; i < n; i++)
			if(chk[i]) res[i] = -INF;
		return res;
	}

	// (V^3)
	std::vector<std::vector<long long>> warshall_floyd() {	// verified
		int n = size();
		std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
		for(int i = 0; i < n; i++) dist[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to], e.cost);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++) {
				if(dist[i][k] == INF) continue;
				for(int j = 0; j < n; j++) {
					if(dist[k][j] == INF) continue;
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		return dist;
	}

	// (V) (using DFS)
	// if a directed cycle exists, return {}
	std::vector<int> topological_sort() {  // verified
		std::vector<int> res;
		int n = size();
		std::vector<int> used(n, 0);
		bool not_DAG = false;
		auto dfs = [&](auto self, int k) -> void {
			if(not_DAG) return;
			if(used[k]) {
				if(used[k] == 1) not_DAG = true;
				return;
			}
			used[k] = 1;
			for(auto &e : edges[k]) self(self, e.to);
			used[k] = 2;
			res.push_back(k);
		};
		for(int i = 0; i < n; i++) dfs(dfs, i);
		if(not_DAG) return std::vector<int>{};
		std::reverse(res.begin(), res.end());
		return res;
	}

	bool is_DAG() { return !topological_sort().empty(); }  // verified

	// (V)
	// array of the distance from each vertex to the most distant vertex
	std::vector<long long> height() {  // verified
		auto vec1 = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v1 = i;
		vec1 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v2 = i;
		auto vec2 = bfs(v2);
		for(int i = 0; i < int(size()); i++) {
			if(vec1[i] < vec2[i]) vec1[i] = vec2[i];
		}
		return vec1;
	}

	// O(V+E)
	// vector<(int)(0 or 1)>
	// if it is not bipartite, return {}
	std::vector<int> bipartite_grouping() {
		std::vector<int> colors(size(), -1);
		auto dfs = [&](auto self, int now, int col) -> bool {
			colors[now] = col;
			for(auto &e : edges[now]) {
				if(col == colors[e.to]) return false;
				if(colors[e.to] == -1 && !self(self, e.to, !col)) return false;
			}
			return true;
		};
		for(int i = 0; i < int(size()); i++)
			if(!colors[i] && !dfs(dfs, i, 0)) return std::vector<int>{};
		return colors;
	}

	bool is_bipartite() { return !bipartite_grouping().empty(); }

	// (V+E)
	// ((v1, v2), diameter)
	std::pair<std::pair<int, int>, long long> diameter() {	// verified
		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v1 = i;
		vec = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v2 = i;
		std::pair<std::pair<int, int>, long long> res = {{v1, v2}, dia};
		return res;
	}

	// (ElogV)
	long long prim() {	// verified
		long long res = 0;
		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> que;
		for(auto &e : edges[0]) que.push(e);
		std::vector<int> chk(size());
		chk[0] = 1;
		int cnt = 1;
		while(cnt < size()) {
			auto e = que.top();
			que.pop();
			if(chk[e.to]) continue;
			cnt++;
			res += e.cost;
			chk[e.to] = 1;
			for(auto &e2 : edges[e.to]) que.push(e2);
		}
		return res;
	}

	// (ElogE)
	long long kruskal() {  // verified
		std::vector<std::tuple<int, int, long long>> Edges;
		for(int i = 0; i < int(size()); i++)
			for(auto &e : edges[i]) Edges.emplace_back(i, e.to, e.cost);
		std::sort(Edges.begin(), Edges.end(), [](const std::tuple<int, int, long long> &a, const std::tuple<int, int, long long> &b) {
			return std::get<2>(a) < std::get<2>(b);
		});
		std::vector<int> uf_data(size(), -1);
		auto root = [&uf_data](auto self, int x) -> int {
			if(uf_data[x] < 0) return x;
			return uf_data[x] = self(self, uf_data[x]);
		};
		auto unite = [&uf_data, &root](int u, int v) -> bool {
			u = root(root, u), v = root(root, v);
			if(u == v) return false;
			if(uf_data[u] > uf_data[v]) std::swap(u, v);
			uf_data[u] += uf_data[v];
			uf_data[v] = u;
			return true;
		};
		long long ret = 0;
		for(auto &e : Edges)
			if(unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);
		return ret;
	}

	// O(V)
	std::vector<int> centroid() {
		int n = size();
		std::vector<int> centroid, sz(n);
		auto dfs = [&](auto self, int now, int per) -> void {
			sz[now] = 1;
			bool is_centroid = true;
			for(auto &e : edges[now]) {
				if(e.to != per) {
					self(self, e.to, now);
					sz[now] += sz[e.to];
					if(sz[e.to] > n / 2) is_centroid = false;
				}
			}
			if(n - sz[now] > n / 2) is_centroid = false;
			if(is_centroid) centroid.push_back(now);
		};
		dfs(dfs, 0, -1);
		return centroid;
	}

	// O(V+E)
	// bridge: (s, t)  (s < t);
	std::pair<std::vector<std::pair<int, int>>, std::vector<int>> bridges_and_articulations() {	 // verified
		std::vector<int> order(size(), -1), low(size()), articulation;
		int order_next = 0;
		std::vector<std::pair<int, int>> bridge;
		auto dfs = [&](auto self, int now, int par = -1) -> void {
			low[now] = order[now] = order_next++;
			bool is_articulation = false;
			int cnt = 0, cnt_par = 0;
			for(auto &ed : edges[now]) {
				int &nxt = ed.to;
				if(order[nxt] == -1) {
					cnt++;
					self(self, nxt, now);
					if(order[now] < low[nxt]) bridge.push_back(std::minmax(now, nxt));
					if(order[now] <= low[nxt]) is_articulation = true;
					low[now] = std::min(low[now], low[nxt]);
				} else if(nxt != par || cnt_par++ == 1) {
					low[now] = std::min(low[now], order[nxt]);
				}
			}
			if(par == -1 && cnt < 2) is_articulation = false;
			if(is_articulation) articulation.push_back(now);
			return;
		};
		for(int i = 0; i < (int)size(); i++)
			if(order[i] == -1) dfs(dfs, i);
		return std::make_pair(bridge, articulation);
	}

	// (V+E)
	// directed graph from root to leaf
	Graph root_to_leaf(int root = 0) {
		Graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(now, e.to, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	// (V+E)
	// directed graph from leaf to root
	Graph leaf_to_root(int root = 0) {
		Graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(e.to, now, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	// long long Chu_Liu_Edmonds(int root = 0) {}
};

struct tree_doubling {
   private:
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;
	std::vector<long long> dist;
	int max_jump = 1;

	void build() {
		for(int i = 0; i < max_jump - 1; i++) {
			for(int v = 0; v < (int)dist.size(); v++) {
				if(parent[i][v] == -1)
					parent[i + 1][v] = -1;
				else
					parent[i + 1][v] = parent[i][parent[i][v]];
			}
		}
	}

   public:
	tree_doubling() = default;
	tree_doubling(const Graph &g, const int root = 0) : dist(g.size()), depth(g.size()) {
		int n = g.size();
		while((1 << max_jump) < n) max_jump++;
		parent.assign(max_jump, std::vector<int>(n, -1));
		auto dfs = [&](auto self, int now, int per, int d, long long cost) -> void {
			parent[0][now] = per;
			depth[now] = d;
			dist[now] = cost;
			for(auto &e : g[now])
				if(e.to != per) self(self, e.to, now, d + 1, cost + e.cost);
		};
		dfs(dfs, root, -1, 0, 0LL);
		build();
	}

	int lowest_common_ancestor(int u, int v) {
		if(depth[u] < depth[v]) std::swap(u, v);
		int k = parent.size();
		for(int i = 0; i < k; i++)
			if((depth[u] - depth[v]) >> i & 1) u = parent[i][u];
		if(u == v) return u;
		for(int i = k - 1; i >= 0; i--)
			if(parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v];
		return parent[0][u];
	}

	long long length_of_path(const int u, const int v) { return dist[u] + dist[v] - dist[lowest_common_ancestor(u, v)] * 2; }

	int level_ancestor(int v, int level) {
		assert(level >= 0);
		for(int jump = 0; jump < max_jump && level; jump++) {
			if(level & 1) v = parent[jump][v];
			level >>= 1;
		}
		return v;
	}
};

struct strongly_connected_components {
   private:
	enum { CHECKED = -1, UNCHECKED = -2 };
	const Graph &graph_given;
	Graph graph_reversed;
	std::vector<int> order, group_number; /* at the beginning of the building, 'group_number' is used as 'checked' */

	void dfs(int now) {
		if(group_number[now] != UNCHECKED) return;
		group_number[now] = CHECKED;
		for(auto &e : graph_given[now]) dfs(e.to);
		order.push_back(now);
	}

	void rdfs(int now, int group_count) {
		if(group_number[now] != UNCHECKED) return;
		group_number[now] = group_count;
		for(auto &e : graph_reversed[now]) rdfs(e.to, group_count);
	}

	void build(bool create_compressed_graph) {
		for(int i = 0; i < (int)graph_given.size(); i++) dfs(i);
		reverse(order.begin(), order.end());
		group_number.assign(graph_given.size(), UNCHECKED);
		int group = 0;
		for(auto &i : order)
			if(group_number[i] == UNCHECKED) rdfs(i, group), group++;
		graph_compressed.resize(group);
		groups.resize(group);
		for(int i = 0; i < (int)graph_given.size(); i++) groups[group_number[i]].push_back(i);
		if(create_compressed_graph) {
			std::vector<int> edges(group, -1);
			for(int i = 0; i < group; i++)
				for(auto &vertex : groups[i])
					for(auto &e : graph_given[vertex])
						if(group_number[e.to] != i && edges[group_number[e.to]] != i) {
							edges[group_number[e.to]] = i;
							graph_compressed[i].emplace_back(group_number[e.to], 1);
						}
		}
		return;
	}

   public:
	std::vector<std::vector<int>> groups;
	Graph graph_compressed;

	strongly_connected_components(const Graph &g_, bool create_compressed_graph = false)
		: graph_given(g_), graph_reversed(g_.size()), group_number(g_.size(), UNCHECKED) {
		for(size_t i = 0; i < g_.size(); i++)
			for(auto &e : graph_given[i]) graph_reversed[e.to].emplace_back(i, 1);
		build(create_compressed_graph);
	}

	const int &operator[](const int k) { return group_number[k]; }
};

struct heavy_light_decomposition {
   public:
	std::vector<int> sz, in, out, head, rev, par;

   private:
	Graph &g;

	void dfs_sz(int v, int p = -1) {
		par[v] = p;
		if(!g[v].empty() && g[v].front().to == p) std::swap(g[v].front(), g[v].back());
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			dfs_sz(e.to, v);
			sz[v] += sz[e.to];
			if(sz[g[v].front().to] < sz[e.to]) std::swap(g[v].front(), e);
		}
	}

	void dfs_hld(int v, int &t, int p = -1) {
		in[v] = t++;
		rev[in[v]] = v;
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			head[e.to] = (g[v].front().to == e.to ? head[v] : e.to);
			dfs_hld(e.to, t, v);
		}
		out[v] = t;
	}

	void build(int root = 0) {
		dfs_sz(root);
		int t = 0;
		head[root] = root;
		dfs_hld(root, t);
	}

   public:
	heavy_light_decomposition(Graph &g_, int root = 0) : g(g_) {
		int n = g.size();
		sz.resize(n, 1);
		in.resize(n);
		out.resize(n);
		head.resize(n);
		rev.resize(n);
		par.resize(n);
		build(root);
	}

	int level_ancestor(int v, int level) {
		while(true) {
			int u = head[v];
			if(in[v] - level >= in[u]) return rev[in[v] - level];
			level -= in[v] - in[u] + 1;
			v = par[u];
		}
	}

	int lowest_common_ancestor(int u, int v) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) return u;
		}
	}

	// u, v: vertex, unit: unit, q: query on a path, f: binary operation ((T, T) -> T)
	template <typename T, typename Q, typename F>
	T query(int u, int v, const T &unit, const Q &q, const F &f, bool edge = false) {
		T l = unit, r = unit;
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v), std::swap(l, r);
			if(head[u] == head[v]) break;
			l = f(q(in[head[v]], in[v] + 1), l);
		}
		return f(f(q(in[u] + edge, in[v] + 1), l), r);
	}

	// u,v: q:
	template <typename Q>
	void add(int u, int v, const Q &q, bool edge = false) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) break;
			q(in[head[v]], in[v] + 1);
		}
		q(in[u] + edge, in[v] + 1);
	}

	std::pair<int, int> subtree(int v, bool edge = false) { return std::pair<int, int>(in[v] + edge, out[v]); }
};

#pragma endregion

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(15);
	srand((unsigned)time(NULL));

	int n;
	cin >> n;
	VEC(int, a, n);

	if(n == 1) {
		drop(a[0]);
	}

	int one = 0;
	foa(t, a) if(t == 1) one++;

	if(one == 0) {
		vout(a, 0);
		exit(0);
	}

	if(one == 1) {
		rep(i, n) { a[i] = 2; }
		a[1] = 1;
		vout(a);
		exit(0);
	}

	if(one == n) {
		vout(a);
		return 0;
	}

	a.clear();
	// a[0] = 2, a[1] = 1;
	a.push_back(2), a.push_back(1);
	rep(n - one - 1) { a.push_back(2); }
	while(a.size() < n) a.push_back(1);
	vout(a);

	return 0;
}