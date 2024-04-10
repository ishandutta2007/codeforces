/*	author:  Kite_kuma
	created: 2020.11.18 00:24:13 */

// #ifdef LOCAL
// #define _GLIBCXX_DEBUG
// #endif
#include <bits/stdc++.h>
using namespace std;

#pragma region aliases

#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl

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
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using qll = queue<long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
template <class T = ll>
using V = vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
//pq()
template <class T = ll>
using pqup = priority_queue<T, vector<T>, greater<T>>;
//pq()
template <class T = ll>
using pqdn = priority_queue<T>;

#pragma endregion

#pragma region constants

long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
long long const dekai = 3e16;
const long double pi = acos(-1);
const char dl = '\n';
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

const int mod = 1000000007;
// const int mod = 998244353;

#pragma endregion

#pragma region basic_procedure

template <class T>
inline bool isin(T x, T lef, T rig) {
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

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << "\n"; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << "\n"; }
void NO() { cout << "NO\n"; }
template <class T>
void drop(T answer) {
	cout << answer << "\n";
	exit(0);
}
void err() {
	cout << -1 << "\n";
	exit(0);
}

template <class T>
void vout(vector<T> &v, bool tate = 0) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) {
				if(tate)
					cout << endl;
				else
					cout << " ";
			}
		}
	}
	cout << endl;
}

inline void print() {
	cout << '\n';
	return;
}

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
void add(vector<T> &v, T val) {	 //
	for(auto &a : v) a += val;
	return;
}

// vector map<,>
template <class T>
map<T, long long> cntv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}

//
//{1,36,1,3,8,-2,-92}
//{2, 5,2,3,4, 1,  0}
template <class T>
vector<long long> press(vector<T> &v) {
	long long n = v.size();
	vector<long long> w(n);
	map<T, long long> m;
	for(T &p : v) m[p] = 0;
	long long i = 0;
	for(auto &p : m) {
		p.second = i;
		i++;
	}
	for(long long i = 0; i < n; i++) w.at(i) = m[v.at(i)];
	return w;
}

// 
template <class T>
T dup(T a, T b) {
	assert(b != 0);
	T x = abs(a);
	T y = abs(b);
	T z = (x + y - 1) / y;
	if((a < 0 && b > 0) || (a > 0 && b < 0))
		return -z;
	else if(a == 0)
		return 0;
	else
		return z;
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
	return res;
}

// a * x % mod == __gcd(a,mod)x
// a  mod
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

vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {  //(overflow)
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

// nCk mod
const int MAX = 5100000;
// 
// MAX=3*10^71900ms
// MAX=5*10^6(300ms)
long long fac[MAX], finv[MAX], inv[MAX];

void cominit() {
	// 
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long commod(long long n, long long k) {  // 
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
long long pmod(long long n, long long k) {	// 
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
// nk
long long hmod(long long n, long long k) {	// 
	return commod(n + k - 1, n);
}
#pragma endregion

#pragma region input
#define VEC(type, name, size) \
	vector<type> name(size);  \
	INPUT(name)
#define VVEC(type, name, h, w)                     \
	vector<vector<type>> name(h, vector<type>(w)); \
	INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	INPUT(__VA_ARGS__)

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
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}

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
		std::cerr << "\n";
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
		std::cerr << "\n";
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
		std::cerr << "\n";
	}
	std::cerr << "}";
}

#pragma endregion

// when debugging : g++ foo.cpp -DLOCAL
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	view(H);
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
		std::cerr << "\n";                           \
	} while(0)

#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#pragma endregion
#pragma region graph_structure

template <class T = long long>
struct edge {
	T len;
	int from;
	int to;
	bool operator<(const edge a) const {
		if(len != a.len) return len < a.len;
		if(from != a.from) return from < a.from;
		return to < a.to;
	}
	bool operator>(const edge a) const {
		if(len != a.len) return len > a.len;
		if(from != a.from) return from > a.from;
		return to > a.to;
	}
};
template <class T = long long>
struct graph {	// 0-indexed
	T const INF = numeric_limits<T>::max() / 3;
	vector<vector<edge<T>>> edges;
	int ver;

	// constructor
	graph() = default;
	graph(int vertex) : ver(vertex), edges(vertex) {}

	// (0-indexed)
	void update(int from, int to, T len = 1, bool direction = 1) {	// checked
		edge<T> e;
		e.len = len;
		e.from = from;
		e.to = to;
		edges[from].push_back(e);
		if(!direction) {
			swap(e.to, e.from);
			edges[to].push_back(e);
		}
	}

	// (1-indexed)
	void input(int edge_num, bool direction = false, bool weight = false, int index = 1) {	// checked
		for(int i = 0; i < edge_num; i++) {
			int a;
			int b;
			cin >> a >> b;
			a -= index;
			b -= index;
			T c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, direction);
		}
	}

	// 1 (INF)
	vector<T> bfs(int start) {	// checked
		// https://atcoder.jp/contests/abc007/submissions/me
		vector<T> ret(ver, INF);
		queue<int> q;
		q.push(start);
		ret[start] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(ret[e.to] != INF) continue;
				q.push(e.to);
				ret[e.to] = ret[now] + 1;
			}
		}
		return ret;
	}

	//path<vll> O((ver)log(ver)+(edge))
	vector<T> dijkstra(int start) {	 // checked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_1_A/judge/4817136/C++14
		vector<T> ret(ver, (T)INF);													  //{dist,place}
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> p;  //{dist,place}
		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			int place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				int nextplace = next.to;
				T dis = next.len;
				if(ret[nextplace] > dist + dis) {
					ret[nextplace] = dist + dis;
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	// O((ver)*(edge))
	// ret[i] = INF;
	// ret[i] = -INF;
	vector<T> BellmanFord(int start) {	// checked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_1_B/judge/4817139/C++14
		vector<T> ret(ver, INF);
		ret[start] = 0;
		for(int loop = 0; loop < ver - 1; loop++) {
			for(int v = 0; v < ver; v++) {
				if(ret[v] == INF) continue;
				for(auto &e : edges[v]) {
					ret[e.to] = min(ret[e.to], ret[v] + e.len);
				}
			}
		}

		//
		queue<int> q;
		vector<bool> chk(ver, 0);
		for(int v = 0; v < ver; v++) {
			if(ret[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(ret[e.to] > ret[v] + e.len) {
					ret[e.to] = ret[v] + e.len;
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		for(int i = 0; i < ver; i++)
			if(chk[i]) ret[i] = -INF;

		return ret;
	}

	//
	//ver
	vector<int> topo_sort() {  // checked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_4_B/judge/4817106/C++14
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_4_A/judge/4817110/C++14
		vector<int> num_input(ver);
		// 
		for(int i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		// 0queue
		queue<int> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<int> ans;
		while(!que.empty()) {
			auto node = que.front();
			que.pop();
			ans.push_back(node);
			// 
			for(auto e : edges[node]) {
				num_input[e.to]--;
				// 0queue
				if(num_input[e.to] == 0) {
					que.push(e.to);
				}
			}
		}
		return ans;
	}

	//{{},}
	pair<pair<int, int>, T> DiameterOfTree(bool weigh = true) {	 // chkecked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_5_A/judge/4817099/C++14
		vector<T> vec;
		vec = weigh ? dijkstra(0) : bfs(0);
		int v1 = -1;
		T dia = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				dia = vec[i];
				v1 = i;
			}

		vec = weigh ? dijkstra(v1) : bfs(v1);
		dia = -1;
		int v2 = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				v2 = i;
				dia = vec[i];
			}

		pair<pair<int, int>, T> ans = {{v1, v2}, dia};
		return ans;
	}

	//
	graph<T> RootToLeaf(int root) {	 // 0-indexed
		graph<T> ret(ver);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(now, e.to, e.len);
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//
	graph<T> LeafToRoot(int root) {	 // 0-indexed
		graph<T> ret(ver);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(e.to, now, e.len);
				dfs(e.to);
			}
		};
		dfs(root);
		ret.update(root, root, 0);
		return ret;
	}

	// LeafToRootvector.par[i]=i
	vector<int> par(int root) {	 // 0-indexed
		vector<int> ret(ver, -1);
		ret[root] = root;  // rootroot
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	vector<edge<T>> ParentAndDistance(int root) {  // 0-indexed
		vector<edge<T>> ret(ver);
		for(int i = 0; i < ver; i++) ret[i].to = -1;
		ret[root].to = root;  // rootroot
		ret[root].len = 0;	  // root0
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to].to != -1) continue;
				ret[e.to].to = now;
				ret[e.to].len = e.len;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//sheet.warshall
	vector<vector<T>> GraphArray(void) {  // chkecked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_1_C/judge/4817090/C++14
		vector<vector<T>> ret(ver, vector<T>(ver, INF));
		for(int from = 0; from < ver; from++) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}

	graph<T> Prim(bool direction = 0, int start = 0) {	// checked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_2_A/judge/4817129/C++14
		graph<T> ret(ver);
		priority_queue<edge<T>, vector<edge<T>>, greater<edge<T>>> p;
		for(auto &e : edges[start]) {
			p.push(e);
		}
		vector<bool> chk(ver, 0);
		chk[start] = 1;
		while(!p.empty()) {
			auto ed = p.top();
			p.pop();
			if(chk[ed.to]) continue;
			chk[ed.to] = 1;
			ret.update(ed.from, ed.to, ed.len, direction);
			for(auto &e : edges[ed.to]) {
				p.push(e);
			}
		}
		return ret;
	}

	//
	vector<T> height(int start = 0) {  // checked
		// https://onlinejudge.u-aizu.ac.jp/status/users/Kite_kuma/submissions/1/GRL_5_B/judge/4817082/C++14
		vector<T> fir(ver, -1), sec(ver, -1);
		function<T(int, int)> dfs = [&](int now, int par) {
			T f = 0, s = 0;	 // startnow12
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				s = max(s, dfs(e.to, now) + e.len);
				if(f < s) swap(f, s);
			}
			sec[now] = s;
			return fir[now] = f;
		};
		dfs(start, -1);
		function<void(int, int, T, T, T)> sol = [&](int now, int par, T parf, T pars, T parlen) {
			if(fir[now] + parlen == parf) parf = pars;
			sec[now] = max(sec[now], parf + parlen);
			if(fir[now] < sec[now]) swap(fir[now], sec[now]);
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				sol(e.to, now, fir[now], sec[now], e.len);
			}
			return;
		};
		sol(start, -1, -1, -1, -1);
		return fir;
	}

	//DP
	//
	// std::function
	template <class U>
	vector<U> ReRootingDP(U &unit, function<U(U, U)> &merge, function<U(int, U, T)> &send, int root = 0) {
		auto tr = RootToLeaf(root);
		vector<vector<U>> v(ver);
		vector<U> ret(ver);	 //

		function<U(int)> treeDP = [&](int now) {
			U res = unit;
			vector<U> vec;
			for(auto &e : tr.edges[now]) {
				U u = send(e.to, treeDP(e.to), e.len);
				v[now].push_back(u);
				res = merge(res, u);
			}
			return res;
		};
		treeDP(root);

		function<void(int, U, int, T)> rerooting = [&](int now, U ans_par, int par, T len) {
			if(now != root) ans_par = send(par, ans_par, len);
			int sz = v[now].size();
			vector<U> data_front(sz + 1), data_back(sz + 1);
			data_front[0] = data_back[sz] = unit;
			for(int i = 0; i < sz; i++) {
				data_front[i + 1] = merge(data_front[i], v[now][i]);
				data_back[sz - i - 1] = merge(v[now][sz - i - 1], data_back[sz - i]);
			}
			for(int i = 0; i < sz; i++) {
				auto nxtans = merge(ans_par, merge(data_front[i], data_back[i + 1]));
				rerooting(tr.edges[now][i].to, nxtans, now, tr.edges[now][i].len);
			}
			ret[now] = merge(ans_par, data_front[sz]);
			return;
		};
		rerooting(root, unit, root, 0);

		return ret;
	}

	// HL
};

#pragma endregion

void c(graph<> &g, int n, int m, int k) {
	if((ll)k * ((ll)(k - 1) / 2) > m) {
		cout << -1 << dl;
		return;
	}
	set<pair<int, int>> se;

	rep(i, n) { se.emplace(g.edges[i].size(), i); }

	vi ed(n);
	rep(i, n) ed[i] = g.edges[i].size();

	auto it = se.begin();
	int tp = -1;
	while(!se.empty()) {
		it = se.begin();
		if(it->first >= k - 1) {
			tp = 2;
			break;
		} else {
			int now = it->second;
			foa(e, g.edges[now]) {
				if(ed[e.to] == -1) continue;
				se.erase(make_pair(ed[e.to], e.to));
				ed[e.to]--;
				se.emplace(ed[e.to], e.to);
			}
			ed[now] = -1;
			se.erase(it);
		}
	}

	if(tp < 0) {
		cout << -1 << dl;
		return;
	}

	// set<pair<int, int>> edge;
	unordered_set<ll> edge;
	rep(i, n) foa(e, g.edges[i]) {
		edge.insert(e.from * (ll)n + e.to);
		edge.insert(e.to * (ll)n + e.from);
	}

	vi v;

	while(!se.empty()) {
		it = se.begin();

		int now = it->second;

		v.clear();
		v.push_back(now);
		bool flag = true;
		if(it->first < k - 1) {
			flag = 0;
			goto sk;
		}
		foa(e, g.edges[now]) {
			if(ed[e.to] == -1) continue;
			foa(t, v) {
				if(!edge.count((ll)t * (ll)n + e.to)) {
					flag = false;
					goto sk;
				}
			}
			v.push_back(e.to);
		}
	sk:;
		if(flag) {
			cout << 2 << dl;
			add(v, 1);
			vout(v, 0);
			return;
		}

		now = it->second;
		foa(e, g.edges[now]) {
			if(ed[e.to] == -1) continue;
			se.erase(make_pair(ed[e.to], e.to));
			ed[e.to]--;
			se.emplace(ed[e.to], e.to);
		}
		ed[it->second] = -1;
		se.erase(it);
	}

	cout << -1 << dl;
	return;
}

void sol() {
	INT(n, m, k);
	graph<> g(n);
	g.input(m);

	set<pair<int, int>> se;

	rep(i, n) { se.emplace(g.edges[i].size(), i); }

	vi ed(n);
	rep(i, n) ed[i] = g.edges[i].size();

	auto it = se.begin();
	int tp = -1;
	while(!se.empty()) {
		it = se.begin();
		if(it->first >= k) {
			tp = 1;
			break;
		} else {
			int now = it->second;
			foa(e, g.edges[now]) {
				if(ed[e.to] == -1) continue;
				se.erase(make_pair(ed[e.to], e.to));
				ed[e.to]--;
				se.emplace(ed[e.to], e.to);
			}
			ed[it->second] = -1;
			se.erase(it);
			continue;
		}
	}

	if(tp == -1) {
		c(g, n, m, k);
		return;
	}

	// cout << tp << dl;

	cout << tp << " " << se.size() << dl;

	vi ans;
	foa(t, se) ans.push_back(t.second + 1);
	vout(ans, 0);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(15);
	srand((unsigned)time(NULL));

	INT(t);
	while(t--) sol();

	return 0;
}