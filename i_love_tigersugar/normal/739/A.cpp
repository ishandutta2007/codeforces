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

int a[MAX];
pair<int, int> seg[MAX];
int n, m;

void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) scanf("%d%d", &seg[i].fi, &seg[i].se);
}

void process(void) {
    pair<int, int> best(0, n + 1);
    FOR(i, 1, m) if (best.se - best.fi > seg[i].se - seg[i].fi) best = seg[i];
    int res = best.se - best.fi + 1;

    FOR(i, best.fi, best.se) a[i] = i - best.fi;
    FORD(i, best.fi - 1, 1) a[i] = (a[i + 1] - 1 + res) % res;
    FOR(i, best.se + 1, n) a[i] = (a[i - 1] + 1) % res;

    printf("%d\n", res);
    FOR(i, 1, n) printf("%d ", a[i]); printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/