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

int ceil(int a, int b) {
    return a / b + (a % b > 0);
}

long long solve(int x, int y, int p, int q) {
    if (p == q) return x == y ? 0 : -1;
    y -= x; q -= p;

    if (p == 0 && x > 0) return -1;
    if (q == 0 && y > 0) return -1;

    int k = 0;
    if (x > 0) maximize(k, ceil(x, p));
    if (y > 0) maximize(k, ceil(y, q));

    return 1LL * k * (p + q) - (x + y);
}

int main(void) {
    int t; cin >> t;
    REP(LOVE, t) {
        int x, y, p, q; cin >> x >> y >> p >> q;
        cout << solve(x, y, p, q) << "\n";
    }

    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/