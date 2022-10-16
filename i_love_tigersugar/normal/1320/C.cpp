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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const long long INF = (long long)1e18 + 7LL;

class SegmentTree {
private:
    int n;
    vector<long long> tree, lazy;

    void pushDown(int i) {
        FOR(j, 2 * i, 2 * i + 1) {
            tree[j] += lazy[i];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, long long c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i] += c;
            lazy[i] += c;
            return;
        }

        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    long long getMax(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return -INF;
        if (u <= l && r <= v) return tree[i];

        pushDown(i);
        int m = (l + r) >> 1;
        long long L = getMax(2 * i, l, m, u, v);
        long long R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n > 0) {
            tree.assign(4 * n + 7, 0);
            lazy.assign(4 * n + 7, 0);
        }
    }

    void update(int l, int r, long long c) {
        update(1, 1, n, l, r, c);
    }

    long long getMax(int l, int r) {
        return getMax(1, 1, n, l, r);
    }
};

struct Point {
    int x, y, value;

    Point() {
        x = y = value = 0;
    }

    void input(void) {
        scanf("%d%d%d", &x, &y, &value);
    }

    bool operator < (const Point &p) const {
        return y < p.y;
    }
};

#define MAX   1000100
int numX, numY, numPoint;
long long costX[MAX + 1], costY[MAX + 1];
vector<Point> points;

void init(void) {
    scanf("%d%d%d", &numX, &numY, &numPoint);
    memset(costX, 0x3f, sizeof costX);
    memset(costY, 0x3f, sizeof costY);

    REP(love, numX) {
        int x, c; scanf("%d%d", &x, &c);
        minimize(costX[x], c);
    }
    REP(love, numY) {
        int y, c; scanf("%d%d", &y, &c);
        minimize(costY[y], c);
    }

    points.assign(numPoint, Point());
    FORE(it, points) it->input();
    sort(ALL(points));
}

void process(void) {
    SegmentTree myit(MAX);
    FOR(i, 1, MAX) myit.update(i, i, -costX[i]);

    long long best = -INF;
    int j = 0;
    FOR(y, 1, MAX) {
        while (j < numPoint && points[j].y < y) {
            myit.update(points[j].x + 1, MAX, points[j].value);
            j++;
        }
        maximize(best, myit.getMax(1, MAX) - costY[y]);
    }

    cout << best << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/