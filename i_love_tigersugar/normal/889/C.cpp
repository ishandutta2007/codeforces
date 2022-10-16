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

#define MAX   1000100
const int MOD = (int)1e9 + 7;

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

int frac[MAX], finv[MAX];
int sum[MAX], cnt[MAX];

void prepare(void) {
    frac[0] = finv[0] = 1;
    FOR(i, 1, MAX - 1) {
        frac[i] = 1LL * frac[i - 1] * i % MOD;
        finv[i] = inverse(frac[i]);
    }
}

void process(void) {
    int n, k; cin >> n >> k;
    cnt[1] = sum[1] = 1;
    FOR(i, 2, n) {
        cnt[i] = i <= k ? frac[i - 1] : 0;
        int L = max(1, i - k);
        int tmp = (sum[i - 1] - sum[L - 1] + MOD) % MOD;
        cnt[i] = (cnt[i] + 1LL * tmp * frac[i - 1]) % MOD;
        sum[i] = (sum[i - 1] + 1LL * cnt[i] * finv[i]) % MOD;
//        FOR(j, 1, k) if (i > j) cnt[i] = (cnt[i] + 1LL * cnt[i - j] * frac[i - 1] % MOD * finv[i - j]) % MOD;
    }

//    FOR(i, 1, n) printf("count %d is %d\n", i, cnt[i]);

    int res = frac[n - 1];
    FOR(i, 2, n) {
        res = (res + 1LL * cnt[i - 1] * frac[n - 1] % MOD * finv[i - 1]) % MOD;
//        cerr << res << endl;
    }

    printf("%d\n", (frac[n] - res + MOD) % MOD);
}

int main(void) {
    prepare();
    process();
    return 0;
}


/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/