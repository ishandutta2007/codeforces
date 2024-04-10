#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    bool sameDir(const Point &p) const {
        return 1LL * x * p.y == 1LL * y * p.x;
    }

    bool operator < (const Point &p) const {
        return y == p.y ? x < p.x : y < p.y;
    }

    bool operator != (const Point &p) const {
        return x != p.x || y != p.y;
    }
};

istream& operator >> (istream &is, Point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const Point &p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

const int INF = (int)1e6 + 7;
const Point NA(INF, INF);
#define BETWEEN(val, low, high) (((low) <= (val) && (val) <= (high)) || ((high) <= (val) && (val) <= (low)))

struct Line {
    int a, b;
    long long c;

    Line(int _a = 0, int _b = 0, long long _c = 0) {
        a = _a; b = _b; c = _c;
    }

    Line(const Point &m, const Point &n) {
        a = m.y - n.y;
        b = n.x - m.x;
        c = -(1LL * a * m.x + 1LL * b * m.y);
    }

    bool contain(const Point &p) const {
        return 1LL * a * p.x + 1LL * b * p.y + c == 0;
    }

    Point intersect(const Line &l) const {
        long long a1 = a, b1 = b, c1 = -c;
        long long a2 = l.a, b2 = l.b, c2 = -l.c;

        long long d = a1 * b2 - a2 * b1;
        if (d == 0) return NA;

        long long dx = c1 * b2 - c2 * b1;
        long long dy = a1 * c2 - a2 * c1;
        if (dx % d != 0 || dy % d != 0) return NA;

        long long x = dx / d, y = dy / d;
        return BETWEEN(x, -INF, INF) && BETWEEN(y, -INF, INF) ? Point(x, y) : NA;
    }

    bool operator < (const Line &l) const {
        if (a != l.a) return a < l.a;
        if (b != l.b) return b < l.b;
        return c < l.c;
    }
};

struct Segment {
    Point a, b;

    Segment(const Point &_a = Point(), const Point &_b = Point()) {
        a = _a; b = _b;
        if (b < a) swap(a, b);
    }

    bool contain(const Point &p) const {
        return BETWEEN(p.x, a.x, b.x) && BETWEEN(p.y, a.y, b.y) && Line(a, b).contain(p);
    }

    Point intersect(const Segment &s) const {
        Point p = Line(a, b).intersect(Line(s.a, s.b));
        return p != NA && contain(p) && s.contain(p) ? p : NA;
    }

    int numIntPoint(void) const {
        int dx = Abs(a.x - b.x), dy = Abs(a.y - b.y);
        return __gcd(dx, dy) + 1;
    }
};

#define MAX   2020
int comb[MAX * MAX];
void prepare(void) {
    memset(comb, -1, sizeof comb);
    FOR(i, 1, MAX) comb[i * (i - 1) / 2] = i;
}

int numSegment;
Segment segments[MAX];

void init(void) {
    cin >> numSegment;
    FOR(i, 1, numSegment) {
        Point a, b; cin >> a >> b;
        segments[i] = Segment(a, b);
    }
}

void addSegment(const vector<Segment> &seg) {
    vector<pair<Point, int>> points;
    FORE(it, seg) {
        assert(it-> a < it->b);
        points.push_back(make_pair(it->a, 1));
        points.push_back(make_pair(it->b, -1));
    }
    sort(ALL(points));
    assert(!points.empty() && points.front().se > 0 && points.back().se < 0);

    Point start;
    int cur = 0;
    FORE(it, points) {
        cur += it->se;
        if (cur == 0) segments[++numSegment] = Segment(start, it->fi);
        if (cur == 1 && it->se > 0) start = it->fi;
    }
}

void process(void) {
    map<Line, vector<Segment>> lines;
    FOR(i, 1, numSegment) {
        const Segment &s = segments[i];
        lines[Line(s.a, s.b)].push_back(s);
    }

    numSegment = 0;
    FORE(it, lines) addSegment(it->se);

    long long res = 0;
    FOR(i, 1, numSegment) res += segments[i].numIntPoint();
    cerr << "Temporary " << res << endl;

    map<Point, int> cnt;
    FOR(i, 1, numSegment) FOR(j, i + 1, numSegment) {
        Point tmp = segments[i].intersect(segments[j]);
        if (tmp != NA) cnt[tmp]++;
    }

    FORE(it, cnt) {
        int j = comb[it->se];
        assert(j >= 2);
        res -= j - 1;
    }

#ifdef ONLINE_JUDGE
    cout << res << " ";
#else
    cout << res << endl;
#endif // ONLINE_JUDGE
}

int main(void) {
#ifdef ONLINE_JUDGE
    //freopen("intpoint.inp", "r", stdin);
    //freopen("intpoint.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(false); cin.tie(NULL);
    prepare();

//    int subtask, t; cin >> subtask >> t;
    REP(love, 1) {
        init();
        process();
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/