#line 1 "a.cpp"
/*	author:  Kite_kuma
	created: 2022.08.01 20:59:35 */

#line 2 "SPJ-Library/geometry/geometry.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <vector>

using R = long double;
using point = std::complex<R>;
using arrow = point;
const R EPS(1e-10), PI(acosl(-1));

inline bool eq(const R &a, const R &b) { return fabsl(b - a) < EPS; }
inline bool same_point(const point &a, const point &b) { return abs(b - a) < EPS; }
/*
	sign of x
	-1: x < 0
	 0: x == 0
	 1: x > 0
*/
inline int sgn(const R &x) { return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1); }
/*
	sign of (a-b)
	-1: a < b
	 0: a == b
	 1: a > b
*/
inline int compare(const R &a, const R &b) { return eq(a, b) ? 0 : a < b ? -1 : 1; }

std::istream &operator>>(std::istream &is, point &p) {
	R a, b;
	is >> a >> b;
	p = point(a, b);
	return is;
}
std::ostream &operator<<(std::ostream &os, point &p) { return os << '(' << p.real() << ", " << p.imag() << ')'; }

// rotate point 'p' for counter clockwise direction
point rotate(const point &p, const R &theta) {
	return point(cosl(theta) * p.real() - sinl(theta) * p.imag(), sinl(theta) * p.real() + cosl(theta) * p.imag());
}

R radian_to_degree(const R &r) { return (r * 180.0 / PI); }
R degree_to_radian(const R &d) { return (d * PI / 180.0); }

// get angle a-b-c (<pi)
R get_angle(const point &a, const point &b, const point &c) {
	const point v(a - b), w(c - b);
	R theta = fabsl(atan2l(w.imag(), w.real()) - atan2l(v.imag(), v.real()));
	return std::min(theta, 2 * PI - theta);
}

namespace std {
bool operator<(const point &a, const point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
}  // namespace std

struct segment;
struct line {
	point a, b;
	line() = default;
	line(const point &a, const point &b) : a(a), b(b) {}
	// Ax + By + C = 0
	line(const R &A, const R &B, const R &C) {
		if(eq(A, 0)) {
			assert(!eq(B, 0));
			a = point(0, -C / B), b = point(1, -(A + C) / B);
		} else {
			a = point(-C / A, 0), b = point(-(B + C) / A, 1);
		}
	}
	explicit line(const segment &seg);
	friend std::ostream &operator<<(std::ostream &os, line &ln) { return os << '(' << ln.a << " -- " << ln.b << ')'; }
	friend std::istream &operator>>(std::istream &is, line &a) { return is >> a.a >> a.b; }
};
struct segment {
	point a, b;
	segment() = default;
	segment(const point &a, const point &b) : a(a), b(b) {}
	explicit segment(const line &ln) : a(ln.a), b(ln.b) {}
	friend std::ostream &operator<<(std::ostream &os, segment &seg) { return os << '[' << seg.a << " -- " << seg.b << ']'; }
	friend std::istream &operator>>(std::istream &is, segment &a) { return is >> a.a >> a.b; }
};
line::line(const segment &seg) : a(seg.a), b(seg.b) {}

struct circle {
	point center;
	R radius;
	circle() = default;
	circle(const point &center, const R &radius) : center(center), radius(radius) {}
};

using points = std::vector<point>;
using polygon = std::vector<point>;
using segments = std::vector<segment>;
using lines = std::vector<line>;
using circles = std::vector<circle>;

R cross(const point &a, const point &b) { return real(a) * imag(b) - imag(a) * real(b); }
R dot(const point &a, const point &b) { return real(a) * real(b) + imag(a) * imag(b); }

enum CCW {
	ONLINE_FRONT = -2,
	CLOCKWISE = -1,
	ON_SEGMENT = 0,
	COUNTER_CLOCKWISE = 1,
	ONLINE_BACK = 2,
};
int ccw(const point &a, point b, point c) {
	b -= a, c -= a;
	const R crs_b_c = cross(b, c);
	if(crs_b_c > EPS) return CCW::COUNTER_CLOCKWISE;
	if(crs_b_c < -EPS) return CCW::CLOCKWISE;
	if(dot(b, c) < -EPS) return CCW::ONLINE_BACK;
	if(norm(b) + EPS < norm(c)) return CCW::ONLINE_FRONT;
	return CCW::ON_SEGMENT;
}

bool parallel(const arrow &a, const arrow &b) { return eq(cross(a, b), R(0)); }
bool parallel(const line &a, const line &b) { return parallel(a.b - a.a, b.b - b.a); }
bool parallel(const line &a, const segment &b) { return parallel(a.b - a.a, b.b - b.a); }
bool parallel(const segment &a, const line &b) { return parallel(a.b - a.a, b.b - b.a); }
bool parallel(const segment &a, const segment &b) { return parallel(a.b - a.a, b.b - b.a); }

bool orthogonal(const arrow &a, const arrow &b) { return eq(dot(a, b), R(0)); }
bool orthogonal(const line &a, const line &b) { return orthogonal(a.b - a.a, b.b - b.a); }
bool orthogonal(const line &a, const segment &b) { return orthogonal(a.b - a.a, b.b - b.a); }
bool orthogonal(const segment &a, const line &b) { return orthogonal(a.b - a.a, b.b - b.a); }
bool orthogonal(const segment &a, const segment &b) { return orthogonal(a.b - a.a, b.b - b.a); }

point projection(const line &l, const point &p) { return l.a + (l.a - l.b) * dot(p - l.a, l.a - l.b) / norm(l.a - l.b); }
point projection(const segment &s, const point &p) { return projection(line(s), p); }

point reflection(const line &l, const point &p) { return projection(l, p) * R(2) - p; }
point reflection(const segment &s, const point &p) { return projection(line(s), p); }

R distance(const point &p, const point &q);
R distance(const line &l, const point &p);
int number_of_common_tangents(const circle &c1, const circle &c2) {
	const R r1 = std::min(c1.radius, c2.radius), r2 = std::max(c1.radius, c2.radius), d = distance(c1.center, c2.center);
	int com = compare(r1 + r2, d);
	return com == 1 ? compare(d + r1, r2) + 1 : 3 - com;
}

// number of common points (-1: infinite)
int intersect(const line &l, const point &p) { return int(abs(ccw(l.a, l.b, p)) != 1); }
int intersect(const point &p, const line &l) { return intersect(l, p); }
int intersect(const line &l, const line &m) {
	if(intersect(l, m.a) && intersect(l, m.b)) return -1;
	return int(!parallel(l, m));
}
int intersect(const segment &s, const point &p) { return int(ccw(s.a, s.b, p) == CCW::ON_SEGMENT); }
int intersect(const point &p, const segment &s) { return intersect(s, p); }
int intersect(const line &l, const segment &s) {
	if(intersect(l, s.a) && intersect(l, s.b)) return -1;
	return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) != 1;
}
int intersect(const segment &s, const line &l) { return intersect(l, s); }
int intersect(const circle &c, const line &l) {
	R d = c.radius - distance(l, c.center);
	return fabsl(d) < EPS ? 1 : d > 0. ? 2 : 0;
}
int intersect(const line &l, const circle &c) { return intersect(c, l); }
int intersect(const circle &c, const point &p) { return int(eq(c.radius, distance(c.center, p))); }
int intersect(const point &p, const circle &c) { return intersect(c, p); }
int intersect(const segment &s, const segment &t) {
	if(same_point(s.a, s.b)) return intersect(t, s.a);
	if(intersect(line(s), t.a) && intersect(line(s), t.b) &&
	   std::max(std::min(s.a, s.b), std::min(t.a, t.b)) < std::min(std::max(s.a, s.b), std::max(t.a, t.b)))
		return -1;
	return int(ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0);
}
int intersect(const circle &c, const segment &s) {
	const point h = projection(s, c.center);
	const int c0 = compare(distance(h, c.center), c.radius);
	if(c0 == 1) return 0;
	if(c0 == 0) return intersect(s, h);
	const int c1 = compare(distance(c.center, s.a), c.radius), c2 = compare(distance(c.center, s.b), c.radius);
	if(std::min(c1, c2) == -1) return int(std::max(c1, c2) >= 0);
	return intersect(s, h) ? 2 : 0;
}
int intersect(const segment &s, const circle &c) { return intersect(c, s); }
int intersect(const circle &c1, const circle &c2) { return 2 - abs(2 - number_of_common_tangents(c1, c2)); }

// distance of two shaps
R distance(const point &a, const point &b) { return fabs(a - b); }
R distance(const line &l, const point &p) { return distance(p, projection(l, p)); }
R distance(const point &p, const line &l) { return distance(l, p); }
R distance(const line &l, const line &m) { return parallel(l, m) ? distance(l, m.a) : 0; }
R distance(const segment &s, const point &p) {
	const point r = projection(s, p);
	return intersect(s, r) ? distance(r, p) : std::min(distance(s.a, p), distance(s.b, p));
}
R distance(const point &p, const segment &s) { return distance(s, p); }
R distance(const segment &a, const segment &b) {
	if(intersect(a, b)) return R(0);
	return std::min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}
R distance(const line &l, const segment &s) {
	if(intersect(l, s)) return 0;
	return std::min(distance(l, s.a), distance(l, s.b));
}
R distance(const segment &s, const line &l) { return distance(l, s); }
R distance(const circle &c, const point &p) { return fabsl(distance(c.center, p) - c.radius); }
R distance(const point &p, const circle &c) { return distance(c, p); }
R distance(const circle &c, const line &l) { return std::max(R(0), distance(l, c.center) - c.radius); }
R distance(const line &l, const circle &c) { return distance(c, l); }
R distance(const circle &c1, const circle &c2) {
	const R d = distance(c1.center, c2.center);
	if(d > c1.radius + c2.radius) return d - c1.radius - c2.radius;
	if(d < fabsl(c1.radius - c2.radius)) return fabsl(c1.radius - c2.radius) - d;
	return R(0);
}
R distance(const circle &c, const segment &s) {
	const point p = projection(s, c.center);
	const R dist_min = intersect(s, p) ? distance(c.center, p) : std::min(distance(c.center, s.a), distance(c.center, s.b));
	if(dist_min > c.radius) return dist_min - c.radius;
	const R dist_max = std::max(distance(c.center, s.a), distance(c.center, s.b));
	return dist_max < c.radius ? c.radius - dist_max : R(0);
}
R distance(const segment &s, const circle &c) { return distance(c, s); }

point crosspoint(const line &l, const line &m) {
	R A = cross(l.b - l.a, m.b - m.a);
	R B = cross(l.b - l.a, l.b - m.a);
	if(eq(A, 0.)) return m.a;
	return m.a + (m.b - m.a) * B / A;
}
point crosspoint(const segment &s, const segment &t) { return crosspoint(line(s), line(t)); }
point crosspoint(const segment &s, const line &l) { return crosspoint(line(s), l); }
point crosspoint(const line &l, const segment &s) { return crosspoint(l, line(s)); }
points crosspoints(const circle &c, const line &l) {
	const point pr = projection(l, c.center);
	const R square = c.radius * c.radius - norm(pr - c.center);
	switch(sgn(square)) {
		case 0:
			return points{pr};
		case -1:
			return points(0);
	}
	const arrow v = (l.b - l.a) / abs(l.b - l.a) * sqrtl(square);
	return points{pr - v, pr + v};
}
points crosspoints(const line &l, const circle &c) { return crosspoints(c, l); }
points crosspoints(const circle &c, const segment &s) {
	points ret;
	for(const auto &pt : crosspoints(c, line(s)))
		if(intersect(s, pt)) ret.push_back(pt);
	return ret;
}
points crosspoints(const segment &s, const circle &c) { return crosspoints(c, s); }
points crosspoints(const circle &c1, const circle &c2) {
	R d = abs(c1.center - c2.center);
	if(compare(d, c1.radius + c2.radius) == 1) return points(0);
	if(compare(d, fabsl(c1.radius - c2.radius)) == -1) return points(0);
	bool one_crosspoint = false;
	if(eq(d, c1.radius + c2.radius) || eq(d, fabsl(c1.radius - c2.radius))) one_crosspoint = true;
	const R alpha = acosl((c1.radius * c1.radius + d * d - c2.radius * c2.radius) / (2 * c1.radius * d));  // cosine theorem
	const R beta = std::arg(c2.center - c1.center);
	if(one_crosspoint) return points{c1.center + std::polar(c1.radius, beta + alpha)};
	return points{c1.center + std::polar(c1.radius, beta + alpha), c1.center + std::polar(c1.radius, beta - alpha)};
}

points tangent_points(const circle &c, const point &p) {
	const R square = norm(c.center - p) - c.radius * c.radius;
	switch(sgn(square)) {
		case 0:
			return points{p};
		case -1:
			return points{};
	}
	return crosspoints(c, circle(p, sqrtl(square)));
}

// common tangents of two circles
lines tangents(circle c1, circle c2) {
	lines ret;
	if(c1.radius < c2.radius) std::swap(c1, c2);
	const R g = distance(c1.center, c2.center);
	if(!sgn(g)) return ret;
	const arrow u = (c2.center - c1.center) / g;
	const arrow v = rotate(u, PI * 0.5);
	for(const int &s : {-1, 1}) {
		const R h = (c1.radius + s * c2.radius) / g;
		if(eq(1 - h * h, 0)) {
			ret.emplace_back(c1.center + u * c1.radius, c1.center + (u + v) * c1.radius);
		} else if(1 - h * h > 0) {
			const point uu = u * h, vv = v * sqrtl(1 - h * h);
			ret.emplace_back(c1.center + (uu + vv) * c1.radius, c2.center - (uu + vv) * c2.radius * R(s));
			ret.emplace_back(c1.center + (uu - vv) * c1.radius, c2.center - (uu - vv) * c2.radius * R(s));
		}
	}
	return ret;
}
#line 2 "SPJ-Library/template/kuma.hpp"

#line 2 "SPJ-Library/template/basic_func.hpp"

#line 5 "SPJ-Library/template/basic_func.hpp"
#include <iostream>
#line 7 "SPJ-Library/template/basic_func.hpp"

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
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
	os << p.first << ' ' << p.second;
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
#line 6 "a.cpp"

R solo(point start, point goal, int n, points pts) {
	R minvalue = INF;
	R ans = 0;
	foa(t, pts) {
		ans += distance(t, goal);
		chmin(minvalue, distance(start, t) - distance(goal, t));
	}
	return ans * 2 + minvalue;
}

int main() {
	point a, b;
	cin >> a >> b;
	point box;
	cin >> box;
	int n;
	cin >> n;
	points pts(n);
	rep(i, n) cin >> pts[i];
	R ans = min(solo(a, box, n, pts), solo(b, box, n, pts));
	if(n == 1) drop(ans);
	vector<pair<R, int>> dist_a, dist_b;
	R res = 0;
	rep(i, n) {
		res += distance(box, pts[i]);
		dist_a.emplace_back(distance(pts[i], a) - distance(box, pts[i]), i);
		dist_b.emplace_back(distance(pts[i], b) - distance(box, pts[i]), i);
	}
	res *= 2;
	sort(all(dist_a));
	sort(all(dist_b));
	if(dist_a.front().second != dist_b.front().second) {
		chmin(ans, res + dist_a.front().first + dist_b.front().first);
	} else {
		chmin(ans, res + dist_a[1].first + dist_b.front().first);
		chmin(ans, res + dist_b[1].first + dist_a.front().first);
	}
	drop(ans);
	return 0;
}