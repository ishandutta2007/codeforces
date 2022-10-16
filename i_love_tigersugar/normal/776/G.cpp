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

#define NUM_DIGIT   15
#define DIGIT(x, i) (((x) >> (4 * (i))) & 15)

long long f[NUM_DIGIT + 1][2][2];

long long readNumber(void) {
    string s; cin >> s;
    long long res = 0;
    FORE(it, s) {
        int c = '0' <= *it && *it <= '9' ? *it - '0' : *it - 'a' + 10;
        res = (res << 4) | c;
    }
    return res;
}

long long calc(long long lim, int maxXorBit) {
    memset(f, 0, sizeof f);
    f[0][1][0] = 1;
    REP(i, NUM_DIGIT) REP(j, 2) REP(k, 2) if (f[i][j][k] > 0) REP(t, maxXorBit + 1) {
        if (i == maxXorBit / 4 && !BIT(t, maxXorBit % 4)) continue;

        int dig = DIGIT(lim, i);
        int newJ = t != dig ? t < dig : j;
        f[i + 1][newJ][k || (t == maxXorBit)] += f[i][j][k];
    }

    return f[NUM_DIGIT][1][1];
}

long long countLess(long long lim) {
    if (lim < 0) return 0;

    long long res = 0;
    REP(i, 16) res += calc(lim, i);
    return res;
}

long long answer(long long l, long long r) {
    return countLess(r) - countLess(l - 1);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    REP(love, t) {
        long long l = readNumber();
        long long r = readNumber();
        cout << answer(l, r) << "\n";
    }

    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/