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

#define MAX   1000100
#define LOG   20
const long long INF = (long long)1e18 + 7LL;
const int mod = (int)1e9 + 7;

int cntWay[LOG + 1][MAX];
int numPrimeDiv[MAX];
long long sum[MAX][LOG + 1];


int inverse(int x) {
    int res = 1;
    int mul = x;
    int k = mod - 2;

    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % mod;
        mul = 1LL * mul * mul % mod;
        k >>= 1;
    }
    return res;
}

void prepare(void) {
    FOR(i, 2, MAX - 1) if (numPrimeDiv[i] == 0)
        for (int j = i; j < MAX; j = j + i) numPrimeDiv[j]++;

    FOR(i, 2, MAX - 1) assert(numPrimeDiv[i] < 15);

    cntWay[0][1] = 1;
    REP(j, LOG) FOR(i, 1, MAX - 1) if (cntWay[j][i] > 0)
        for (int k = 2 * i; k < MAX; k = k + i) {
            cntWay[j + 1][k] += cntWay[j][i];
            if (cntWay[j + 1][k] >= mod) cntWay[j + 1][k] -= mod;
        }

    REP(j, LOG + 1) FOR(i, 1, MAX - 1) if (cntWay[j][i] > 0)
        FOR(k, 1, (MAX - 1) / i) {
            sum[k * i][j] += 1LL * cntWay[j][i] * MASK(numPrimeDiv[k]);
            if (sum[k * i][j] >= INF) sum[k * i][j] %= mod;
        }

#define comb cntWay

    REP(i, LOG + 1) comb[i][0] = 0;
    REP(j, MAX) comb[0][j] = 1;

    comb[0][0] = 1;

    FOR(i, 1, LOG) FOR(j, 1, MAX - 1) {
        if (i > j) comb[i][j] = 0;
        if (i == j) comb[i][j] = 1;
        if (i < j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i][j - 1];
            if (comb[i][j] >= mod) comb[i][j] -= mod;
        }
    }
}

int answer(int r, int n) {
    long long res = 0;
    FOR(k, 0, LOG) {
        res += 1LL * comb[k][r] * sum[n][k];
        if (res >= INF) res %= mod;
    }
    return res % mod;
}

int main(void) {
    prepare();

    int q; scanf("%d", &q);
    REP(love, q) {
        int r, n; scanf("%d%d", &r, &n);
        printf("%d\n", answer(r, n));
    }

    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/