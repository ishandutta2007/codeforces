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

#define MAX   200200
#define NUMBIT   30

int sumAnd[MAX], sumOr[MAX], res[MAX], n;
int bitCount[NUMBIT + 7];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &sumAnd[i]);
    FOR(i, 1, n) scanf("%d", &sumOr[i]);
}

void noAnswer(void) {
    printf("-1\n");
    exit(0);
}

void findResult(void) {
    long long sumAll = 0;
    FOR(i, 1, n) sumAll += sumAnd[i] + sumOr[i];
    if (sumAll % (2 * n) != 0) noAnswer();
    sumAll /= 2 * n;
    FOR(i, 1, n) {
        long long tmp = sumAnd[i] + sumOr[i] - sumAll;
        if (tmp < 0 || tmp % n != 0) noAnswer();
        if (tmp / n > sumOr[i]) noAnswer();
        res[i] = tmp / n;
    }
}

long long calcSumAnd(int val) {
    long long res = 0;
    REP(i, NUMBIT) if (BIT(val, i)) res += (1LL * bitCount[i]) << i;
    return res;
}

long long calcSumOr(int val) {
    long long res = 0;
    REP(i, NUMBIT) {
        if (BIT(val, i)) res += (1LL * n) << i;
        else res += (1LL * bitCount[i]) << i;
    }
    return res;
}

bool check(void) {
    FOR(i, 1, n) REP(j, NUMBIT) bitCount[j] += BIT(res[i], j);
    FOR(i, 1, n) if (calcSumAnd(res[i]) != sumAnd[i]) return false;
    FOR(i, 1, n) if (calcSumOr(res[i]) != sumOr[i]) return false;
    return true;
}

void process(void) {
    findResult();
    if (!check()) noAnswer();
    FOR(i, 1, n) printf("%d ", res[i]); printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/