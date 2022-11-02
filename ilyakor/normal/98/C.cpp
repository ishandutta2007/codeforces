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

struct P {
    D x, y;
    P(D x = 0.0, D y = 0.0) : x(x), y(y) {} 
    P operator+(P a) {
        return P(x + a.x, y + a.y);
    }
    P operator-(P a) {
        return P(x - a.x, y - a.y);
    }
    P operator*(D k) {
        return P(x * k, y * k);
    }
    D operator *(P a) {
        return x * a.y - y * a.x;
    }
    D operator ^(P a) {
        return x * a.x + y * a.y;
    }
    D len() {
        return sqrt(x * x + y * y);
    }
    P perp() {
        return P(y, -x);
    }
    P norm() {
        D l = len();
        return abs(l) < eps ? P(x, y) : P(x / l, y / l);
    }
    bool operator==(P a) {
        return abs(x - a.x) < eps && abs(y - a.y) < eps;
    }
    void load() {
        cin >> x >> y;
    }
};

int sgn(D x)
{
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}

bool pointOnSegment(P p, P a, P b) {
    if (abs((a - p) * (b - p)) > eps) 
        return false;
    return ((a - p) ^ (b - p)) < eps;
}

bool crossSegments1d(D a, D aa, D b, D bb) {
    return min(a, aa) < max(b, bb) + eps && min(b, bb) < max(a, aa) + eps;  
}

bool crossSegments(P a, P aa, P b, P bb) {
    if (sgn((b - a) * (aa - a)) * sgn((aa - a) * (bb - a)) < 0)
        return false;
    if (sgn((a - b) * (bb - b)) * sgn((bb - b) * (aa - b)) < 0)
        return false;
    return crossSegments1d(a.x, aa.x, b.x, bb.x) && crossSegments1d(a.y, aa.y, b.y, bb.y);
}

struct L {
    D a, b, c;
    L(D a = 0.0, D b = 0.0, D c = 0.0): a(a), b(b), c(c) {}
};

L getLine(P p1, P p2) {
    D x0 = p1.x, y0 = p1.y;
    D al = (p2 - p1).x, be = (p2 - p1).y;
    return L(be, -al, al * y0 - be * x0);
}

P getPoint(L l1, L l2) {
    D det = l1.a * l2.b - l1.b * l2.a;
    D det1 = -(l1.c * l2.b - l1.b * l2.c);
    D det2 = -(l1.a * l2.c - l1.c * l2.a);
    return P(det1 / det, det2 / det);
}

const D pi = 2. * asin(1.);

P p0;

D calc(D alpha, D l, D w) {
    P p1(0., l * sin(alpha));
    P p2(l * cos(alpha), 0.);
    P dir(w * sin(alpha), w * cos(alpha));
    p1 = p1 + dir;
    p2 = p2 + dir;
    L l0 = getLine(p2, p1); 
    D val = l0.a * p0.x + l0.b * p0.y + l0.c;
    val /= sqrt(sqr(l0.a) + sqr(l0.b));
    //cerr << (p1 - p2).len() << " " << dir.len() << " " << (dir ^ (p1 - p2)) << " " << val << "\n";
    return val;
}

D calc(D L, D w) {
    D l = 0.0, r = pi * 0.5;
    if (calc(l, L, w) < -eps) return -1.0;
    if (calc(r, L, w) < -eps) return -1.0;
    for (int it = 0; it < 300; ++it) {
        D l2r = (2 * l + r) / 3.;
        D lr2 = (l + 2 * r) / 3.;
        D v1 = calc(l2r, L, w);
        D v2 = calc(lr2, L, w);
        if (v1 < v2) 
            r = lr2;
        else
            l = l2r;
    }
    return calc((l + r) * 0.5, L, w);
}

int main()
{
    double a, b, l;
    cin >> a >> b >> l;
    p0 = P(b, a);
    double down = 0.0, up = l;
    down = min(down, up);
    for (int it = 0; it < 130; ++it) {
        D t = (up + down) * 0.5;
        if (calc(l, t) < 0.)
            up = t;
        else
            down = t;
    }
    D res = (up + down) * 0.5;
    if (calc(l, res) < -eps)
        res = -1E100;
    cerr << res << calc(l, res) << "\n";
    if (l < b + eps)
        res = max(res, min(a, l));
    if (l < a + eps) {
        res = max(res, min(b, l));
    }
    res = min(res, l);
    if (res < 1E-7)
        printf("My poor head =(\n");
    else
    printf("%.10lf\n", res);
    return 0;
}