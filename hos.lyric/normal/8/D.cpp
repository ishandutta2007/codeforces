//  Codeforces Beta Round #8
//  Problem D

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1.0);
int sig(double r) { return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }

struct Pt {
    double x, y;
    Pt() {}
    Pt(double x, double y) : x(x), y(y) {}
    Pt operator+(const Pt &a) { return Pt(x + a.x, y + a.y); }
    Pt operator-(const Pt &a) { return Pt(x - a.x, y - a.y); }
    Pt operator*(const Pt &a) { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
    Pt operator/(const Pt &a) { return Pt(dot(a) / a.norm(), -det(a) / a.norm()); }
    Pt operator-() { return Pt(-x, -y); }
    Pt operator*(const double &k) { return Pt(x * k, y * k); }
    Pt operator/(const double &k) { return Pt(x / k, y / k); }
    double abs() const { return sqrt(x * x + y * y); }
    double norm() const { return x * x + y * y; }
    double arg() const { return atan2(y, x); }
    double dot(Pt a) const { return x * a.x + y * a.y; }
    double det(Pt a) const { return x * a.y - y * a.x; }
};
namespace std {
    bool operator<(const Pt &a, const Pt &b) { return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y); }
    bool operator==(const Pt &a, const Pt &b) { return (sig(a.x - b.x) == 0) && (sig(a.y - b.y) == 0); }
    ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
}
Pt unit(Pt a) { return a / a.abs(); }
double tri(Pt a, Pt b, Pt c) { return (b - a).det(c - a); }

int iCC(Pt a, double r, Pt b, double s) {
    double d = (b - a).abs();
    if (sig(d) == 0 && sig(r - s) == 0) return -1;  //  correspond
    if (sig(r - s - d) > 0) return 2;   //  r > s
    if (sig(s - r - d) > 0) return -2;  //  s > r
    return (sig(r + s - d) >= 0) ? 1 : 0;
}
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
    double d = (b - a).abs();
    double x = (d * d + r * r - s * s) / (d * 2);
    double y = sqrt(max(r * r - x * x, 0.0));
    Pt e = (b - a) / d;
    return mp(a + e * x + e * Pt(0, 1) * y, a + e * x - e * Pt(0, 1) * y);
}

bool iCCC(Pt a, double r, Pt b, double s, Pt c, double t) {
    int ibc = iCC(b, s, c, t), ica = iCC(c, t, a, r), iab = iCC(a, r, b, s);
    if (ibc == +2) return ica;
    if (ibc == -2) return iab;
    if (ica == +2) return iab;
    if (ica == -2) return ibc;
    if (iab == +2) return ibc;
    if (iab == -2) return ica;
    pair<Pt,Pt> ps;
    if (ibc) {
        ps = pCC(b, s, c, t);
        if (sig((ps.first - a).abs() - r) <= 0) return 1;
        if (sig((ps.second - a).abs() - r) <= 0) return 1;
    }
    if (ica) {
        ps = pCC(c, t, a, r);
        if (sig((ps.first - b).abs() - s) <= 0) return 1;
        if (sig((ps.second - b).abs() - s) <= 0) return 1;
    }
    if (iab) {
        ps = pCC(a, r, b, s);
        if (sig((ps.first - c).abs() - t) <= 0) return 1;
        if (sig((ps.second - c).abs() - t) <= 0) return 1;
    }
//cout<<a<<" "<<r<<"  "<<b<<" "<<s<<"  "<<c<<" "<<t<<endl;
    return 0;
}

int main() {
    double s, t;
    Pt A, B, C;
    
    s = in();
    t = in();
    A.x = in(); A.y = in();
    C.x = in(); C.y = in();
    B.x = in(); B.y = in();
    
    double ab = (A - B).abs(), bc = (B - C).abs(), ac = (A - C).abs();
    double ss = ab + bc + s, tt = ac + t;
    
    if (ab + bc <= tt + EPS) {
        printf("%.10f\n", min(ss, tt));
        return 0;
    }
    
    double lo = 0.0, ho = min(ss - bc, tt);
    for (int reps = 50; reps--; ) {
        double mo = (lo + ho) / 2.0;
        iCCC(A, mo, B, ss - bc - mo, C, tt - mo) ? lo = mo : ho = mo;
    }
    
    printf("%.10f\n", lo);
    
    return 0;
}