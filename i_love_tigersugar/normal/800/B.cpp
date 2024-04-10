#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   100100
#define SQRT(x) sqrt(max<double>(x, 0.0))

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }

    double modul(void) const {
        return SQRT(1LL * x * x + 1LL * y * y);
    }
};

istream &operator >> (istream &is, Point &p) {
    return is >> p.x >> p.y;
}

Point points[MAX];
int n;

void init(void) {
    cin >> n;
    REP(i, n) cin >> points[i];
}

long long area(const Point &a, const Point &b, const Point &c) {
    long long sum = 0;
    sum += 1LL * (a.x - b.x) * (a.y + b.y);
    sum += 1LL * (b.x - c.x) * (b.y + c.y);
    sum += 1LL * (c.x - a.x) * (c.y + a.y);
    return Abs(sum);
}

double distance(const Point &a, const Point &b, const Point &c) {
    return area(a, b, c) / (b - c).modul();
}

void process(void) {
    double res = INFINITY;
    REP(i, n) REP(j, n) if (i != j && (i + 1) % n != j)
        minimize(res, distance(points[j], points[i], points[(i + 1) % n]) / 2);

    REP(i, n) minimize(res, distance(points[(i + 1) % n], points[i], points[(i + 2) % n]) / 2);

    printf("%.9lf\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/