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

const long long INF = (long long)1e18 + 7LL;

class SegmentTree {
    private:
    vector<long long> tree;
    int n;

    void assign(int i, int l, int r, int x, long long v) {
        if (l == r) {
            tree[i] = v;
            return;
        }

        int m = (l + r) >> 1;
        if (x > m) assign(2 * i + 1, m + 1, r, x, v);
        else assign(2 * i, l, m, x, v);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    long long getMax(int i, int l, int r, int u, int v) const {
        if (l > v || r < u || l > r || v < u) return -INF;
        if (u <= l && r <= v) return tree[i];

        int m = (l + r) >> 1;
        long long L = getMax(2 * i, l, m, u, v);
        long long R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

    long long getMax(int l, int r) const {
        return getMax(1, 1, n, l, r);
    }

    public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.assign(4 * n + 7, -INF);
    }

    void assign(int pos, long long value) {
        assign(1, 1, n, pos, value);
    }

    long long getExcludeMax(int l, int r) const {
        return max(getMax(1, l - 1), getMax(r + 1, n));
    }
};

#define MAX   200200
const string noAnswer = "Impossible";

vector<int> adj[MAX];
int value[MAX], n;
long long sum[MAX];
int sta[MAX], fin[MAX], cnt;
long long res;
SegmentTree myit;

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);

    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void preDFS(int u, int par) {
    sta[u] = ++cnt;
    sum[u] = value[u];
    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        preDFS(v, u);
        sum[u] += sum[v];
    }
    fin[u] = cnt;
}

void calcAnswer(int u, int par) {
    long long tmp = myit.getExcludeMax(sta[u], fin[u]);
    if (tmp > -INF) maximize(res, sum[u] + tmp);

    myit.assign(sta[u], -INF);

    FORE(it, adj[u]) if (*it != par) calcAnswer(*it, u);

    myit.assign(sta[u], sum[u]);
}

void process(void) {
    preDFS(1, -1);

    myit = SegmentTree(n);
    FOR(i, 1, n) myit.assign(sta[i], sum[i]);

    res = -INF;
    calcAnswer(1, -1);
    if (res > -INF) cout << res << endl; else cout << noAnswer << endl;
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/