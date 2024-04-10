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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Point operator + (const Point &a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }

    bool operator < (const Point &a) const {
        return y == a.y ? x < a.x : y < a.y;
    }
};

istream& operator >> (istream &is, Point &p) {
    return is >> p.x >> p.y;
}
ostream& operator << (ostream &os, const Point &p) {
    return os << p.x << " " << p.y;
}

int main(void) {
    Point points[5];
    REP(i, 3) cin >> points[i];
    set<Point> res;
    REP(i, 3) res.insert(points[i] + points[(i + 1) % 3] - points[(i + 2) % 3]);
    cout << res.size() << endl;
    FORE(it, res) cout << *it << "\n";
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/