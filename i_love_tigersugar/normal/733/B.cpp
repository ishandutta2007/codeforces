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

#define MAX   100100

int l[MAX], r[MAX], n, sl, sr;

int main(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &l[i], &r[i]);
    FOR(i, 1, n) sl += l[i];
    FOR(i, 1, n) sr += r[i];
    int best = Abs(sl - sr);
    int res = 0;
    FOR(i, 1, n) {
        int newSL = sl - l[i] + r[i];
        int newSR = sr - r[i] + l[i];
        if (best < Abs(newSL - newSR)) {
            best = Abs(newSL - newSR);
            res = i;
        }
    }
    printf("%d\n", res);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/