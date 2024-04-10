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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE.  **/

class SegmentTree {
private:
    vector<int> tree, lazy;
    int n;

    void pushDown(int i) {
        FOR(j, 2 * i, 2 * i + 1) {
            tree[j] += lazy[i];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int c) {
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

public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n > 0) {
            tree.assign(4 * n + 7, 0);
            lazy.assign(4 * n + 7, 0);
        }
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }

    int getMax(void) const {
        return tree[1];
    }
};

#define MAX   300300
int p[MAX], q[MAX], n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        p[x] = i;
    }
    FOR(i, 1, n) scanf("%d", &q[i]);

    int cur = n;
    SegmentTree myit(n);
    myit.update(1, p[n], 1);

    FOR(i, 1, n) {
        while (myit.getMax() <= 0) {
            assert(cur > 1);
            cur--;
            myit.update(1, p[cur], 1);
        }
        printf("%d ", cur);
        myit.update(1, q[i], -1);
    }

    printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/