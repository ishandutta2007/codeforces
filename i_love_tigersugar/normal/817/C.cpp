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

#define NUM_DIGIT   20

struct Number {
    int digits[NUM_DIGIT + 3];

    Number(long long x = 0) {
        memset(digits, 0, sizeof digits);
        REP(i, NUM_DIGIT) {
            digits[i] = x % 10;
            x /= 10;
        }
    }

    int operator [] (int x) const {
        return digits[x];
    }
};

long long f[NUM_DIGIT + 3][NUM_DIGIT * 9 + 3][2][2];

long long calcNumber(long long l, long long r, int sum) {
    if (l > r) return 0;
    Number L(l), R(r);

    memset(f, 0, sizeof f);
    f[0][0][1][1] = 1;
    REP(i, NUM_DIGIT) REP(j, sum + 1) REP(x, 2) REP(y, 2) if (f[i][j][x][y] > 0) REP(t, 10) {
        int newX = t != L[i] ? t > L[i] : x;
        int newY = t != R[i] ? t < R[i] : y;
        if (j + t <= sum) f[i + 1][j + t][newX][newY] += f[i][j][x][y];
    }

    return f[NUM_DIGIT][sum][1][1];
}

long long solve(long long n, long long s) {
    long long res = 0;
    REP(sum, NUM_DIGIT * 9 + 1) res += calcNumber(sum + s, n, sum);
    return res;
}

int main(void) {
    long long n, s; while (cin >> n >> s) cout << solve(n, s) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/