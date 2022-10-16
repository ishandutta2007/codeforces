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

#define MAX   100100
#define VALUE   200
const int MOD = 998244353;

int f[MAX][2][VALUE + 3];
int sumF[MAX][2][VALUE + 3];
int a[MAX], n;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

int sum(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int subtract(int a, int b) {
    return a >= b ? a - b : a - b + MOD;
}

void process(void) {
    FOR(i, 1, VALUE) {
        f[1][0][i] = a[1] == i || a[1] < 0 ? 1 : 0;
        sumF[1][0][i] = sum(sumF[1][0][i - 1], f[1][0][i]);
    }

    FOR(pos, 2, n) REP(ok, 2) FOR(val, 1, VALUE) {
        if (a[pos] > 0 && a[pos] != val) f[pos][ok][val] = 0;
        else {
            if (!ok) f[pos][ok][val] = sum(sumF[pos - 1][0][val - 1], sumF[pos - 1][1][val - 1]);
            else {
                f[pos][ok][val] = subtract(sumF[pos - 1][1][VALUE], sumF[pos - 1][1][val]);
                REP(j, 2) f[pos][ok][val] = sum(f[pos][ok][val], f[pos - 1][j][val]);
            }
        }

        sumF[pos][ok][val] = sum(sumF[pos][ok][val - 1], f[pos][ok][val]);
    }

    printf("%d\n", sumF[n][1][VALUE]);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/