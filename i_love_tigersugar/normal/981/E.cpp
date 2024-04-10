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

#define MAX   10010
typedef bitset<MAX> BitSet;

class SegmentTree {
private:
    struct Node {
        vector<int> queries;
        BitSet values;

        Node() {
            values = BitSet().flip(0);
        }
    };

    vector<Node> tree;
    int n;

    void update(int i, int l, int r, int u, int v, int x) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) return tree[i].queries.push_back(x);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, x);
        update(2 * i + 1, m + 1, r, u, v, x);
    }

    void calc(int i, int l, int r, BitSet &res) {
        if (l > r) return;

        BitSet &cur = tree[i].values;
        FORE(it, tree[i].queries) {
            cur |= cur << *it;
        }
        if (l == r) {
            res |= cur;
            return;
        }

        int m = (l + r) >> 1;
        FOR(j, 2 * i, 2 * i + 1) tree[j].values = tree[i].values;
        calc(2 * i, l, m, res);
        calc(2 * i + 1, m + 1, r, res);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, Node());
    }

    void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    BitSet finalCalc(void) {
        BitSet res;
        calc(1, 1, n, res);
        return res;
    }
};

void process(void) {
    int n, q; scanf("%d%d", &n, &q);
    SegmentTree myit(n);
    REP(love, q) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        myit.update(l, r, x);
    }

    BitSet res = myit.finalCalc();
    vector<int> values;
    FOR(i, 1, n) if (res[i]) values.push_back(i);
    printf("%d\n", (int)values.size());
    FORE(it, values) printf("%d ", *it); printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/