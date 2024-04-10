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

#define MAX   512
const int INF = (int) 1e9 + 7;

int req[MAX], n, reqSum;
int f[MAX][MAX + 10], best[MAX][MAX + 10];
int answer[MAX];

void init(void) {
    scanf("%d%d", &n, &reqSum);
    FOR(i, 1, n) scanf("%d", &req[i]);
}

void optimize(void) {
    memset(f, 0x3f, sizeof f);
    f[0][reqSum] = 0;
    REP(i, n) REP(j, MAX) if (f[i][j] < INF)
        FOR(k, req[i + 1], MAX - 1) if (j + k >= reqSum)
            if (f[i + 1][k] > f[i][j] + k - req[i + 1]) {
                f[i + 1][k] = f[i][j] + k - req[i + 1];
                best[i + 1][k] = j;
            }
}

void trace(void) {
    int j = 0;
    REP(i, MAX) if (f[n][j] > f[n][i]) j = i;
    printf("%d\n", f[n][j]);
    FORD(i, n, 1) {
        answer[i] = j;
        j = best[i][j];
    }
    FOR(i, 1, n) printf("%d ", answer[i]); printf("\n");
}

int main(void) {
    init();
    optimize();
    trace();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/