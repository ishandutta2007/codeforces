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

#define MAX   1111

const long long INF = (long long)1e18 + 7LL;

long long minNeed[MAX], maxNeed[MAX];

int main(void) {
    minNeed[0] = maxNeed[0] = 1;
    minNeed[1] = maxNeed[1] = 2;
    FOR(i, 2, MAX - 1) {
        minNeed[i] = 2 * minNeed[i - 1];
        maxNeed[i] = 2 * maxNeed[i - 1];
        minimize(minNeed[i], minNeed[i - 1] + minNeed[i - 2]);
        maximize(maxNeed[i], maxNeed[i - 1] + maxNeed[i - 2]);
        minimize(minNeed[i], INF);
        minimize(maxNeed[i], INF);
    }

    long long n; cin >> n;
    int res = 0;
    FOR(i, 1, MAX - 1) if (minNeed[i] <= n && n <= maxNeed[i]) res = i;
    cout << res << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/