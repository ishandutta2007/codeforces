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

#define MAX   200200
const int MOD = (int)1e9 + 7;

int frac[MAX], finv[MAX];

int inverse(int x) {
    int res = 1;
    int mul = x;
    int k = MOD - 2;

    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }

    assert(1LL * res * x % MOD == 1);
    return res;
}

void precalc(void) {
    frac[0] = finv[0] = 1;
    FOR(i, 1, MAX - 1) {
        frac[i] = 1LL * frac[i - 1] * i % MOD;
        finv[i] = inverse(frac[i]);
    }
}

int comb(int k, int n) {
    return k > n ? 0 : 1LL * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}

int calc(int L, int R) {
    if (L == 1) return R;
    if (R == 1) return 1;
    return comb(R - 1, L + R - 1);

//    int res = 0;
//    FOR(i, 1, min(L, R)) res = (res + 1LL * comb(i - 1, L - 1) * comb(i, R)) % MOD;
//    return res;
}

int solve(string s) {
    int L = 0, R = 0;
    FORE(it, s) if (*it == ')') R++;

    int res = 0;
    FORE(it, s) {
        if (*it == '(') L++;
        if (*it == '(') res = (res + calc(L, R)) % MOD;
        if (*it == ')') R--;
    }
    return res;
}

int main(void) {
    precalc();

    string s; while (cin >> s) cout << solve(s) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/