/*	author:  Kite_kuma
	created: 2021.09.12 23:03:24 */

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

#pragma region geometry_light

using Real = long double;
using R = Real;
using Point = std::complex<Real>;
using Vec = Point;
const Real EPS = 1e-10, PI = acos(-1);

inline bool eq(const Real &a, const Real &b) { return fabs(b - a) < EPS; }
inline bool eq(const Point &a, const Point &b) { return fabs(b - a) < EPS; }
/*
	-1: a < b
	0 : a == b
	1 : a > b
*/
inline int compare(const Real &a, const Real &b) { return eq(a, b) ? 0 : a < b ? -1 : 1; }
inline int sign(const Real &a) { return fabs(a) < EPS ? 0 : a < 0 ? -1 : 1; }

namespace std {
const Point operator*(const Point &p, const Real &d) { return Point(real(p) * d, imag(p) * d); }
}  // namespace std

std::istream &operator>>(std::istream &is, Point &p) {
	Real a, b;
	is >> a >> b;
	p = Point(a, b);
	return is;
}
std::ostream &operator<<(std::ostream &os, Point &p) { return os << std::fixed << std::setprecision(10) << p.real() << " " << p.imag(); }

// rotate point 'p' for counter clockwise direction
const Point rotate(const Real &theta, const Point &p) {
	return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

const Real radian_to_degree(const Real &r) { return (r * 180.0 / PI); }

const Real degree_to_radian(const Real &d) { return (d * PI / 180.0); }

// get angle a-b-c (<pi)
const Real get_angle(const Point &a, const Point &b, const Point &c) {
	const Point v(a - b), w(c - b);
	Real theta = fabs(atan2(w.imag(), w.real()) - atan2(v.imag(), v.real()));
	return std::min(theta, 2 * PI - theta);
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
}  // namespace std

struct Line {
	Point a, b;

	Line() = default;

	Line(Point a, Point b) : a(a), b(b) {}

	Line(Real A, Real B, Real C)  // Ax + By = C
	{
		if(eq(A, 0))
			a = Point(0, C / B), b = Point(1, C / B);
		else if(eq(B, 0))
			b = Point(C / A, 0), b = Point(C / A, 1);
		else
			a = Point(0, C / B), b = Point(C / A, 0);
	}

	friend std::ostream &operator<<(std::ostream &os, Line &p) { return os << p.a << " -- " << p.b; }

	friend std::istream &operator>>(std::istream &is, Line &a) { return is >> a.a >> a.b; }
};

struct Segment : Line {
	Segment() = default;

	Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
	Point p;
	Real r;

	Circle() = default;

	Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = std::vector<Point>;
using Polygon = std::vector<Point>;
using Segments = std::vector<Segment>;
using Lines = std::vector<Line>;
using Circles = std::vector<Circle>;

const Real cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }
const Real dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
const int ccw(const Point &a, Point b, Point c) {
	b = b - a, c = c - a;
	if(cross(b, c) > EPS) return +1;		// "COUNTER_CLOCKWISE"
	if(cross(b, c) < -EPS) return -1;		// "CLOCKWISE"
	if(dot(b, c) < -EPS) return +2;			// "ONLINE_BACK"
	if(norm(b) + EPS < norm(c)) return -2;	// "ONLINE_FRONT"
	return 0;								// "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
bool parallel(const Line &a, const Line &b) { return eq(cross(a.b - a.a, b.b - b.a), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
bool orthogonal(const Line &a, const Line &b) { return eq(dot(a.a - a.b, b.a - b.b), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
Point projection(const Line &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
Point reflection(const Line &l, const Point &p) { return projection(l, p) * 2.0 - p; }

int intersect(const Line &l, const Point &p) { return int(abs(ccw(l.a, l.b, p)) != 1); }

int intersect(const Line &l, const Line &m) {
	if(intersect(l, m.a) && intersect(l, m.b)) return -1;
	return int(abs(cross(l.b - l.a, m.b - m.a)) > EPS);
}

int intersect(const Segment &s, const Point &p) { return int(ccw(s.a, s.b, p) == 0); }

int intersect(const Line &l, const Segment &s) {
	if(intersect(l, s.a) && intersect(l, s.b)) return -1;
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

Real distance(const Line &l, const Point &p);

int intersect(const Circle &c, const Line &l) {
	Real d = c.r - distance(l, c.p);
	return fabs(d) < EPS ? 1 : d > 0. ? 2 : 0;
}

int intersect(const Circle &c, const Point &p) { return int(abs(abs(p - c.p) - c.r) < EPS); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
int intersect(const Segment &s, const Segment &t) {
	if(eq(s.a, s.b)) return intersect(t, s.a);
	if(intersect(Line(s), t.a) && intersect(Line(s), t.b) &&
	   std::max(std::min(s.a, s.b), std::min(t.a, t.b)) < std::min(std::max(s.a, s.b), std::max(t.a, t.b)))
		return -1;
	return int(ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0);
}

int intersect(const Circle &c, const Segment &l) {
	const Point h = projection(l, c.p);
	if(norm(h - c.p) - c.r * c.r > EPS) return 0;
	auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
	if(compare(d1, c.r) == -1 && compare(d2, c.r) == -1) return 0;
	if(d1 < c.r - EPS && d2 > c.r - EPS || d1 > c.r - EPS && d2 < c.r - EPS) return 1;
	return dot(l.a - h, l.b - h) < 0 ? 2 : 0;
}

Real distance(const Point &a, const Point &b);

int number_of_common_tangents(const Circle &c1, const Circle &c2) {
	Real r1 = std::min(c1.r, c2.r), r2 = std::max(c1.r, c2.r), d = distance(c1.p, c2.p);
	int com = compare(r1 + r2, d);
	return com == 1 ? compare(d + r1, r2) + 1 : 3 - com;
	// if(c1.r < c2.r) swap(c1, c2);
	// Real d = abs(c1.p - c2.p);
	// if(compare(c1.r + c2.r, d) == -1) return 4;
	// if(eq(c1.r + c2.r, d)) return 3;
	// if(compare(c1.r - c2.r, d) == -1) return 2;
	// return int(eq(c1.r - c2.r, d));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
int intersect(const Circle &c1, const Circle &c2) { return 2 - abs(2 - number_of_common_tangents(c1, c2)); }

Real distance(const Point &a, const Point &b) { return abs(a - b); }

Real distance(const Line &l, const Point &p) { return abs(p - projection(l, p)); }

Real distance(const Line &l, const Line &m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Segment &s, const Point &p) {
	Point r = projection(s, p);
	return intersect(s, r) ? distance(r, p) : std::min(abs(s.a - p), abs(s.b - p));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
Real distance(const Segment &a, const Segment &b) {
	if(intersect(a, b)) return 0;
	return std::min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

Real distance(const Line &l, const Segment &s) {
	if(intersect(l, s)) return 0;
	return std::min(distance(l, s.a), distance(l, s.b));
}

Point crosspoint(const Line &l, const Line &m) {
	Real A = cross(l.b - l.a, m.b - m.a);
	Real B = cross(l.b - l.a, l.b - m.a);
	if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
	return m.a + (m.b - m.a) * B / A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Segment &l, const Segment &m) { return crosspoint(Line(l), Line(m)); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
std::pair<Point, Point> crosspoint(const Circle &c, const Line l) {
	Point pr = projection(l, c.p);
	if(eq(distance(l, c.p), c.r)) return {pr, pr};
	Vec v = (l.b - l.a) / abs(l.b - l.a) * sqrt(c.r * c.r - norm(pr - c.p));
	return make_pair(pr - v, pr + v);
	// Vec e = (l.b - l.a) / abs(l.b - l.a);
	// double base = sqrt(c.r * c.r - norm(pr - c.p));
	// return {pr - e * base, pr + e * base};
}

std::pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
	if(intersect(c, l) == 2) return crosspoint(c, Line(l.a, l.b));
	auto ret = crosspoint(c, Line(l.a, l.b));
	if(dot(l.a - ret.first, l.b - ret.first) < EPS)
		ret.second = ret.first;
	else
		ret.first = ret.second;
	return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
std::pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
	Real d = abs(c1.p - c2.p);
	Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));  // cosine theorem
	Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
	Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
	Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
	return make_pair(p1, p2);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
// " p  c "2
std::pair<Point, Point> tangent(const Circle &c1, const Point &p2) {
	return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r)));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
//  c1, c2 
Lines tangent(Circle c1, Circle c2) {
	Lines ret;
	if(c1.r < c2.r) std::swap(c1, c2);
	Real g = norm(c1.p - c2.p);
	if(eq(g, 0)) return ret;
	Vec u = (c2.p - c1.p) / Real(sqrt(g));
	Vec v = rotate(PI * 0.5, u);
	for(int s : {-1, 1}) {
		Real h = (c1.r + s * c2.r) / sqrt(g);
		if(eq(1 - h * h, 0)) {
			ret.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
		} else if(1 - h * h > 0) {
			Point uu = u * h, vv = v * sqrt(1 - h * h);
			ret.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
			ret.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
		}
	}
	return ret;
}

#pragma endregion

bool include(Circle c, Point p) { return compare(distance(c.p, p), c.r) == -1; }

ll solve() {
	LL(n, s);
	ll half = n / 2 + 1;
	// if(n % 2 == 0) half = n / 2 + 1;
	// if(/)

	return s / half;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(15);
	srand((unsigned)time(NULL));

	int n;
	cin >> n;
	while(n--) {
		cout << solve() << dl;
	}

	return 0;
}