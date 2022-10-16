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

priority_queue<int, vector<int>, greater<int> > prices[111];
const int INF = (int)1e9 + 7;

#define MAX   200200
int p[MAX], a[MAX], b[MAX], n;

void init(void) {
    int n; scanf("%d", &n);
    REP(i, n) scanf("%d", &p[i]);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);

    REP(i, n) {
        a[i]--; b[i]--;
        prices[MASK(a[i]) | MASK(b[i])].push(p[i]);
    }
}

int getPrice(int need) {
    int res = INF;
    REP(i, MASK(3)) if (BIT(i, need) && !prices[i].empty())
        minimize(res, prices[i].top());

    if (res >= INF) return -1;

    REP(i, MASK(3)) if (BIT(i, need) && !prices[i].empty() && prices[i].top() == res) prices[i].pop();
    return res;
}

void process(void) {
    int q; scanf("%d", &q);
    REP(pmp, q) {
        int x; scanf("%d", &x); x--;
        printf("%d ", getPrice(x));
    }
    printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/