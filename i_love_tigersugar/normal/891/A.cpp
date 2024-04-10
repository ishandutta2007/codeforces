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

#define MAX   2222
int a[MAX], res[MAX][MAX], n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) res[i][i] = a[i];
    FOR(d, 1, n - 1) FOR(i, 1, n - d) res[i][i + d] = __gcd(res[i + 1][i + d], a[i]);

    if (res[1][n] > 1) {
        printf("-1\n");
        return;
    }

    int countOne = 0;
    FOR(i, 1, n) if (a[i] == 1) countOne++;
    if (countOne > 0) {
        printf("%d\n", n - countOne);
        return;
    }

    int best = n;
    FOR(i, 1, n) FOR(j, i, n) if (res[i][j] == 1) minimize(best, j - i);
    printf("%d\n", best + n - 1);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/