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
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
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

pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return mp(a + e * x - w, a + e * x + w);
}

int N;
double D;
Pt P[20010];
double R[20010];

int psLen;
pair<double,int> ps[1000010];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		D = in();
		for (int i = 0; i < N; ++i) {
			P[i].x = in();
			P[i].y = in();
			R[i] = in();
		}
		for (int i = 0; i < N; ++i) {
			P[i] = P[i] * Pt(cos(0.1), sin(0.1));
		}
		int now = 0;
		psLen = 0;
		for (int i = 0; i < N; ++i) {
			const double minDist = P[i].abs() - R[i];
			const double maxDist = P[i].abs() + R[i];
			const int minHit = ceil(minDist / D - EPS);
			const int maxHit = floor(maxDist / D + EPS);
			for (int hit = minHit; hit <= maxHit; ++hit) {
				const auto res = pCC(Pt(0, 0), hit * D, P[i], R[i]);
				double tBeg = res.first.arg();
				double tEnd = res.second.arg();
// cout<<res.first<<" "<<res.second<<endl;
// cout<<" "<<tBeg<<" "<<tEnd<<endl;
				if (sig(tEnd - tBeg) == 0) {
					const double tMid = (tBeg + tEnd) / 2.0;
					tBeg = tMid - EPS;
					tEnd = tMid + EPS;
				}
				if (sig(tEnd - tBeg) < 0) {
					++now;
				}
				ps[psLen++] = mp(tBeg, -1);
				ps[psLen++] = mp(tEnd, +1);
			}
		}
		sort(ps, ps + psLen);
// for(int j=0;j<psLen;++j)cout<<"("<<ps[j].first<<", "<<ps[j].second<<") ";cout<<endl;
		int ans = now;
		for (int j = 0; j < psLen; ++j) {
			now -= ps[j].second;
			chmax(ans, now);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}