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

class SegmentTree {
    private:
    struct Node {
        int best, bestPrefix, bestSuffix;
        int incSuffix, decPrefix;
        long long firstValue, lastValue;
        int length;
        long long lazy;

        Node(int len = 0) {
            best = bestPrefix = bestSuffix = 1;
            incSuffix = decPrefix = 1;
            firstValue = lastValue = 0;
            length = len;
            lazy = 0;
        }

        void debug(void) const {
            printf("Best %d | %d | %d\n", best, bestPrefix, bestSuffix);
            printf("First %lld | Last %lld\n", firstValue, lastValue);
            printf("IncSuf %d | DecPre %d\n", incSuffix, decPrefix);
            printf("Length %d | Lazy %lld\n", length, lazy);
        }

    };

    int n;
    vector<Node> tree;

    void pushDown(int i) {
        FOR(j, 2 * i, 2 * i + 1) {
            tree[j].lazy += tree[i].lazy;
            tree[j].firstValue += tree[i].lazy;
            tree[j].lastValue += tree[i].lazy;
        }
        tree[i].lazy = 0;
    }

    void combine(Node &cur, const Node &left, const Node &right) {
        cur.firstValue = left.firstValue;
        cur.lastValue = right.lastValue;

        cur.incSuffix = right.incSuffix;
        if (left.lastValue < right.firstValue && right.incSuffix == right.length)
            cur.incSuffix += left.incSuffix;
        cur.decPrefix = left.decPrefix;
        if (left.lastValue > right.firstValue && left.decPrefix == left.length)
            cur.decPrefix += right.decPrefix;

        cur.bestPrefix = left.bestPrefix;
        if (left.lastValue > right.firstValue && left.bestPrefix == left.length)
            cur.bestPrefix += right.decPrefix;
        if (left.lastValue < right.firstValue && left.incSuffix == left.length)
            maximize(cur.bestPrefix, right.bestPrefix + left.length);

        cur.bestSuffix = right.bestSuffix;
        if (left.lastValue < right.firstValue && right.bestSuffix == right.length)
            cur.bestSuffix += left.incSuffix;
        if (left.lastValue > right.firstValue && right.decPrefix == right.length)
            maximize(cur.bestSuffix, left.bestSuffix + right.length);

        cur.best = max(left.best, right.best);
        maximize(cur.best, max(cur.bestPrefix, cur.bestSuffix));
        maximize(cur.best, max(cur.incSuffix, cur.decPrefix));
        if (left.lastValue > right.firstValue) maximize(cur.best, left.bestSuffix + right.decPrefix);
        if (left.lastValue < right.firstValue) maximize(cur.best, right.bestPrefix + left.incSuffix);
    }

    void init(int i, int l, int r) {
        if (l > r) return;
        tree[i] = Node(r - l + 1);
        if (l == r) return;
        int m = (l + r) >> 1;
        init(2 * i, l, m);
        init(2 * i + 1, m + 1, r);
    }

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i].lazy += c;
            tree[i].firstValue += c;
            tree[i].lastValue += c;
            return;
        }

        pushDown(i);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        combine(tree[i], tree[2 * i], tree[2 * i + 1]);
    }

    void debug(int i, int l, int r) const {
        if (l > r) return;
        printf("Node %d from %d to %d:\n", i, l, r);
        tree[i].debug();
        if (l == r) return;
        int m = (l + r) >> 1;
        debug(2 * i, l, m);
        debug(2 * i + 1, m + 1, r);
    }

    public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, Node());
        init(1, 1, n);
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }
    int getMax(void) const {
        return tree[1].best;
    }
//    void debug(void) const {
//        debug(1, 1, n);
//    }
};

void process(void) {
    int n; scanf("%d", &n);
    SegmentTree myit(n);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        myit.update(i, i, x);
    }
    int q; scanf("%d", &q);
    REP(love, q) {
        int l, r, c; scanf("%d%d%d", &l, &r, &c);
        myit.update(l, r, c);
        printf("%d\n", myit.getMax());
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/