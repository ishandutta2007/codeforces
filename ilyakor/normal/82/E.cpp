#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

typedef double D;
const D eps = 1E-8;

struct P
{
    D x, y;
    P(D x = 0.0, D y = 0.0) : x(x), y(y) {} 
    P operator+(P a)
    {
        return P(x + a.x, y + a.y);
    }
    P operator-(P a)
    {
        return P(x - a.x, y - a.y);
    }
    P operator*(D k)
    {
        return P(x * k, y * k);
    }
    D operator *(P a)
    {
        return x * a.y - y * a.x;
    }
    D operator ^(P a)
    {
        return x * a.x + y * a.y;
    }
    D len()
    {
        return sqrt(x * x + y * y);
    }
    P perp()
    {
        return P(y, -x);
    }
    P norm()
    {
        D l = len();
        return abs(l) < eps ? P(x, y) : P(x / l, y / l);
    }
    bool operator==(P a)
    {
        return abs(x - a.x) < eps && abs(y - a.y) < eps;
    }
    void load()
    {
        cin >> x >> y;
    }
};

int sgn(D x)
{
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}

bool pointOnSegment(P p, P a, P b)
{
    if (abs((a - p) * (b - p)) > eps) 
        return false;
    return ((a - p) ^ (b - p)) < eps;
}

bool crossSegments1d(D a, D aa, D b, D bb)
{
    return min(a, aa) < max(b, bb) + eps && min(b, bb) < max(a, aa) + eps;  
}

bool crossSegments(P a, P aa, P b, P bb)
{
    if (sgn((b - a) * (aa - a)) * sgn((aa - a) * (bb - a)) < 0)
        return false;
    if (sgn((a - b) * (bb - b)) * sgn((bb - b) * (aa - b)) < 0)
        return false;
    return crossSegments1d(a.x, aa.x, b.x, bb.x) && crossSegments1d(a.y, aa.y, b.y, bb.y);
}

struct L
{
    D a, b, c;
    L(D a = 0.0, D b = 0.0, D c = 0.0): a(a), b(b), c(c) {}
    bool operator||(L l) {
        return abs(a * l.b - b * l.a) < eps;
    }
};

L getLine(P p1, P p2)
{
    D x0 = p1.x, y0 = p1.y;
    D al = (p2 - p1).x, be = (p2 - p1).y;
    return L(be, -al, al * y0 - be * x0);
}

P getPoint(L l1, L l2)
{
    D det = l1.a * l2.b - l1.b * l2.a;
    D det1 = -(l1.c * l2.b - l1.b * l2.c);
    D det2 = -(l1.a * l2.c - l1.c * l2.a);
    return P(det1 / det, det2 / det);
}

D h, f;

pair<D, D> calc1(D y, D x1, D x2) {
    D l = x1 * (f - y) / (f - h);
    D r = x2 * (f - y) / (f - h);
    return mp(l, r);
}

pair<D, D> calc2(D y, D x1, D x2) {
    D l = x1 * (y + f) / (f - h);
    D r = x2 * (y + f) / (f - h);
    return mp(l, r);
}


int main()
{
    int n;
    cin >> n;
    cin >> h >> f;
    vector<ii> v(n);
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
        D l = abs(v[i].second - v[i].first);
        res += 2. * h * (l + l * (f + h) / (f - h));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<P> V;
            L l11 = getLine(P(0, f), P(v[i].first, h));
            L l12 = getLine(P(0, f), P(v[i].second, h));
            L l21 = getLine(P(0, -f), P(v[j].first, -h));
            L l22 = getLine(P(0, -f), P(v[j].second, -h));
            if (!(l11 || l21))
                V.pb(getPoint(l11, l21));
            if (!(l11 || l22))
                V.pb(getPoint(l11, l22));
            if (!(l12 || l21))
                V.pb(getPoint(l12, l21));
            if (!(l12 || l22))
                V.pb(getPoint(l12, l22));
            vector<D> ev;
            ev.pb(-h);
            ev.pb(-h);
            ev.pb(h);
            ev.pb(h);
            for (int k = 0; k < sz(V); ++k) {
                if (abs(V[k].y) < h + eps)
                    ev.pb(V[k].y);
            }
            sort(all(ev));
            double cur = 0;
            double st = 0.0;
            for (int k = 1; k < sz(ev); ++k) {
                pair<double, double> p = calc1(ev[k], v[i].first, v[i].second);
                pair<double, double> q = calc2(ev[k], v[j].first, v[j].second);
                double l = max(p.first, q.first);
                double r = min(p.second, q.second);
                double t = max(0.0, r - l);
                cur += (t + st) * 0.5 * (ev[k] - ev[k - 1]);
                st = t;
            }
            /*vector<P> w;
            for (int i = 0; i < sz(V); ++i) {
                int j = (i + 1) % sz(V);
                bool fl1 = V[i].y < h + eps && V[i].y > -h -eps;
                bool fl2 = V[j].y < h + eps && V[j].y > -h -eps;
                if (fl1) {
                    w.pb(V[i]);                 
                }
                if (fl1 ^ fl2) {
                    L l = getLine(V[i], V[j]);
                    L l1 = getLine(P(0, -h), P(1, -h));
                    P tmp = getPoint(l, l1);
                    if (!pointOnSegment(tmp, V[i], V[j])) {
                        l1 = getLine(P(0, h), P(1, h));
                        tmp = getPoint(l, l1);
                    }
                    w.pb(tmp);
                }
            }
            D cur = 0.0;
            for (int i = 0; i < sz(w); ++i) {
                int j = (i + 1) % sz(w);
                cur += w[i] * w[j];
            }*/
            res -= abs(cur);
        }
    }
    printf("%.10lf\n", res);
    return 0;
}