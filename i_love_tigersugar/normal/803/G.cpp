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
    static const int INF = (int)1e9 + 7;
    vector<int> tree, lazy;
    int n;

    void pushDown(int i) {
        if (lazy[i] < 0) return;
        FOR(j, 2 * i, 2 * i + 1) {
            tree[j] = lazy[i];
            lazy[j] = lazy[i];
        }
        lazy[i] = -1;
        return;
    }

    void assign(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i] = lazy[i] = c;
            return;
        }

        pushDown(i);
        int m = (l + r) >> 1;
        assign(2 * i, l, m, u, v, c);
        assign(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    int getMin(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return INF;
        if (u <= l && r <= v) return tree[i];

        pushDown(i);
        int m = (l + r) >> 1;
        int L = getMin(2 * i, l, m, u, v);
        int R = getMin(2 * i + 1, m + 1, r, u, v);
        return min(L, R);
    }

public:
    SegmentTree(int n = 0) {
        this-> n = n;
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void assign(int l, int r, int v) {
        assign(1, 1, n, l, r, v);
    }

    int getMin(int l, int r) {
        return getMin(1, 1, n, l, r);
    }
};

struct Query {
    #define UPDATE   1
    #define GET_MAX   2

    int type, l, r, value;

    Query() {
        type = l = r = value = 0;
    }

    void input(void) {
        scanf("%d%d%d", &type, &l, &r); l--; r--;
        if (type == UPDATE) scanf("%d", &value);
    }
};

#define MAX   100100
#define LOG   17

Query queries[MAX];
int numValue, numRepeat, numQuery;
int value[MAX], rmq[MAX][LOG + 1], lg2[MAX];
vector<int> indices;

void init(void) {
    scanf("%d%d", &numValue, &numRepeat);
    REP(i, numValue) scanf("%d", &value[i]);
    scanf("%d", &numQuery);
    REP(i, numQuery) queries[i].input();
}

void prepare(void) {
    indices.push_back(0);
    REP(i, numQuery) {
        indices.push_back(queries[i].l);
        indices.push_back(queries[i].r + 1);
    }
    indices.push_back(numValue * numRepeat);

    sort(ALL(indices));
    indices.resize(unique(ALL(indices)) - indices.begin());

    REP(i, numValue) rmq[i][0] = value[i];
    FOR(j, 1, LOG) REP(i, numValue - MASK(j) + 1) rmq[i][j] = min(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);

    FOR(i, 1, numValue) {
        while (MASK(lg2[i]) <= i) lg2[i]++; lg2[i]--;
    }
}

int getMin(int l, int r) {
    int k = lg2[r - l + 1];
    return min(rmq[l][k], rmq[r - MASK(k) + 1][k]);
}

int getMinSegment(int l, int r) {
    if (r / numValue - l / numValue > 1) return getMin(0, numValue - 1);
    if (r / numValue == l / numValue) return getMin(l % numValue, r % numValue);
    return min(getMin(l % numValue, numValue - 1), getMin(0, r % numValue));
}

void process(void) {
    SegmentTree myit(indices.size() - 1);
    REP(i, indices.size() - 1) {
        int L = indices[i], R = indices[i + 1] - 1;
        myit.assign(i + 1, i + 1, getMinSegment(L, R));
    }

    REP(i, numQuery) {
        int L = lower_bound(ALL(indices), queries[i].l) - indices.begin() + 1;
        int R = upper_bound(ALL(indices), queries[i].r) - indices.begin();
        if (queries[i].type == UPDATE) myit.assign(L, R, queries[i].value);
        else printf("%d\n", myit.getMin(L, R));
    }
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/