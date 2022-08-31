//  Codeforces Beta Round #60

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
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



int N;
int U, V;
PT P[10010], S;
double ts[10010];

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i <= N; ++i) {
            P[i].x = in();
            P[i].y = in();
            P[i].z = in();
        }
        V = in();
        U = in();
        S.x = in();
        S.y = in();
        S.z = in();
        for (i = 0; i < N; ++i) {
            ts[i + 1] = ts[i] + (P[i + 1] - P[i]).abs() / U;
        }
        for (i = 0; i <= N; ++i) {
            if (sig((P[i] - S).abs() / V - ts[i]) <= 0) {
                break;
            }
        }
        if (i > N) {
            puts("NO");
            continue;
        }
        if (i == 0) {
            puts("YES");
            printf("%.10f\n", 0.0);
            printf("%.10f %.10f %.10f\n", P[0].x, P[0].y, P[0].z);
            continue;
        }
        double lo = 0.0, ho = 1.0;
        for (int reps = 100; reps--; ) {
            double mo = (lo + ho) / 2.0;
            PT p = P[i - 1] * (1.0 - mo) + P[i] * mo;
            double t = ts[i - 1] * (1.0 - mo) + ts[i] * mo;
            if (((p - S).abs() / V - t) <= 0) {
                ho = mo;
            } else {
                lo = mo;
            }
        }
        PT p = P[i - 1] * (1.0 - ho) + P[i] * ho;
        double t = ts[i - 1] * (1.0 - ho) + ts[i] * ho;
        puts("YES");
        printf("%.10f\n", t);
        printf("%.10f %.10f %.10f\n", p.x, p.y, p.z);
    }
    
    return 0;
}