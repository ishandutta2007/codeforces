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

const int INF = (int)1e9 + 7;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void update(int i, int l, int r, int pos, int value) {
        if (l == r) {
            tree[i] = value;
            return;
        }

        int m = (l + r) >> 1;
        if (pos > m) update(2 * i + 1, m + 1, r, pos, value);
        else update(2 * i, l, m, pos, value);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return -INF;
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        int L = getMax(2 * i, l, m, u, v);
        int R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, 0);
    }

    void update(int pos, int value) {
        update(1, 1, n, pos, value);
    }

    int getMax(int l, int r) const {
        return getMax(1, 1, n, l, r);
    }
};

#define MAX   200200
#define DIM   7

SegmentTree myit[MASK(DIM)];
int cord[MAX][DIM];
int numPoint, dim;

void addPoint(int id) {
    REP(mask, MASK(dim)) {
        int sum = 0;
        REP(j, dim) sum += BIT(mask, j) ? cord[id][j] : -cord[id][j];
        myit[mask].update(id, sum);
    }
}

int query(int l, int r) {
    int res = -INF;
    REP(mask, MASK(dim)) {
        int rev = (MASK(dim) - 1) ^ mask;
        maximize(res, myit[mask].getMax(l, r) + myit[rev].getMax(l, r));
    }
    return res;
}

void process(void) {
    scanf("%d%d", &numPoint, &dim);
    FOR(i, 1, numPoint) REP(j, dim) scanf("%d", &cord[i][j]);
    REP(mask, MASK(dim)) myit[mask] = SegmentTree(numPoint);
    FOR(i, 1, numPoint) addPoint(i);

    int numQuery; scanf("%d", &numQuery);
    REP(love, numQuery) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int pos; scanf("%d", &pos);
            REP(i, dim) scanf("%d", &cord[pos][i]);
            addPoint(pos);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", query(l, r));
        }
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/