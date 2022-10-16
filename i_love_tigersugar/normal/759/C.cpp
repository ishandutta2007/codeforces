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
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }
    int lastLess(int c) {
        if (tree[1] >= c) return 0;

        int i = 1;
        int l = 1;
        int r = n;
        while (true) {
            if (l == r) return r;

            pushDown(i);
            int m = (l + r) >> 1;
            if (tree[2 * i + 1] < c) {
                i = 2 * i + 1;
                l = m + 1;
            } else {
                i = 2 * i;
                r = m;
            }
        }
    }

};

#define MAX   300300

#define POP   -2
int a[MAX], n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, 2 * n) a[i] = -1;

    SegmentTree myit(3 * n);
    FOR(i, 1, 2 * n) myit.update(i, 3 * n, 1);

    int size = 2 * n;
    REP(love, n) {
        int pos, type, val; scanf("%d%d", &pos, &type);
        if (type == 1) scanf("%d", &val);

        a[pos + 2 * n] = type == 1 ? val : POP;
        if (a[pos + 2 * n] == POP) myit.update(pos + 2 * n, 3 * n,-1);
        else myit.update(pos + 2 * n, 3 * n, 1);
        if (a[pos + 2 * n] == POP) size--; else size++;

        printf("%d\n", a[myit.lastLess(size) + 1]);
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/