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

#define MAX   1500150
const int MOD = (int)1e9 + 7;

int pw2[MAX];

void precalc(void) {
    pw2[0] = 1;
    FOR(i, 1, MAX - 1) pw2[i] = 2 * pw2[i - 1] % MOD;
}

int solve(const string &s) {
    int res = 0;
    int cntA = 0;

    FORE(it, s) {
        if (*it == 'a') cntA++;
        else res = (res + pw2[cntA] - 1) % MOD;
    }

    return (res % MOD + MOD) % MOD;
}

int main(void) {
    precalc();

    string s; while (cin >> s) cout << solve(s) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/