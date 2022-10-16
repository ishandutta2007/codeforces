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
    vector<long long> tree, lazy;
    int n;

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
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void update(int l, int r, long long v) {
        update(1, 1, n, l, r, v);
    }
    long long getMin(void) const {
        return tree[1];
    }
};

#define MAX   1000100
#define MAX_VALUE   10001000

int curLim[MAX];
pair<int, int> buyLim[MAX];
int numCur, numBuy, allow;

int cnt[MAX_VALUE];

void init(void) {
    scanf("%d%d%d", &numCur, &numBuy, &allow);
    FOR(i, 1, numCur) scanf("%d", &curLim[i]);
    FOR(i, 1, numBuy) scanf("%d", &buyLim[i].fi);
    FOR(i, 1, numBuy) buyLim[i].se = i;
    sort(buyLim + 1, buyLim + numBuy + 1, greater<pair<int, int> > ());
}

bool ok(int x) {
    memset(cnt, 0, sizeof cnt);
    FOR(i, 1, numCur) cnt[curLim[i]]++;
    FOR(i, 1, x) cnt[buyLim[i].fi]++;

    REP(i, MAX_VALUE - 1) {
        if (cnt[i] > 1LL * allow * (i + 1)) return false;
        cnt[i + 1] += cnt[i];
    }

    return true;
}

int solve(void) {
    int L = 0;
    int R = numBuy;

    while (true) {
        if (L == R) return R;
        if (R - L == 1) return ok(R) ? R : L;
        int M = (L + R) >> 1;
        if (ok(M)) L = M; else R = M - 1;
    }
}

void process(void) {
    if (!ok(0)) {
        printf("-1\n");
        return;
    }

    int res = solve();
    printf("%d\n", res);
    FOR(i, 1, res) printf("%d ", buyLim[i].se); printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/