//  Codeforces Beta Round #58 (C)

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

    bool operator<(const Pt &a) const { return (x != a.x) ? (x < a.x) : (y < a.y); }

    bool operator==(const Pt &a) const { return (sig(x - a.x) == 0 && sig(y - a.y) == 0); }

};

ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }

double tri(Pt a, Pt b, Pt c) { return (b - a).det(c - a); }



Pt proj(Pt a, Pt b) {

    return a * a.dot(b) / a.abs2();

}

Pt perp(Pt a, Pt b, Pt c) {

    return a + proj(b - a, c - a);

}

Pt refl(Pt a, Pt b, Pt c) {

    return perp(a, b, c) * 2 - c;

}


int iSP(Pt a, Pt b, Pt c) {

    int s = sig((b - a).det(c - a));

    if (s) return s;

    if (sig((b - a).dot(c - a)) < 0) return -2; //  c-a-b

    if (sig((a - b).dot(c - b)) < 0) return +2; //    a-b-c

    return 0;

}

bool iSS(Pt a, Pt b, Pt c, Pt d) {

    return (iSP(a, b, c) * iSP(a, b, d) <= 0 && iSP(c, d, a) * iSP(c, d, b) <= 0);

}

Pt pLL(Pt a, Pt b, Pt c, Pt d) {

    b = b - a; d = d - c;

    return a + b * (c - a).det(d) / b.det(d);

}



int N;
Pt P[110][10];
int S[110][10];
int X, Y;
double xs[20010];
pair< double,pair<double,int> > ys[20010];

int main() {
    int u, v, i, j;
    int e, f;
    
    scanf("%d", &N);
    for (u = 0; u < N; ++u) {
        for (i = 0; i < 3; ++i) {
            scanf("%lf%lf", &P[u][i].x, &P[u][i].y);
            P[u][i] = P[u][i] * Pt(cos(1), sin(1));
            P[u][i + 3] = P[u][i];
        }
    }
    for (u = 0; u < N; ++u) {
        for (i = 0; i < 3; ++i) {
            xs[X++] = P[u][i].x;
        }
    }
    for (u = 0; u < N; ++u) for (v = u + 1; v < N; ++v) {
        for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j) {
            if (iSS(P[u][i], P[u][i + 1], P[v][j], P[v][j + 1])) {
                Pt p = pLL(P[u][i], P[u][i + 1], P[v][j], P[v][j + 1]);
                xs[X++] = p.x;
            }
        }
    }
    sort(xs, xs + X);
//pv(xs,xs+X);
    
    for (u = 0; u < N; ++u) {
        for (i = 0; i < 3; ++i) {
            if (P[u][i].x != P[u][i + 1].x) {
                S[u][i] = sig(tri(P[u][i], P[u][i + 1], P[u][i + 2])) * sig(tri(P[u][i], P[u][i + 1], Pt(P[u][i].x, INF)));
            }
        }
//pv(S[u],S[u]+3);
    }
    
    double ans = 0.0;
    for (e = 0; e < X - 1; ++e) {
        double xmid = (xs[e] + xs[e + 1]) / 2.0;
        Y = 0;
        for (u = 0; u < N; ++u) {
            for (i = 0; i < 3; ++i) {
                if (P[u][i].x != P[u][i + 1].x) {
                    if (sig(P[u][i].x - xmid) * sig(P[u][i + 1].x - xmid) <= 0) {
                        Pt p0 = pLL(P[u][i], P[u][i + 1], Pt(xs[e], 0), Pt(xs[e], 1));
                        Pt p1 = pLL(P[u][i], P[u][i + 1], Pt(xmid, 0), Pt(xmid, 1));
                        Pt p2 = pLL(P[u][i], P[u][i + 1], Pt(xs[e + 1], 0), Pt(xs[e + 1], 1));
                        ys[Y++] = mp(p1.y, mp((p2 - p0).abs(), S[u][i]));
                    }
                }
            }
        }
        sort(ys, ys + Y);
        int crt = 0, nxt;
//for(f=0;f<Y;++f)printf("%d ",ys[f].second.second);cout<<endl;
        for (f = 0; f < Y; ++f) {
            nxt = crt + ys[f].second.second;
            if (!!crt != !!nxt) {
                ans += ys[f].second.first;
            }
            crt = nxt;
        }
    }
    printf("%.10f\n", ans);
    
    return 0;
}