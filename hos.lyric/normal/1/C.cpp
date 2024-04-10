//  Codeforces Beta Round #1
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

Pt circenter(Pt a, Pt b, Pt c) {
    Pt bc = c - b, ca = a - c, ab = b - a;
    return (b + c - bc * Pt(0, 1) * ca.dot(ab) / ca.det(ab)) / 2;
}

const double EPS2 = 1e-5;

int main() {
    Pt a, b, c, o;
    double rr;
    double A, B;
    
    scanf("%lf%lf", &a.x, &a.y);
    scanf("%lf%lf", &b.x, &b.y);
    scanf("%lf%lf", &c.x, &c.y);
    o = circenter(a, b, c);
    a = a - o;
    b = b - o;
    c = c - o;
    rr = a.norm();
    A = acos(b.dot(c) / rr);
    B = acos(c.dot(a) / rr);
    
    for (int n = 3; n < 1005; ++n) {
        double U = PI * 2 / n;
        double AA = floor(A / U + 0.5) * U, BB = floor(B / U + 0.5) * U;
        if (abs(AA - A) < EPS2 && abs(BB - B) < EPS2) {
            printf("%.8f\n", rr * n * sin(U) / 2.0);
            return 0;
        }
    }
    
    return 0;
}