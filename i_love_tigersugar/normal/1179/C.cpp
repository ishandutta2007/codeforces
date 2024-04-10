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

struct SegmentTree {
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
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
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

    int firstNegative(void) {
        pushDown(1);
        if (tree[1] >= 0) return -1;

        int i = 1, l = 1, r = n;
        while (true) {
            if (l == r) return r;
            pushDown(i);
            int m = (l + r) >> 1;
            if (tree[2 * i + 1] < 0) {
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }
};

#define MAX   1000100
#define CHANGE_DISH   1
#define CHANGE_PERSON   2
int numDish, numPerson, numQuery;
int dishes[MAX], people[MAX];

void process(void) {
    SegmentTree myit(MAX);
    scanf("%d%d", &numDish, &numPerson);

    FOR(i, 1, numDish) {
        int x; scanf("%d", &x);
        dishes[i] = x;
        myit.update(1, x, -1);
    }
    FOR(i, 1, numPerson) {
        int x; scanf("%d", &x);
        people[i] = x;
        myit.update(1, x, 1);
    }

    scanf("%d", &numQuery);
    REP(love, numQuery) {
        int t, u, c; scanf("%d%d%d", &t, &u, &c);
        if (t == 1) {
            int prev = dishes[u]; dishes[u] = c;
            if (prev < c) myit.update(prev + 1, c, -1);
            if (prev > c) myit.update(c + 1, prev, 1);
        } else {
            int prev = people[u]; people[u] = c;
            if (prev < c) myit.update(prev + 1, c, 1);
            if (prev > c) myit.update(c + 1, prev, -1);
        }
        printf("%d\n", myit.firstNegative());
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/