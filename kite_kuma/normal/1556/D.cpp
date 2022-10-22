/*	author:  Kite_kuma
	created: 2021.08.29 23:34:03 */

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
void INPUT(Head &head, Tail &... tail) {
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(15);
	srand((unsigned)time(NULL));

#ifdef LOCAL
	vll ans = {1, 4, 1, 5, 2};
#endif

	int n, k;

#ifdef LOCAL
	n = ans.size();
	k = 4;
#else
	cin >> n >> k;
#endif

	auto query_and = [&](int i, int j) {
		assert(i != j && in_range(i, 0, n) && in_range(j, 0, n));
		if(i > j) swap(i, j);
		cout << "and " << i + 1 << sp << j + 1 << endl;
		ll ret;
#ifdef LOCAL
		ret = ans[i] & ans[j];
#else
		cin >> ret;
#endif
		if(ret == -1) exit(0);
		return ret;
	};

	auto query_or = [&](int i, int j) {
		assert(i != j && in_range(i, 0, n) && in_range(j, 0, n));
		if(i > j) swap(i, j);
		cout << "or " << i + 1 << sp << j + 1 << endl;
		ll ret;

#ifdef LOCAL
		ret = ans[i] | ans[j];
#else
		cin >> ret;
#endif
		if(ret == -1) exit(0);
		return ret;
	};

	auto fin = [&](ll ret) {
		cout << "finish " << ret << endl;
		exit(0);
		return;
	};

	ll d = query_and(0, 1);
	ll e = query_and(1, 2);
	ll f = query_and(2, 0);
	ll g = query_or(0, 1);
	ll h = query_or(1, 2);
	ll i = query_or(2, 0);

	vll res(n);
	debug(d, e, f, g, h, i);

	rep(cnt, 30) {
		ll keta = 1LL << cnt;
		debug(keta);
		ll dd = d & keta;
		ll ee = e & keta;
		ll ff = f & keta;
		ll gg = g & keta;
		ll hh = h & keta;
		ll ii = i & keta;

		if(dd + ee + ff + gg + hh + ii) {
			debug(keta);
			debug(dd, ee, ff, gg, hh, ii);
		}

		if(dd && ee && ff) {
			res[0] += keta;
			res[1] += keta;
			res[2] += keta;
		} else if(dd) {
			res[0] += keta;
			res[1] += keta;
		} else if(ee) {
			res[1] += keta;
			res[2] += keta;
		} else if(ff) {
			res[2] += keta;
			res[0] += keta;
		} else if(gg) {
			if(hh) {
				res[1] += keta;
			} else {
				res[0] += keta;
			}
		} else {
			if(hh) {
				res[2] += keta;
			} else {
				// pass
			}
		}
	}

	rep(nxt, 3, n) {
		ll res_and = query_and(0, nxt);
		ll res_or = query_or(0, nxt);

		rep(cnt, 30) {
			ll keta = 1LL << cnt;
			ll keta_and = res_and & keta;
			ll keta_or = res_or & keta;

			if(keta_and) {
				res[nxt] += keta;
			} else if(keta_or) {
				if(keta & res[0]) {
					// pass
				} else {
					res[nxt] += keta;
				}
			}
		}
	}

	debug(ans, k);
	debug(res);

	sort(all(res));

	fin(res[k - 1]);

	return 0;
}