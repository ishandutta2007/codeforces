#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld PI = 4 * atanl(1);

const ld eps = 1e-11;
bool eq(ld x, ld y) {
	return fabsl(x - y) < eps;
}
bool ls(ld x, ld y) {
	return x < y && !eq(x, y);
}
bool lseq(ld x, ld y) {
	return x < y || eq(x, y);
}

struct Point {
	ld x, y;

	Point() : x(), y() {}
	Point(ld _x, ld _y) : x(_x), y(_y) {}

	void scan() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x;
		y = _y;
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator * (const ld &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const ld &k) const {
		return Point(x / k, y / k);
	}
	ld operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	ld operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	ld sqrLen() const {
		return *this % *this;
	}
	ld len() const {
		return sqrtl(sqrLen());
	}

	Point ort() const {
		return Point(-y, x);
	}
	Point rot(const ld &ca, const ld &sa) const {
		return *this * ca + ort() * sa;
	}
	Point rot(const ld &ang) const {
		return rot(cosl(ang), sinl(ang));
	}

	void eprint() {
		eprintf("(%.5lf %.5lf) ", (double)x, (double)y);
	}
};

bool onSegm(Point A, Point B, Point C) {
	return lseq((A - B) % (C - B), 0);
}

bool intersectLines(Point A, Point a, Point B, Point b, Point &I) {
	if (eq(a * b, 0)) return false;
	ld y = ((A - B) * a) / (b * a);
	I = B + b * y;
	return true;
}

ld PHI;

struct Segm {
	Point P, Q;

	Segm() : P(), Q() {}
	Segm(Point _P, Point _Q) {
		P = _P;
		Q = _Q;
		if (eq(P * Q, 0)) throw;
		if (P * Q < 0) swap(P, Q);
	}

	ld getPointInDir(const ld &phi) const {
		Point I;
		Point dd = Point(1, 0).rot(phi);
		if (!intersectLines(Point(), Point(1, 0).rot(phi), P, Q - P, I)) return -1;
//		if (ls(dd % I, 0)) return -1;
//		if (!onSegm(P, I, Q)) return -1;
		return I.sqrLen();
	}

	bool operator < (const Segm &S) const {
		return ls(getPointInDir(PHI), S.getPointInDir(PHI));
	}

	void eprint() {
		P.eprint();
		Q.eprint();
		eprintf("\n");
	}
};

const int N = 100100;
Point a[N];
Point b[N][2];
ld c[N];
vector<Segm> ev[N][2];
int n, m;
set<Segm> setik;

void eprintSet() {
	eprintf("setik:\n");
	for (Segm S : setik)
		S.eprint();
	eprintf("---------\n");
}

void read() {
	int q;
	scanf("%d", &q);
	while(q--) {
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			a[i].scan();
		a[k] = a[0];
		for (int i = 0; i < k; i++) {
			b[n][0] = a[i];
			b[n][1] = a[i + 1];
			n++;
		}
		for (int i = 0; i < k; i++)
			c[m++] = atan2l(a[i].y, a[i].x);
	}
	sort(c, c + m);
	int mm = 0;
	for (int i = 0; i < m; i++) {
		if (mm == 0 || !eq(c[i], c[mm - 1]))
			c[mm++] = c[i];
	}
	m = mm;
	c[m] = c[0] + 2 * PI;
	PHI = (c[m - 1] + c[m]) / 2;
	for (int i = 0; i < n; i++) {
		Point P = b[i][0], Q = b[i][1];
		if (eq(P * Q, 0)) continue;
		Segm S = Segm(P, Q);
		ld ang1 = atan2l(S.P.y, S.P.x), ang2 = atan2l(S.Q.y, S.Q.x);
		int pos1 = lower_bound(c, c + m, ang1 - eps) - c;
		int pos2 = lower_bound(c, c + m, ang2 - eps) - c;
		ev[pos1][0].push_back(S);
		ev[pos2][1].push_back(S);
		if (pos1 > pos2) setik.insert(S);
	}
}

ld getArea2(Segm S, ld phi1, ld phi2) {
	ld A = S.getPointInDir(phi1), B = S.getPointInDir(phi2);
	if (A < -0.5 || B < -0.5) throw;
	return sinl(phi2 - phi1) * sqrtl(A * B) / 2;
}
ld getArea(ld phi1, ld phi2) {
//	eprintf("getArea %.5lf %.5lf\n", (double)phi1, (double)phi2);
//	eprintSet();
	if (setik.empty()) return 0;
//	if ((int)setik.size() == 1) throw;
	if ((int)setik.size() == 1) return 0;
	Segm S1, S2;
	auto it = setik.begin();
	S1 = *it;
	it++;
	S2 = *it;
	return getArea2(S2, phi1, phi2) - getArea2(S1, phi1, phi2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
//	eprintf("after read\n");
//	for (int i = 0; i <= m; i++)
//		eprintf("%.5lf ", (double)c[i]);
//	eprintf("\n");
	ld ans = 0;
	for (int i = 0; i < m; i++) {
		for (Segm S : ev[i][1]) {
			setik.erase(S);
		}
		PHI = (c[i] + c[i + 1]) / 2;
		for (Segm S : ev[i][0]) {
			setik.insert(S);
		}
		ans += getArea(c[i], c[i + 1]);
	}
	printf("%.13lf\n", (double)ans);

	return 0;
}