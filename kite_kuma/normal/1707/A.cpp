#line 1 "a.cpp"
/*	author:  Kite_kuma
	created: 2022.07.16 23:33:55 */

#line 2 "SPJ-Library/template/kuma.hpp"

#line 2 "SPJ-Library/template/basic_func.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

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

void Yes(bool flag = true) { std::cout << (flag ? "Yes" : "No") << '\n'; }
void YES(bool flag = true) { std::cout << (flag ? "YES" : "NO") << '\n'; }

template <class T>
void drop(T answer) {
	std::cout << answer << '\n';
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
inline void print(const T &x) {
	std::cout << x << '\n';
	return;
}
template <typename Head, typename... Tail>
void print(const Head &H, const Tail &... T) {
	std::cout << H << " ";
	print(T...);
}

template <class T>
void add(std::vector<T> &v, T value) {
	for(auto &a : v) a += value;
	return;
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

// ceil(a / b);
template <class T>
T dup(T a, T b) {
	assert(b);
	if(b < 0) {
		a *= -1;
		b *= -1;
	}
	return least_upper_multiple(a, b) / b;
}

long long pow_ll(long long a, long long n) {
	assert(n >= 0LL);
	if(n == 0) return 1LL;
	if(a == 0) return 0LL;
	if(a == 1) return 1LL;
	if(a == -1) return (n & 1LL) ? -1LL : 1LL;
	long long res = 1;
	while(n > 1LL) {
		if(n & 1LL) res *= a;
		a *= a;
		n >>= 1;
	}
	return res * a;
}

long long modpow(long long a, long long n, long long mod) {	 // a^n mod
	assert(n >= 0 && mod);
	if(mod == 1) return 0LL;
	long long res = 1;
	a %= mod;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res < 0 ? res + mod : res;
}

// return x which satisfies a * x % mod == gcd(a, mod)
// not (mod | a)
long long modinv(long long a, const long long mod) {
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
	return (int)std::distance(a.begin(), std::lower_bound(a.begin(), a.end(), x));
}
template <class T>
int ub(const std::vector<T> &a, const T x) {
	return (int)std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), x));
}
template <class T>
void unq_sort(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<int> press(const std::vector<T> &a) {
	std::vector<T> vec = a;
	unq_sort(vec);
	std::vector<int> ret;
	for(const auto &v : a) ret.push_back(lb(vec, v));
	return ret;
}
#line 1 "SPJ-Library/template/header.hpp"
#include <bits/stdc++.h>
#line 2 "SPJ-Library/template/io.hpp"

#line 4 "SPJ-Library/template/io.hpp"

#line 8 "SPJ-Library/template/debug.hpp"

#line 3 "SPJ-Library/template/constants.hpp"

constexpr int inf = 1000'000'000;
constexpr long long INF = 1'000'000'000'000'000'000LL;
constexpr int mod_1000000007 = 1000000007;
constexpr int mod_998244353 = 998244353;
const long double pi = acosl(-1.);
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
#line 10 "SPJ-Library/template/debug.hpp"

namespace viewer {

template <typename T, typename U>
void view(const std::pair<T, U> &p);

template <class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p);

template <class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p);

void view(const long long &e);

void view(const int &e);

template <typename T>
void view(const T &e);

template <typename T>
void view(const std::set<T> &s);

template <typename T>
void view(const std::unordered_set<T> &s);

template <typename T>
void view(const std::multiset<T> &s);

template <typename T>
void view(const std::unordered_multiset<T> &s);

template <typename T>
void view(const std::vector<T> &v);

template <typename T, std::size_t ary_size>
void view(const std::array<T, ary_size> &v);

template <typename T>
void view(const std::vector<std::vector<T>> &vv);

template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v);

template <class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v);

template <class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v);

template <typename map_type>
void view_map_container(const map_type &m);

template <typename T, typename U>
void view(const std::map<T, U> &m);

template <typename T, typename U>
void view(const std::unordered_map<T, U> &m);

template <typename container_type>
void view_container(const container_type &c, bool vertically = false) {
	typename container_type::const_iterator begin = c.begin();
	const typename container_type::const_iterator end = c.end();
	if(vertically) {
		std::cerr << "{\n";
		while(begin != end) {
			std::cerr << '\t';
			view(*(begin++));
			if(begin != end) std::cerr << ',';
			std::cerr << '\n';
		}
		std::cerr << '}';
		return;
	}
	std::cerr << "{ ";
	while(begin != end) {
		view(*(begin++));
		if(begin != end) std::cerr << ',';
		std::cerr << ' ';
	}
	std::cerr << '}';
}

template <typename T, typename U>
void view(const std::pair<T, U> &p) {
	std::cerr << '(';
	view(p.first);
	std::cerr << ", ";
	view(p.second);
	std::cerr << ')';
}

template <class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p) {
	std::cerr << '(';
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ')';
}

template <class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p) {
	std::cerr << '(';
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ", ";
	view(std::get<3>(p));
	std::cerr << ')';
}

void view(const long long &e) {
	if(e == INF)
		std::cerr << "INF";
	else if(e == -INF)
		std::cerr << "-INF";
	else
		std::cerr << e;
}

void view(const int &e) {
	if(e == inf)
		std::cerr << "inf";
	else if(e == -inf)
		std::cerr << "-inf";
	else
		std::cerr << e;
}

template <typename T>
void view(const T &e) {
	std::cerr << e;
}

template <typename T>
void view(const std::set<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::unordered_set<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::multiset<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::unordered_multiset<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::vector<T> &v) {
	view_container(v);
}

template <typename T, std::size_t ary_size>
void view(const std::array<T, ary_size> &v) {
	view_container(v);
}

template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	view_container(vv, true);
}

template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	view_container(v, true);
}

template <class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v) {
	view_container(v, true);
}

template <class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v) {
	view_container(v, true);
}

template <typename map_type>
void view_map_container(const map_type &m) {
	std::cerr << "{\n";
	for(typename map_type::const_iterator it = m.begin(); it != m.end(); it++) {
		std::cerr << "\t[";
		view(it->first);
		std::cerr << "] : ";
		view(it->second);
		std::cerr << '\n';
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::map<T, U> &m) {
	view_map_container(m);
}

template <typename T, typename U>
void view(const std::unordered_map<T, U> &m) {
	view_map_container(m);
}

}  // namespace viewer

// when compiling : g++ foo.cpp -DLOCAL
#ifdef LOCAL
void debug_out() {}
template <typename T>
void debug_out(const T &x) {
	viewer::view(x);
}
template <typename Head, typename... Tail>
void debug_out(const Head &H, const Tail &... T) {
	viewer::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "]\n";                                       \
	} while(0)
#else
#define debug(...) (void(0))
#endif
#line 2 "SPJ-Library/template/scanner.hpp"

#line 6 "SPJ-Library/template/scanner.hpp"

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
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner
#line 7 "SPJ-Library/template/io.hpp"

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

template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}

template <typename T1, typename T2>
std::ostream &std::operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
	os << p.first << ' ' << p.second;
	return os;
}
template <class T>
std::ostream &std::operator<<(std::ostream &os, const std::vector<T> &v) {
	for(typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if(it != v.begin()) os << ' ';
		os << *it;
	}
	return os;
}

struct fast_io {
	fast_io() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout << std::fixed << std::setprecision(15);
		srand((unsigned)time(NULL));
	}
} fast_io_;
#line 2 "SPJ-Library/template/macros.hpp"

#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pcnt(n) __builtin_popcountll((long long)n)

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

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vvvi = std::vector<std::vector<std::vector<int>>>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
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
#line 7 "SPJ-Library/template/kuma.hpp"

using namespace std;
#line 5 "a.cpp"
// #include "atcoder/lazysegtree.hpp"

void solve() {
	int n;
	ll q;
	cin >> n >> q;
	VEC(ll, a, n);

	reverse(all(a));
	ll iq = 0;
	int ans = 0;
	string res;
	foa(val, a) {
		if(iq == q && val > iq) {
			res += '0';
		} else {
			res += '1';
			if(val > iq) iq++;
		}
	}reverse(all(res));
	print(res);
}

int main() {
	int t;
	cin >> t;
	rep(t) { solve(); }
	return 0;
}