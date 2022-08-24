//  Codeforces Beta Round #74

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1.0);
int sig(double r) { return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }

struct PT {
    double x, y, z;
    PT() {}
    PT(double x, double y, double z) : x(x), y(y), z(z) {}
    PT operator+(const PT &a) const { return PT(x + a.x, y + a.y, z + a.z); }
    PT operator-(const PT &a) const { return PT(x - a.x, y - a.y, z - a.z); }
    PT operator-() const { return PT(-x, -y, -z); }
    PT operator*(const double &k) const { return PT(x * k, y * k, z * k); }
    PT operator/(const double &k) const { return PT(x / k, y / k, z / k); }
    double abs() const { return sqrt(x * x + y * y + z * z); }
    double abs2() const { return x * x + y * y + z * z; }
    double dot(const PT &a) const { return x * a.x + y * a.y + z * a.z; }
    PT cross(const PT a) const { return PT(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x); }
    bool operator<(const PT &a) const { return (x != a.x) ? (x < a.x) : (y != a.y) ? (y < a.y) : (z < a.z); }
    bool operator==(const PT &a) const { return (sig(x - a.x) == 0) && (sig(y - a.y) == 0) && (sig(z - a.z) == 0); }
};
ostream &operator<<(ostream &os, const PT &a) { os << "(" << a.x << ", " << a.y << ", " << a.z << ")"; return os; }
PT tri(PT a, PT b, PT c) { return (b - a).cross(c - a); }
double tet(PT a, PT b, PT c, PT d) { return (b - a).cross(c - a).dot(d - a); }

PT A, V;
double S;
int N;
PT O[110];
double R[110];
int M[110];
PT P[110][110];

double ans;

void solve(PT p, double d) {
    double a = V.abs2();
    double b = V.dot(A - p);
    double c = (A - p).abs2() - d * d;
    double delta = b * b - a * c;
    if (sig(delta) < 0) return;
    delta = sqrt(max(delta, 0.0));
    double t0 = (-b - delta) / a;
    double t1 = (-b + delta) / a;
    if (sig(t0) > 0) chmin(ans, t0);
    if (sig(t1) > 0) chmin(ans, t1);
}

int main() {
    int i, j;
    
    for (; ~scanf("%lf%lf%lf", &A.x, &A.y, &A.z); ) {
        scanf("%lf%lf%lf", &V.x, &V.y, &V.z);
        scanf("%lf", &S);
        N = in();
        for (i = 0; i < N; ++i) {
            scanf("%lf%lf%lf", &O[i].x, &O[i].y, &O[i].z);
            scanf("%lf", &R[i]);
            M[i] = in();
            for (j = 0; j < M[i]; ++j) {
                scanf("%lf%lf%lf", &P[i][j].x, &P[i][j].y, &P[i][j].z);
            }
        }
        ans = INF;
        for (i = 0; i < N; ++i) {
            solve(O[i], S + R[i]);
        }
        for (i = 0; i < N; ++i) {
            for (j = 0; j < M[i]; ++j) {
                solve(O[i] + P[i][j], S);
            }
        }
        if (ans >= INF) {
            puts("-1");
            continue;
        }
        printf("%.10f\n", ans);
    }
    
    return 0;
}