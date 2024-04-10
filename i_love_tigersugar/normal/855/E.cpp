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

#define MAX_BASE   11
#define MAX_LEN   60

long long countWay[MAX_BASE + 2][MAX_LEN + 2][MASK(MAX_BASE) + 2];

void precalc(void) {
    FOR(base, 2, MAX_BASE) {
        countWay[base][0][0] = 1;
        REP(len, MAX_LEN) REP(mask, MASK(base)) if (countWay[base][len][mask] > 0) {
            REP(next, base) countWay[base][len + 1][mask ^ MASK(next)] += countWay[base][len][mask];
        }
    }
}

vector<int> getDigits(int base, long long value) {
    assert(value > 0);
    vector<int> v;
    while (value > 0) {
        v.push_back(value % base);
        value /= base;
    }
    return v;
}
long long answer(int base, long long limit) {
    if (limit < 1) return 0;
    vector<int> digits = getDigits(base, limit);

    long long res = 0;
    FOR(len, 1, digits.size() - 1) FOR(dig, 1, base - 1)
        res += countWay[base][len - 1][MASK(dig)];

    int mask = 0;
    FORD(pos, digits.size() - 1, 0) {
        FOR(dig, pos == digits.size() - 1 ? 1 : 0, digits[pos] - 1) {
            res += countWay[base][pos][mask ^ MASK(dig)];
        }
        mask ^= MASK(digits[pos]);
    }

    return res + (mask == 0);
}

int main(void) {
    precalc();
    int q; cin >> q;
    REP(pmp, q) {
        int b; long long l, r; cin >> b >> l >> r;
        cout << answer(b, r) - answer(b, l - 1) << "\n";
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/