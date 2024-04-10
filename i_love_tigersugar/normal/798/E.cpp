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
    vector<pair<int, int> > tree;
    int n;

    void build(int i, int l, int r) {
        if (l == r) {
            tree[i] = make_pair(0, r);
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    void assign(int i, int l, int r, int x, int v) {
        if (l == r) {
            tree[i] = make_pair(v, r);
            return;
        }

        int m = (l + r) >> 1;
        if (x > m) assign(2 * i + 1, m + 1, r, x, v);
        else assign(2 * i, l, m, x, v);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    pair<int, int> getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return make_pair(-1, -1);
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        pair<int, int> L = getMax(2 * i, l, m, u, v);
        pair<int, int> R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n == 0) return;
        tree.assign(4 * n + 7, make_pair(0, 0));
        build(1, 1, n);
    }

    void assign(int x, int v) {
        assign(1, 1, n, x, v);
    }

    pair<int, int> getMax(int l, int r) const {
        return getMax(1, 1, n, l, r);
    }
};

#define MAX   500500

int a[MAX], b[MAX], res[MAX], n, cnt;
SegmentTree myit;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) b[i] = n + 1;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] < 0) a[i] = n + 1;
        if (a[i] <= n) b[a[i]] = i;
    }
}

void dfs(int u) {
    if (myit.getMax(u, u).fi < 0) return;
    myit.assign(u, -1);

    if (b[u] <= n) dfs(b[u]);

    while (true) {
        pair<int, int> tmp = myit.getMax(1, a[u] - 1);
        if (tmp.fi <= u) break;

        int v = tmp.se;
        dfs(v);
    }

    res[u] = ++cnt;
}

void process(void) {
    myit = SegmentTree(n);
    FOR(i, 1, n) myit.assign(i, b[i]);

    FOR(i, 1, n) if (myit.getMax(i, i).fi >= 0) dfs(i);
    FOR(i, 1, n) printf("%d ", res[i]); printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/