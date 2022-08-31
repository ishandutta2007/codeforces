//  Codeforces Beta Round #2
//  Problem C

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
inline int sig(double r) { return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }

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
inline double tri(Pt a, Pt b, Pt c) { return (b - a).det(c - a); }

Pt proj(Pt a, Pt b) {
    return a * a.dot(b) / a.norm();
}
Pt perp(Pt a, Pt b, Pt c) {
    return a + proj(b - a, c - a);
}

int iLL(Pt a, Pt b, Pt c, Pt d) {
    if (sig((b - a).det(d - c))) return 1;  //  intersect
    if (sig((b - a).det(c - a))) return 0;  //  parallel
    return -1;  //  correspond
}
int iCC(Pt a, double r, Pt b, double s) {
    double d = (b - a).abs();
    if (sig(d) == 0 && sig(r - s) == 0) return -1;  //  correspond
    if (sig(r - s - d) > 0) return 2;   //  r > s
    if (sig(s - r - d) > 0) return -2;  //  s > r
    return (sig(r + s - d) >= 0) ? 1 : 0;
}
int iCL(Pt a, double r, Pt b, Pt c) {
    double d = abs(tri(b, c, a)) / (c - b).abs();
    return (sig(r - d) >= 0) ? 1 : 0;
}

Pt pLL(Pt a, Pt b, Pt c, Pt d) {
    b = b - a; d = d - c;
    return a + b * (c - a).det(d) / b.det(d);
}
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
    double d = (b - a).abs();
    double x = (d * d + r * r - s * s) / (d * 2);
    double y = sqrt(max(r * r - x * x, 0.0));
    Pt e = (b - a) / d;
    return mp(a + e * x + e * Pt(0, 1) * y, a + e * x - e * Pt(0, 1) * y);
}
pair<Pt,Pt> pCL(Pt a, double r, Pt b, Pt c) {
    Pt h = perp(b, c, a);
    double d = (h - a).abs();
    double y = sqrt(max(r * r - d * d, 0.0));
    Pt e = (c - b) / (c - b).abs();
    return mp(h + e * y, h - e * y);
}

Pt A, B, C;
double X, Y, Z;
double sho = -1.0;
Pt pm;

bool valid(Pt p) {
    double a = (p - A).abs() / X, b = (p - B).abs() / Y, c = (p - C).abs() / Z;
    return (sig(b - a) == 0 && sig(c - a) == 0);
}

void check(Pt p) {
    if (!valid(p)) return;
    double tmp = (p - A).norm();
    if (sho < 0.0 || sho > tmp) {
        sho = tmp;
        pm = p;
    }
}
void check(pair<Pt,Pt> ps) {
    check(ps.first);
    check(ps.second);
}

int main() {
    Pt b, b2, c, c2;
    double rb = 0, rc = 0;
    
    A.x = in(); A.y = in(); X = in();
    B.x = in(); B.y = in(); Y = in();
    C.x = in(); C.y = in(); Z = in();
    
    if (X == Y) {
        b = (A + B) / 2.0;
        b2 = b + (B - A) * Pt(0, 1);
    } else {
        b = (A * Y * Y - B * X * X) / (Y * Y - X * X);
        rb = (B - A).abs() * X * Y / (Y * Y - X * X);
    }
    if (X == Z) {
        c = (A + C) / 2.0;
        c2 = c + (C - A) * Pt(0, 1);
    } else {
        c = (A * Z * Z - C * X * X) / (Z * Z - X * X);
        rc = (C - A).abs() * X * Z / (Z * Z - X * X);
    }
    
    if (X == Y) {
        if (X == Z) {
            //if (iLL(b, b2, c, c2) == 1) 
            check(pLL(b, b2, c, c2));
        } else {
            //if (iCL(c, rc, b, b2) == 1) 
            check(pCL(c, rc, b, b2));
        }
    } else {
        if (X == Z) {
            //if (iCL(b, rb, c, c2) == 1) 
            check(pCL(b, rb, c, c2));
        } else {
            //if (iCC(b, rb, c, rc) == 1) 
            check(pCC(b, rb, c, rc));
        }
    }
    
    if (sho >= 0.0) {
        if (abs(pm.x) < 0.000005) pm.x = 0;
        if (abs(pm.y) < 0.000005) pm.y = 0;
        printf("%.5f %.5f\n", pm.x, pm.y);
    }
    
    return 0;
}