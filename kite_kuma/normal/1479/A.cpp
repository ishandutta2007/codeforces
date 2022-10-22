/*	author:  Kite_kuma
	created: 2021.02.08 13:22:02 */

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(15);
	srand((unsigned)time(NULL));

	int n;
	cin >> n;

	vi a(n + 2, -1);
	a[0] = a[n + 1] = inf;

	auto query = [&](int idx) {
		if(a[idx] > -1) return;
		cout << "? " << idx << endl;
		cin >> a[idx];
		return;
	};

	int lef = 0, rig = n + 1;

	while(rig - lef > 20) {
		int mid = (lef + rig) / 2;
		query(mid), query(mid + 1);
		if(a[mid] > a[mid + 1]) {
			lef = mid;
		} else {
			rig = mid + 1;
		}
	}

	rep(mid, lef + 1, rig) { query(mid); }
	rep(mid, lef + 1, rig) {
		if(a[mid] < min(a[mid - 1], a[mid + 1])) {
			cout << "! " << mid << endl;
			return 0;
		}
	}

	return 0;
}