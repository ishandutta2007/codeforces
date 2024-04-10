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

#define MAX   100100

pair<int, int> itemC[MAX], itemD[MAX];
int numC, numD, limC, limD;
int bestC[MAX], bestD[MAX];

void init(void) {
    int n; scanf("%d%d%d", &n, &limC, &limD);
    REP(pmp, n) {
        int val, cost; char type; scanf("%d%d %c", &val, &cost, &type);
        if (type == 'C') itemC[++numC] = make_pair(cost, val);
        else itemD[++numD] = make_pair(cost, val);
    }
}

bool compFirst(const pair<int, int> &a, const pair<int, int> &b) {
    return a.fi < b.fi;
}

int maxSingle(int n, int lim, pair<int, int> items[], int best[]) {
    sort(items + 1, items + n + 1);
    FOR(i, 1, n) best[i] = max(best[i - 1], items[i].se);

    int res = 0;
    FOR(i, 1, n) {
        int j = upper_bound(items + 1, items + n + 1, make_pair(lim - items[i].fi, 0), compFirst) - items - 1;
        minimize(j, i - 1);
        if (j > 0) maximize(res, items[i].se + best[j]);
    }

    return res;
}

int maxBoth(void) {
    int valC = 0, valD = 0;

    FOR(i, 1, numC) if (itemC[i].fi <= limC) valC = bestC[i];
    FOR(i, 1, numD) if (itemD[i].fi <= limD) valD = bestD[i];

    return valC == 0 || valD == 0 ? 0 : valC + valD;
}

void process(void) {
    int res = 0;
    maximize(res, maxSingle(numC, limC, itemC, bestC));
    maximize(res, maxSingle(numD, limD, itemD, bestD));
    maximize(res, maxBoth());

    printf("%d\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/