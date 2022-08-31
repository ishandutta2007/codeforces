#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1.0);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }

struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
	friend ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
};
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }

Pt circumcenter(const Pt &a, const Pt &b, const Pt &c) {
	const Pt bc = c - b, ca = a - c, ab = b - a;
	return (b + c - bc * Pt(0, 1) * ca.dot(ab) / ca.det(ab)) / 2;
}

int N;
Pt P[110];

bool check(const Pt &p, double r) {
	for (int i = 0; i < N; ++i) {
		if (sig((P[i] - p).abs() - r) < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			P[i].x = in();
			P[i].y = in();
		}
		double ans = -1.0;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) {
			if (sig(tri(P[i], P[j], P[k])) > 0) {
				const int sdi = sig((P[j] - P[i]).dot(P[k] - P[i]));
				const int sdj = sig((P[k] - P[j]).dot(P[i] - P[j]));
				const int sdk = sig((P[i] - P[k]).dot(P[j] - P[k]));
				bool ok = false;
				if (sdi > 0 && sdj > 0 && sdk > 0) {
					ok = true;
				} else if (sdi > 0 && sdj == 0 && sdk > 0) {
					for (int l = 0; l < N; ++l) if (sig((P[i] - P[j] + P[k] - P[l]).abs()) == 0) {
						ok = true;
					}
				}
				if (ok) {
					const Pt o = circumcenter(P[i], P[j], P[k]);
					const double r = (P[i] - o).abs();
					if (check(o, r)) {
						chmax(ans, r);
					}
				}
			}
		}
		printf("%.10f\n", ans);
	}
	
	return 0;
}