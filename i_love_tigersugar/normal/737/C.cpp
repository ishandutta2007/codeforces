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

int cnt[MAX], sumCnt[MAX], sumEmpty[MAX], n, root;
bool rootWrong;

void init(void) {
    scanf("%d%d", &n, &root);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        if (i == root) rootWrong = x != 0;
        else cnt[x]++;
    }

    sumCnt[0] = cnt[0];
    FOR(i, 1, n - 1) sumCnt[i] = sumCnt[i - 1] + cnt[i];
    sumEmpty[0] = cnt[0] == 0;
    FOR(i, 1, n - 1) sumEmpty[i] = sumEmpty[i - 1] + (cnt[i] == 0);
}

void process(void) {
    if (n == 1) {
        printf("%d\n", rootWrong ? 1 : 0);
        return;
    }

    int res = MAX;
    FOR(i, 1, n - 1) minimize(res, max(cnt[0] + n - 1 - sumCnt[i], sumEmpty[i] - sumEmpty[0]));
    if (rootWrong) res++;
    printf("%d\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/