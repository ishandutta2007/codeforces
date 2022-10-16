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

const int MOD = (int)1e9 + 7;
int pw(int x, int k) {
    int res = 1;
    int mul = x;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }
    return res;
}

vector<int> getPrimes(int x) {
    vector<int> res;
    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        res.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x > 1) res.push_back(x);
    return res;
}

int solve(int x, int s) {
    if (s % x != 0) return 0;
    s /= x;

    int res = 0;
    vector<int> primes = getPrimes(s);
    REP(mask, MASK(primes.size())) {
        int prod = 1;
        REP(i, primes.size()) if (BIT(mask, i)) prod *= primes[i];
        int numWay = pw(2, s / prod - 1);
        if (__builtin_popcount(mask) % 2 == 0) res = (res + numWay) % MOD;
        else res = (res - numWay + MOD) % MOD;
    }
    return res;
}

int main(void) {
    int x, y;
    while (cin >> x >> y) cout << solve(x, y) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/