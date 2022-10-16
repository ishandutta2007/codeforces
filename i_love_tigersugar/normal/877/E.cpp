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
    int n;
    vector<int> tree, lazy;

    void pushDown(int i, int l, int r) {
        int m = (l + r) >> 1;
        if (lazy[i]) {
            tree[2 * i] = (m - l + 1) - tree[2 * i];
            tree[2 * i + 1] = (r - m) - tree[2 * i + 1];
        }
        FOR(j, 2 * i, 2 * i + 1) lazy[j] ^= lazy[i];
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i] = (r - l + 1) - tree[i];
            lazy[i] ^= 1;
            return;
        }

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v);
        update(2 * i + 1, m + 1, r, u, v);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int getSum(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return tree[i];

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        int L = getSum(2 * i, l, m, u, v);
        int R = getSum(2 * i + 1, m + 1, r, u, v);
        return L + R;
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n > 0) {
            tree.assign(4 * n + 7, 0);
            lazy.assign(4 * n + 7, 0);
        }
    }

    void update(int l, int r) {
        update(1, 1, n, l, r);
    }
    int getSum(int l, int r) {
        return getSum(1, 1, n, l, r);
    }
};

#define MAX   200200

vector<int> children[MAX];
int sta[MAX], fin[MAX], value[MAX];
int n, q, cnt;

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 2, n) {
        int p; scanf("%d", &p);
        children[p].push_back(i);
    }
    FOR(i, 1, n) scanf("%d", &value[i]);
}

void dfs(int u) {
    sta[u] = ++cnt;
    FORE(it, children[u]) dfs(*it);
    fin[u] = cnt;
}

void process(void) {
    dfs(1);

    SegmentTree myit(n);
    FOR(i, 1, n) if (value[i]) myit.update(sta[i], sta[i]);

    scanf("%d", &q);
    char input[33];
    REP(love, q) {
        scanf("%s", input);
        int u; scanf("%d", &u);
        if (input[0] == 'p') myit.update(sta[u], fin[u]);
        else printf("%d\n", myit.getSum(sta[u], fin[u]));
    }
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/