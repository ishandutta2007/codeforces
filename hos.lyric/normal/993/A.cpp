#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

typedef long double Double;

struct Pt {
	Double x, y;
	Pt() {}
	Pt(Double x, Double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator/(const Pt &a) const { const Double d2 = a.abs2(); return Pt((x * a.x + y * a.y) / d2, (y * a.x - x * a.y) / d2); }
	Pt operator+() const { return Pt(+x, +y); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const Double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const Double &k) const { return Pt(x / k, y / k); }
	friend Pt operator*(const Double &k, const Pt &a) { return Pt(k * a.x, k * a.y); }
	Pt &operator+=(const Pt &a) { x += a.x; y += a.y; return *this; }
	Pt &operator-=(const Pt &a) { x -= a.x; y -= a.y; return *this; }
	Pt &operator*=(const Pt &a) { return *this = *this * a; }
	Pt &operator/=(const Pt &a) { return *this = *this / a; }
	Pt &operator*=(const Double &k) { x *= k; y *= k; return *this; }
	Pt &operator/=(const Double &k) { x /= k; y /= k; return *this; }
	Double abs() const { return sqrt(x * x + y * y); }
	Double abs2() const { return x * x + y * y; }
	Double arg() const { return atan2(y, x); }
	Double dot(const Pt &a) const { return x * a.x + y * a.y; }
	Double det(const Pt &a) const { return x * a.y - y * a.x; }
	friend ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
};
const Double EPS = 1e-10;
const Double INF = 1e+10;
const Double PI = acos(-1.0);
inline int sig(Double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline Double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }

int iSP(const Pt &a, const Pt &b, const Pt &c) {
	int s = sig((b - a).det(c - a));
	if (s != 0) return s;
	if (sig((b - a).dot(c - a)) < 0) return -2; // c-a-b
	if (sig((a - b).dot(c - b)) < 0) return +2; //   a-b-c
	return 0;
}

bool iSS(const Pt &a, const Pt &b, const Pt &c, const Pt &d) {
	return (iSP(a, b, c) * iSP(a, b, d) <= 0 && iSP(c, d, a) * iSP(c, d, b) <= 0);
}

//	inside: +1, boundary: 0, outside: -1
int sGP(int n, Pt p[], const Pt &a) {
	int side = -1;
	p[n] = p[0];
	for (int i = 0; i < n; ++i) {
		Pt p0 = p[i] - a, p1 = p[i + 1] - a;
		if (sig(p0.det(p1)) == 0 && sig(p0.dot(p1)) <= 0) return 0;
		if (p0.y > p1.y) swap(p0, p1);
		if (sig(p0.y) <= 0 && 0 < sig(p1.y) && sig(p0.det(p1)) > 0) side = -side;
	}
	return side;
}



int main() {
  Pt P[5], Q[5];
  for (; ~scanf("%Lf%Lf", &P[0].x, &P[0].y); ) {
    for (int i = 1; i < 4; ++i) {
      scanf("%Lf%Lf", &P[i].x, &P[i].y);
    }
    for (int j = 0; j < 4; ++j) {
      scanf("%Lf%Lf", &Q[j].x, &Q[j].y);
    }
    P[4] = P[0];
    Q[4] = Q[0];
    bool ans = false;
    for (int j = 0; j < 4; ++j) {
      ans = ans || (sGP(4, P, Q[j]) >= 0);
    }
    for (int i = 0; i < 4; ++i) {
      ans = ans || (sGP(4, Q, P[i]) >= 0);
    }
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
      ans = ans || iSS(P[i], P[i + 1], Q[j], Q[j + 1]);
    }
    puts(ans ? "Yes" : "No");
  }
  return 0;
}