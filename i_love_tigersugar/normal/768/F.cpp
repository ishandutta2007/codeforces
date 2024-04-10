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

#define MAX   300300
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
void prepare(void) {
    frac[0] = finv[0] = 1;
    FOR(i, 1, MAX - 1) {
        frac[i] = 1LL * frac[i - 1] * i % MOD;
        finv[i] = inverse(frac[i]);
    }
}

int comb(int k, int n) {
    return k > n ? 0 : 1LL * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}

int cntWay(int sum, int capa, int lim = 1) {
    if (1LL * capa * lim > sum) return 0;

    sum -= capa * (lim - 1);
    return comb(capa - 1, sum - 1);
}

int solve(int a, int b, int h) {
    if (h == 0) return 1;

    if (a == 0) return b > h ? 1 : 0;
    if (b == 0) return 1;

    int cntAll = 0, cntGood = 0;
    FOR(i, 1, MAX / 3) {
        cntAll = (cntAll + 2LL * cntWay(a, i) * cntWay(b, i)) % MOD;
        cntGood = (cntGood + 2LL * cntWay(a, i) * cntWay(b, i, h + 1)) % MOD;

        cntAll = (cntAll + 1LL * cntWay(a, i) * cntWay(b, i + 1)) % MOD;
        cntGood = (cntGood + 1LL * cntWay(a, i) * cntWay(b, i + 1, h + 1)) % MOD;

        cntAll = (cntAll + 1LL * cntWay(a, i + 1) * cntWay(b, i)) % MOD;
        cntGood = (cntGood + 1LL * cntWay(a, i + 1) * cntWay(b, i, h + 1)) % MOD;
    }

    cerr << cntGood << endl;
    cerr << cntAll << endl;
    return 1LL * cntGood * inverse(cntAll) % MOD;
}

int main(void) {
    prepare();
    int a, b, h; cin >> a >> b >> h;
    cout << solve(a, b, h) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/