/**
 *	author: nok0
 *	created: 2021.06.30 22:06:26
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#pragma region Macros
// rep macro
#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)

// name macro
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

// input macro
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}
#if __has_include(<atcoder/all>)
std::istream &operator>>(std::istream &is, atcoder::modint998244353 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
#endif
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)

// output-macro
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
#if __has_include(<atcoder/all>)
std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }
#endif
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}

//debug macro
namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  // namespace debugger
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif

// vector macro
template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}

// math macro
template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
// modpow
long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}

// others
struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

#include <stack>
#include <vector>

std::vector<set<int>> sts;
struct rollback_UnionFind {
private:
	std::vector<int> par;
	std::stack<std::pair<int, int>> history;
	std::stack<pair<int, V<int>>> history2;

public:
	rollback_UnionFind() = default;

	rollback_UnionFind(size_t n) : par(n, -1) {}

	int root(int x) {
		if(par[x] < 0) return x;
		return root(par[x]);
	}

	bool same(int x, int y) { return root(x) == root(y); }

	bool unite(int x, int y) {
		x = root(x), y = root(y);
		history.emplace(x, par[x]);
		history.emplace(y, par[y]);
		if(x == y) {
			history2.push(pair(-1, V<>{}));
			return false;
		}
		if(par[x] > par[y]) std::swap(x, y);
		par[x] += par[y];
		V<> tmp;
		for(const auto &v : sts[y]) {
			sts[x].insert(v);
			tmp.pb(v);
		}
		history2.push(pair(x, tmp));
		par[y] = x;
		return true;
	}

	void snapshot() {
		while(!history.empty()) history.pop();
	}

	void undo() {
		for(int i = 0; i < 2; i++) {
			par[history.top().first] = history.top().second;
			history.pop();
		}
		const auto &[x, vec] = history2.top();
		if(x != -1) {
			for(auto v : vec) sts[x].erase(v);
		}
		history2.pop();
	}

	void rollback() {
		while(!history.empty()) undo();
	}

	size_t size(int x) { return -par[root(x)]; }
};

void main_() {
	INT(n, m, q);

	VEC(int, p, n);
	VEC(pii, e, m);
	VEC(pii, querys, q);

	rollback_UnionFind uf(n);

	sts.resize(n);
	REP(i, n) {
		sts[i].insert(p[i]);
	}
	V<> eidx;
	V<> eused(m);
	REP(i, q) {
		auto &[t, x] = querys[i];
		--x;
		if(t == 2) {
			eidx.pb(x);
			eused[x] = 1;
		}
	}
	REP(i, m) {
		if(not eused[i]) eidx.pb(i);
	}
	reverse(all(eidx));

	for(auto idx : eidx) {
		auto [u, v] = e[idx];
		--u, --v;
		uf.unite(u, v);
	}

	V<> used(n + 1);
	for(auto [t, x] : querys) {
		if(t == 1) {
			auto &st = sts[uf.root(x)];
			while(SZ(st) and used[*st.rbegin()]) {
				st.erase(*st.rbegin());
			}
			if(SZ(st)) {
				int val = *st.rbegin();
				used[val] = 1;
				print(val);
				st.erase(val);
			} else
				print(0);
		} else
			uf.undo();
	}
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}