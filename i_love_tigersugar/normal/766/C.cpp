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

#define MAX   1111
const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;

bool valid[MAX][MAX];
bool canLeft[MAX], canRight[MAX];
char s[MAX];
int lim[MAX], cntWay[MAX], minNeed[MAX];
int n;

void init(void) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    REP(i, 26) scanf("%d", &lim[i]);
}

void process(void) {
    FOR(i, 1, n) {
        int allow = INF;
        FOR(j, i, n) {
            minimize(allow, lim[s[j] - 'a']);
            valid[i][j] = allow >= j - i + 1;
        }
    }

    canRight[n + 1] = true;
    FORD(i, n, 1) FORD(j, n + 1, i + 1) if (canRight[j] && valid[i][j - 1]) canRight[i] = true;

    memset(minNeed, 0x3f, sizeof minNeed);
    canLeft[0] = true;
    cntWay[0] = 1;
    minNeed[0] = 0;

    FOR(i, 1, n) REP(j, i) if (canLeft[j] && valid[j + 1][i]) {
        canLeft[i] = true;
        cntWay[i] = (cntWay[i] + cntWay[j]) % MOD;
        minimize(minNeed[i], minNeed[j] + 1);
    }

    printf("%d\n", cntWay[n]);
    int maxLen = -1;
    FOR(i, 1, n) FOR(j, i, n) if (canLeft[i - 1] && valid[i][j] && canRight[j + 1]) maximize(maxLen, j - i + 1);
    printf("%d\n", maxLen);
    printf("%d\n", minNeed[n]);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/