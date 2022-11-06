#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;
typedef pair <pt, pt> seg;

const double PI = 3.1415926535897932384626433832795;

int tests;
vector <seg> v;
int p[3];

/*
bool cross (seg a, seg b, pair <double, double> &cr) {
    int a1 = a.Y.Y - a.X.Y, b1 = a.X.X - a.Y.X, c1 = -(a1 * a.X.X + b1 * a.X.Y);
    int a2 = b.Y.Y - b.X.Y, b2 = b.X.X - b.Y.X, c2 = -(a2 * b.X.X + b2 * b.X.Y);
    int det = (a1 * b2 - a2 * b1);
    if (det == 0) return false;
    int detx = (-c1 * b2 + c2 * b1), dety = (a1 * (-c2) - a2 * (-c1));
    cr.first = (detx + 0.0) / det;
    cr.second = (dety + 0.0) / det;
    return true;
}
*/

inline bool onSite (seg A, pt fir) {
    li a = A.Y.Y - A.X.Y, b = A.X.X - A.Y.X, c = -(A.X.X * 1ll * a + A.X.Y * 1ll * b);
    li t = a * fir.first + b * fir.second + c;
    if (t != 0) return false;
    li minx = A.X.X, maxx = A.Y.X;
    if (minx > maxx) swap(minx, maxx);
    li miny = A.X.Y, maxy = A.Y.Y;
    if (miny > maxy) swap(miny, maxy);
    li x = fir.first, y = fir.second;
    if (x < minx || x > maxx) return false;
    if (y < miny || y > maxy) return false;
    return true;
}

inline li dist (pt fir, pt sec) {
    int ax = fir.first - sec.first;
    int ay = fir.second - sec.second;
    li t1 = ax * 1ll * ax;
    li t2 = ay * 1ll * ay;
    return t1 + t2;
}

inline double ang (seg &A, seg &B) {
    li a1 = A.Y.Y - A.X.Y, b1 = A.X.X - A.Y.X;//, c1 = -(A.X.X * a1 + A.X.Y * b1);
    li a2 = B.Y.Y - B.X.Y, b2 = B.X.X - B.Y.X;//, c2 = -(B.X.X * a2 + B.X.Y * b2);
    li det = a1 * b2 - a2 * b1;
    if (det == 0) return 0;
    double fir = sqrt(dist(A.first, A.second) + 0.0);
    double sec = sqrt(dist(B.first, B.second) + 0.0);
    double thir = sqrt(dist(A.second, B.second) + 0.0);
    double an = acos((sqr(thir) - sqr(fir) - sqr(sec)) / (- 2.0 * fir * sec));
    return an;
}

bool check (seg a, seg b, seg c) {
    pt a1 = a.first, a2 = a.second;
    pt b1 = b.first, b2 = b.second;
    pt c1 = c.first, c2 = c.second;
    if (a1.X != b1.X || a1.Y != b1.Y) return false;
    if (!onSite(a, c1) || !onSite(b, c2)) return false;

    double an = ang(a, b);
    if (fabs(an) < EPS || an - EPS > PI / 2.0) return false;


    pt f1 = c1, f2 = c2;
    li d1 = dist(f1, a1), d2 = dist(f1, a2);
    if (d1 > d2) swap(d1, d2);
    if (d1 * 16 < d2) return false;

    d1 = dist(f2, b1), d2 = dist(f2, b2);
    if (d1 > d2) swap(d1, d2);
    if (d1 * 16 < d2) return false;
    
    return true;
}

int main()
{
    cin >> tests;
    while (tests > 0) {
        tests--;
        v.clear();
        forn(i, 3) {
            int ax, ay, bx, by;
            scanf("%d%d%d%d", &ax, &ay, &bx, &by);
            v.pb(mp(mp(ax, ay), mp(bx, by)));
            p[i] = i;
        }
        bool ok = false;
        do {
            forn(i, 8) {
                pt fir1 = v[p[0]].first, fir2 = v[p[0]].second;
                if (i & 1) swap(fir1, fir2);
                pt sec1 = v[p[1]].first, sec2 = v[p[1]].second;
                if (i & 2) swap(sec1, sec2);
                pt thir1 = v[p[2]].first, thir2 = v[p[2]].second;
                if (i & 4) swap(thir1, thir2);
                if (check(mp(fir1, fir2), mp(sec1, sec2), mp(thir1, thir2))) {
                    ok = true;
                    break;
                }
            }           
        } while (next_permutation(p, p + 3));
        if (ok) puts("YES"); else puts("NO");
    }
    return 0;
}