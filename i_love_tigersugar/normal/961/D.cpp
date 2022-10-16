#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    bool operator < (const Point &p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
    bool operator == (const Point &p) const {
        return x == p.x && y == p.y;
    }
};

struct Line {
    int a, b;
    long long c;

    Line() {
        a = b = c = 0;
    }
    Line(const Point &m, const Point &n) {
        a = m.y - n.y;
        b = n.x - m.x;
        c = -(1LL * a * m.x + 1LL * b * m.y);
        assert(1LL * a * n.x + 1LL * b * n.y + c == 0);
    }

    bool inside(const Point &p) const {
        return 1LL * a * p.x + 1LL * b * p.y + c == 0;
    }
};

bool inOneLine(const vector<Point> &points) {
    if (points.size() < 3) return true;
    Line line(points[0], points[1]);
    FORE(it, points) if (!line.inside(*it)) return false;
    return true;
}

bool inTwoLine(const vector<Point> &points, const Line &line) {
    vector<Point> rem;
    FORE(it, points) if (!line.inside(*it)) rem.push_back(*it);
    return inOneLine(rem);
}

bool canDraw(const vector<Point> &points) {
    if (points.size() < 3) return true;
    REP(i, 3) {
        int j = (i + 1) % 3;
        if (inTwoLine(points, Line(points[i], points[j]))) return true;
    }
    return false;
}

int main(void) {
    int n;
    while (scanf("%d", &n) == 1) {
        vector<Point> points(n);
        REP(i, n) scanf("%d%d", &points[i].x, &points[i].y);
        cout << (canDraw(points) ? "YES" : "NO") << endl;
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/