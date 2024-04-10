#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const int NUM_DIGIT = 15;

int solve(long long n) {
    int dig[NUM_DIGIT + 3];
    memset(dig, 0, sizeof dig);
    int pos = 0;
    while (n > 0) {
        dig[pos++] = n % 10;
        n /= 10;
    }

    int f[NUM_DIGIT + 3][2];
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    REP(i, NUM_DIGIT) REP(j, 2) if (f[i][j] >= 0)
        REP(a, 10) REP(b, 10) if ((a + b + j) % 10 == dig[i])
            maximize(f[i + 1][a + b + j >= 10], f[i][j] + a + b);
    return f[NUM_DIGIT][0];
}

int main(void) {
    long long input;
    while (cin >> input) cout << solve(input) << endl;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/