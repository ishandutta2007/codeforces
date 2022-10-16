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

int val(long long n, long long pos, int numBit) {
    if (numBit == 1) return n;
    if (pos <= MASK(numBit - 1) - 1) return val(n / 2, pos, numBit - 1);
    if (pos == MASK(numBit - 1)) return n % 2;
    return val(n / 2, pos - MASK(numBit - 1), numBit - 1);
}

int main(void) {
    long long n, l, r; cin >> n >> l >> r;
    int numBit = 0;
    while (MASK(numBit) <= n) numBit++;

    int res = 0;
    for (long long i = l; i <= r; i++) res += val(n, i, numBit);
    cout << res << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/