/*	author:  Kite_kuma
	created: 2021.04.04 00:30:27 */

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
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vvvi = std::vector<std::vector<std::vector<int>>>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
template <class T = ll>
using V = std::vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
template <class T = ll>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T = ll>
using pqdn = std::priority_queue<T>;

#pragma endregion

#pragma region constants

const int inf = 1e9;
const long long INF = 1e18;
const long double pi = acos(-1);
const char dl = '\n';
const char sp = ' ';
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int mod_1000000007 = 1000000007;
const int mod_998244353 = 998244353;

#pragma endregion

#pragma region basic_operation

template <class T0, class T1, class T2>
inline bool in_range(T0 x, T1 lef, T2 rig) {
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

void Yes(bool f = 1) { std::cout << (f ? "Yes" : "No") << '\n'; }
void No() { std::cout << "No\n"; }
void YES(bool f = 1) { std::cout << (f ? "YES" : "NO") << '\n'; }
void NO() { std::cout << "NO\n"; }

template <class T>
void drop(T answer) {
	std::cout << answer << '\n';
	exit(0);
}

void err(bool flag = true) {
	if(!flag) return;
	std::cout << -1 << '\n';
	exit(0);
}

template <class T>
void vout(std::vector<T> const &v, bool vertically = 0) {
	if(vertically) {
		for(auto const &a : v) {
			std::cout << a << '\n';
		}
		return;
	}
	for(auto it = v.begin(); it != v.end(); it++) {
		std::cout << (*it);
		if(it != v.end() - 1) {
			std::cout << ' ';
		}
	}
	std::cout << '\n';
	return;
}

inline void print() { std::cout << '\n'; }
template <class T>
inline void print(T x) {
	std::cout << x << '\n';
	return;
}
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
	std::cout << H << " ";
	print(T...);
}

template <class T>
void add(std::vector<T> &v, T val) {
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
	assert(n >= 0 && mod);
	if(mod == 1) return 0LL;
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res < 0 ? res + mod : res;
}

// return x which satisfies a * x % mod == gcd(a, mod)
// not (mod | a)
long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		std::swap(a, b);
		u -= t * v;
		std::swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
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
#define TPL3(type0, type1, type2, name)   \
	std::tuple<type0, type1, type2> name; \
	scanner::INPUT(name);
#define TPL4(type0, type1, type2, type3, name)   \
	std::tuple<type0, type1, type2, type3> name; \
	scanner::INPUT(name);

namespace scanner {
template <class T>
void scan(T &a) {
	std::cin >> a;
}

template <class T, class L>
void scan(std::pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}

template <class T0, class T1, class T2>
void scan(std::tuple<T0, T1, T2> &p) {
	T0 t0;
	T1 t1;
	T2 t2;
	scan(t0);
	scan(t1);
	scan(t2);
	p = std::make_tuple(t0, t1, t2);
}

template <class T0, class T1, class T2, class T3>
void scan(std::tuple<T0, T1, T2, T3> &p) {
	T0 t0;
	T1 t1;
	T2 t2;
	T3 t3;
	scan(t0);
	scan(t1);
	scan(t2);
	scan(t3);
	p = std::make_tuple(t0, t1, t2, t3);
}

template <class T>
void scan(std::vector<T> &a) {
	for(auto &i : a) scan(i);
}

void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner

template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
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
void view(const long long e) {
	if(e == INF)
		std::cerr << "INF";
	else if(e == -INF)
		std::cerr << "-INF";
	else
		std::cerr << e;
}

void view(const int e) {
	if(e == inf)
		std::cerr << "inf";
	else if(e == -inf)
		std::cerr << "-inf";
	else
		std::cerr << e;
}

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

template <class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p) {
	std::cerr << "(";
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ")";
}

template <class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p) {
	std::cerr << "(";
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ", ";
	view(std::get<3>(p));
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

template <class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << '{';
	for(const auto &t : v) {
		std::cerr << "\n\t";
		view(t);
		std::cerr << ",";
	}
	std::cerr << "\n}";
}

template <class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << '{';
	for(const auto &t : v) {
		std::cerr << "\n\t";
		view(t);
		std::cerr << ",";
	}
	std::cerr << "\n}";
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
		viewer::view(x);                             \
		std::cerr << '\n';                           \
	} while(0)

#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#pragma endregion
template <class T = long long>
class ST {
   private:
	int n;
	vector<T> data;
	T unit;
	function<T(T, T)> operation;

   public:
	ST(int _n, function<T(T, T)> _operation, T _unit) : n(_n), operation(_operation), unit(_unit), data(_n * 2, _unit) {
		for(int i = n - 1; i > -1; i--) data[i] = operation(data[i << 1], data[i << 1 | 1]);
	}
	ST(int _n, function<T(T, T)> _operation, T _unit, vector<T> raw_data) : n(_n), operation(_operation), unit(_unit), data(_n * 2, unit) {
		for(int i = 0; i < n; i++) data[i + n] = raw_data[i];
		for(int i = n - 1; i > -1; i--) data[i] = operation(data[i << 1], data[i << 1 | 1]);
	}
	ST(int _n, function<T(T, T)> _operation, T _unit, T _init) : n(_n), operation(_operation), unit(_unit), data(_n * 2, _init) {
		for(int i = n - 1; i > -1; i--) data[i] = operation(data[i << 1], data[i << 1 | 1]);
	}

	void update(int idx, T x) {
		idx += n;
		data[idx] = x;
		idx >>= 1;
		while(idx > 0) {
			data[idx] = operation(data[(idx << 1)], data[(idx << 1) | 1]);
			idx >>= 1;
		}
	}

	void add(int idx, T x) { update(idx, data[idx + n] + x); }

	T get(int lef, int rig) {
		T a = unit, b = unit;
		lef += n;
		rig += n;
		while(lef < rig) {
			if(lef & 1) a = operation(a, data[lef]);
			if(rig & 1) b = operation(data[rig - 1], b);
			(lef += 1) >>= 1;
			rig >>= 1;
		}
		return operation(a, b);
	}

	T get(int idx) { return data[idx + n]; }

	void print() {
#ifdef LOCAL
		cerr << "{";
		for(int i = 0; i < n; i++) {
			cerr << data[i + n] << ", ";
		}
		cerr << "\b\b }\n";
#endif
		return;
	}
};

template <class T>
struct SegmentTreeBeats {
   private:
	size_t n, n_;
	const T MAX = std::numeric_limits<T>::max();
	const T MIN = -MAX;
	std::vector<T> max_v, min_v, smax_v, smin_v, lz_upd, lz_ad, sigm, len;
	std::vector<int> max_c, min_c;

	void init(std::vector<T> &v) {
		n_ = v.size(), n = 1;
		while(n < n_) n *= 2;
		max_v.assign(n * 2 - 1, MIN);
		min_v.assign(n * 2 - 1, MAX);
		smax_v.assign(n * 2 - 1, MIN);
		smin_v.assign(n * 2 - 1, MAX);
		lz_upd.assign(n * 2 - 1, MAX);
		lz_ad.assign(n * 2 - 1, 0);
		len.assign(n * 2 - 1, n);
		sigm.assign(n * 2 - 1, 0);
		max_c.assign(n * 2 - 1, 1);
		min_c.assign(n * 2 - 1, 1);

		for(int i = 0; i < n - 1; i++) len[i * 2 + 1] = len[i * 2 + 2] = (len[i] >> 1);

		for(int i = 0; i < n_; i++) max_v[i + n - 1] = min_v[i + n - 1] = sigm[i + n - 1] = v[i];

		for(int i = n - 2; i >= 0; i--) proc(i);
	}

	void proc(int i) {
		sigm[i] = sigm[i * 2 + 1] + sigm[i * 2 + 2];

		max_v[i] = std::max(max_v[i * 2 + 1], max_v[i * 2 + 2]);

		if(max_v[i * 2 + 1] > max_v[i * 2 + 2]) {
			max_c[i] = max_c[i * 2 + 1];
			smax_v[i] = std::max(smax_v[i * 2 + 1], max_v[i * 2 + 2]);
		}

		if(max_v[i * 2 + 1] < max_v[i * 2 + 2]) {
			max_c[i] = max_c[i * 2 + 2];
			smax_v[i] = std::max(max_v[i * 2 + 1], smax_v[i * 2 + 2]);
		}

		if(max_v[i * 2 + 1] == max_v[i * 2 + 2]) {
			max_c[i] = max_c[i * 2 + 1] + max_c[i * 2 + 2];
			smax_v[i] = std::max(smax_v[i * 2 + 1], smax_v[i * 2 + 2]);
		}

		min_v[i] = std::min(min_v[i * 2 + 1], min_v[i * 2 + 2]);

		if(min_v[i * 2 + 1] < min_v[i * 2 + 2]) {
			min_c[i] = min_c[i * 2 + 1];
			smin_v[i] = std::min(smin_v[i * 2 + 1], min_v[i * 2 + 2]);
		}

		if(min_v[i * 2 + 1] > min_v[i * 2 + 2]) {
			min_c[i] = min_c[i * 2 + 2];
			smin_v[i] = std::min(min_v[i * 2 + 1], smin_v[i * 2 + 2]);
		}

		if(min_v[i * 2 + 1] == min_v[i * 2 + 2]) {
			min_c[i] = min_c[i * 2 + 1] + min_c[i * 2 + 2];
			smin_v[i] = std::min(smin_v[i * 2 + 1], smin_v[i * 2 + 2]);
		}
	}

	void eval(int i) {
		if(lz_upd[i] != MAX) {
			in_update(i * 2 + 1, lz_upd[i]);
			in_update(i * 2 + 2, lz_upd[i]);
			lz_upd[i] = MAX;
			return;
		}

		if(lz_ad[i]) {
			in_add(i * 2 + 1, lz_ad[i]);
			in_add(i * 2 + 2, lz_ad[i]);
			lz_ad[i] = 0;
		}

		if(max_v[i] < max_v[i * 2 + 1]) in_chmin(i * 2 + 1, max_v[i]);
		if(max_v[i] < max_v[i * 2 + 2]) in_chmin(i * 2 + 2, max_v[i]);

		if(min_v[i] > min_v[i * 2 + 1]) in_chmax(i * 2 + 1, min_v[i]);
		if(min_v[i] > min_v[i * 2 + 2]) in_chmax(i * 2 + 2, min_v[i]);
	}

	void in_update(int i, T x) {
		max_v[i] = min_v[i] = x;
		smax_v[i] = MIN, smin_v[i] = MAX;
		max_c[i] = min_c[i] = len[i];
		sigm[i] = len[i] * x;
		lz_upd[i] = x, lz_ad[i] = 0;
	}

	void in_chmin(int i, T x) {
		sigm[i] += (x - max_v[i]) * max_c[i];

		if(max_v[i] == min_v[i])
			max_v[i] = min_v[i] = x;

		else if(max_v[i] == smin_v[i])
			max_v[i] = smin_v[i] = x;

		else
			max_v[i] = x;

		if(lz_upd[i] != MAX and lz_upd[i] > x) lz_upd[i] = x;
	}

	void in_chmax(int i, T x) {
		sigm[i] += (x - min_v[i]) * min_c[i];

		if(min_v[i] == max_v[i])
			min_v[i] = max_v[i] = x;

		else if(min_v[i] == smax_v[i])
			min_v[i] = smax_v[i] = x;

		else
			min_v[i] = x;

		if(lz_upd[i] != MAX and lz_upd[i] < x) lz_upd[i] = x;
	}

	void in_add(int i, T x) {
		max_v[i] += x, min_v[i] += x;

		if(smin_v[i] != MAX) smin_v[i] += x;
		if(smax_v[i] != MIN) smax_v[i] += x;

		sigm[i] += x * len[i];

		if(lz_upd[i] != MAX) lz_upd[i] += x;
		lz_ad[i] += x;
	}

	void chmin(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a or x >= max_v[i]) return;

		if(a <= l and r <= b and smax_v[i] < x) {
			in_chmin(i, x);
			return;
		}

		eval(i);
		chmin(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		chmin(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	void chmax(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a or x <= min_v[i]) return;

		if(a <= l and r <= b and smin_v[i] > x) {
			in_chmax(i, x);
			return;
		}

		eval(i);
		chmax(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		chmax(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	void add(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a) return;

		if(a <= l and r <= b) {
			in_add(i, x);
			return;
		}

		eval(i);
		add(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		add(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	void update(int i, int a, int b, int l, int r, T x) {
		if(b <= l or r <= a) return;

		if(a <= l and r <= b) {
			in_update(i, x);
			return;
		}

		eval(i);
		update(i * 2 + 1, a, b, l, (l + r) >> 1, x);
		update(i * 2 + 2, a, b, (l + r) >> 1, r, x);
		proc(i);
	}

	T sum(int i, int a, int b, int l, int r) {
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return sigm[i];
		eval(i);
		T lv = sum(i * 2 + 1, a, b, l, (l + r) / 2);
		T rv = sum(i * 2 + 2, a, b, (l + r) / 2, r);
		return lv + rv;
	}

	T rangemin(int i, int a, int b, int l, int r) {
		if(r <= a or b <= l) return MAX;

		if(a <= l and r <= b) return min_v[i];

		eval(i);

		T lv = rangemin(i * 2 + 1, a, b, l, (l + r) >> 1);
		T rv = rangemin(i * 2 + 2, a, b, (l + r) >> 1, r);
		return std::min(lv, rv);
	}

	T rangemax(int i, int a, int b, int l, int r) {
		if(r <= a or b <= l) return MIN;

		if(a <= l and r <= b) return max_v[i];

		eval(i);

		T lv = rangemax(i * 2 + 1, a, b, l, (l + r) >> 1);
		T rv = rangemax(i * 2 + 2, a, b, (l + r) >> 1, r);
		return std::max(lv, rv);
	}

	T rangesum(int i, int a, int b, int l, int r) {
		if(r <= a or b <= l) return 0;

		if(a <= l and r <= b) return sigm[i];

		eval(i);

		T lv = rangesum(i * 2 + 1, a, b, l, (l + r) >> 1);
		T rv = rangesum(i * 2 + 2, a, b, (l + r) >> 1, r);
		return lv + rv;
	}

   public:
	SegmentTreeBeats() = default;

	SegmentTreeBeats(std::vector<T> &v) { init(v); }

	SegmentTreeBeats(size_t n, T init_data) {
		std::vector<T> v(n, init_data);
		init(v);
	}

	T operator[](int i) { return query_min(i, i + 1); }

	void update_chmin(int a, int b, T x) { chmin(0, a, b, 0, n, x); }

	void update_chmax(int a, int b, T x) { chmax(0, a, b, 0, n, x); }

	void update_add(int a, int b, T x) { add(0, a, b, 0, n, x); }

	void update_upd(int a, int b, T x) { update(0, a, b, 0, n, x); }

	T query_min(int a, int b) { return rangemin(0, a, b, 0, n); }

	T query_max(int a, int b) { return rangemax(0, a, b, 0, n); }

	T query_sum(int a, int b) { return rangesum(0, a, b, 0, n); }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(15);
	srand((unsigned)time(NULL));

	INT(n);
	V<pair<ll, ll>> ac;
	rep(n) {
		LL(a, c);
		ac.emplace_back(a, c);
	}

	sort(all(ac));

	vll a, c;
	foa(t, ac) {
		ll x, y;
		tie(x, y) = t;
		a.push_back(x);
		c.push_back(y);
	}

	vll data;
	rep(i, n) data.push_back(a[i] + c[i]);

	V<pair<ll, int>> p;
	rep(i, n) p.emplace_back(data[i], i);

	ST<pair<ll, int>> st(
		n, [](pair<ll, int> a, pair<ll, int> b) { return max(a, b); }, pair(-INF, -1), p);

	vll cost(n, INF);
	cost[0] = 0;
	SegmentTreeBeats stb(cost);

	rep(i, n) {
		if(i < n - 1) assert(a[i] <= a[i + 1]);
		// chmin(cost[n - 1], cost[i] + max(0LL, a[n - 1] - data[i]));
		stb.update_chmin(n - 1, n, stb[i] + max(0LL, a[n - 1] - data[i]));

		int it = ub(a, data[i]);
		debug(i, it);
		stb.update_chmin(0, it, stb[i]);
		if(in_range(it, 0, n)) stb.update_chmin(it, it + 1, stb[i] + a[it] - data[i]);
	}

	debug(a);
	debug(c);
	debug(data);

	// rep(i, n) { cout << stb.query_max(i, i + 1) << sp; }

	drop(accumulate(all(c), 0LL) + stb.query_max(n - 1, n));

	return 0;
}