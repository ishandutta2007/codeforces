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

#define MAX   111
const int INF = (int)1e9 + 7;

int minCost[MAX][MAX];
int numNode, numEdge, need;
int f[MAX][MAX][MAX][2];

void init(void) {
    scanf("%d%d%d", &numNode, &need, &numEdge);

    memset(minCost, 0x3f, sizeof minCost);
    REP(pmp, numEdge) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        minimize(minCost[u][v], c);
    }
}

int dp(int l, int r, int need, bool atLeft) {
    if (need == 0) return 0;
    if (l >= r) return INF;
    if (f[l][r][need][atLeft] >= 0) return f[l][r][need][atLeft];

    int &res = f[l][r][need][atLeft];
    res = INF;

    if (atLeft) {
        FOR(i, l + 1, r) if (minCost[l][i] < INF)
            minimize(res, min(dp(l + 1, i, need - 1, false), dp(i, r, need - 1, true)) + minCost[l][i]);
    } else {
        FOR(i, l, r - 1) if (minCost[r][i] < INF)
            minimize(res, min(dp(i, r - 1, need - 1, true), dp(l, i, need - 1, false)) + minCost[r][i]);
    }

    return res;
}

void process(void) {
    if (need < 2) {
        cout << 0 << endl;
        return;
    }

    memset(f, -1, sizeof f);

    int res = INF;
    FOR(i, 1, numNode) FOR(j, i + 1, numNode) if (minCost[i][j] < INF)
        minimize(res, min(dp(i + 1, j, need - 2, false), dp(j, numNode, need - 2, true)) + minCost[i][j]);

    FOR(i, 1, numNode) FOR(j, 1, i - 1) if (minCost[i][j] < INF)
        minimize(res, min(dp(j, i - 1, need - 2, true), dp(1, j, need - 2, false)) + minCost[i][j]);

    cout << (res < INF ? res : -1) << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/