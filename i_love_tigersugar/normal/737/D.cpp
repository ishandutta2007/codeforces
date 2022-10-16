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

#define MAX   4040
const int MAGIC = 65;
const int INF = (int)1e9 + 7;

int *f[2][MAX][MAX];

int a[MAX], n;
int sum[MAX];
int maxK[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
}

void prepare(void) {
    REP(i, MAX) {
        while (maxK[i] * (maxK[i] + 1) / 2 - 1 <= i) maxK[i]++;
        maximize(maxK[i], 1);
    }

    FOR(l, 1, n) FOR(r, l, n) if (Abs((n - r) - (l - 1)) <= MAGIC) REP(i, 2) {
        f[i][l][r] = new int[maxK[l - 1 + n - r] + 1];
        REP(j, maxK[l - 1 + n - r] + 1) f[i][l][r][j] = INF;
    }

}

#define LEFT   true
#define RIGHT   false
int dp(int l, int r, int k, int t) {
    if (l > r || r - l + 1 < k) return 0;
    if (f[t][l][r][k] < INF) return f[t][l][r][k];
    int &res = f[t][l][r][k];

    if (t == LEFT) {
        res = -INF;
        REP(i, 2) if (l + k + i - 1 <= r)
            maximize(res, dp(l + k + i, r, k + i, t ^ 1) + (sum[l + k + i - 1] - sum[l - 1]));
    } else {
        res = INF;
        REP(i, 2) if (r - k - i + 1 >= l)
            minimize(res, dp(l, r - k - i, k + i, t ^ 1) - (sum[r] - sum[r - k - i]));
    }

    return res;
}

void process(void) {
    printf("%d\n", dp(1, n, 1, LEFT));
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/