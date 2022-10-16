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
#define time   ___time
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

long long need, initTime, limCost;
int numChange, numCreate;
pair<long long, long long> changes[MAX], creates[MAX];

bool compSecond(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.se < b.se;
}
void init(void) {
    cin >> need >> numChange >> numCreate >> initTime >> limCost;
    REP(i, numChange) cin >> changes[i].fi;
    REP(i, numChange) cin >> changes[i].se;
    REP(i, numCreate) cin >> creates[i].fi;
    REP(i, numCreate) cin >> creates[i].se;

    sort(changes, changes + numChange, compSecond);
}

void process(void) {
    long long res = need * initTime;
    REP(i, numChange) if (changes[i].se <= limCost) minimize(res, changes[i].fi * need);
    REP(i, numCreate) if (creates[i].se <= limCost) minimize(res, max(0LL, need - creates[i].fi) * initTime);

    long long minTime = initTime;
    int j = 0;
    FORD(i, numCreate - 1, 0) if (creates[i].se <= limCost) {
        while (j < numChange && changes[j].se + creates[i].se <= limCost) minimize(minTime, changes[j++].fi);
        minimize(res, max(0LL, need - creates[i].fi) * minTime);
    }
    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/