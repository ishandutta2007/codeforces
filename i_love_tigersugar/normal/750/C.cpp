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
const int INF = (int)1e9 + 7;
const int minDiv1 = 1900;
const int maxDiv2 = 1899;

const string noAnswer = "Impossible";
const string infAnswer = "Infinity";

int main(void) {
    int L = -INF;
    int R = INF;

    int n; scanf("%d", &n);
    int delta = 0;
    REP(love, n) {
        int atDiv, change; scanf("%d%d", &change, &atDiv);
        if (atDiv == 1) maximize(L, minDiv1 - delta);
        else minimize(R, maxDiv2 - delta);
        delta += change;
    }

    if (L > R) cout << noAnswer << endl;
    else if (R >= INF) cout << infAnswer << endl;
    else cout << R + delta << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/