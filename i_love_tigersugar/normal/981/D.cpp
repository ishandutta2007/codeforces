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

#define MAX   111
#define NUM_BIT   60

int n, m;
long long value[MAX], sum[MAX];
bool f[MAX][MAX];

void init(void) {
    cin >> n >> m;
    FOR(i, 1, n) cin >> value[i];
    FOR(i, 1, n) sum[i] = sum[i - 1] + value[i];
}

bool canMatch(long long mask) {
    memset(f, false, sizeof f);
    f[0][0] = true;
    REP(i, n) REP(j, m) if (f[i][j]) FOR(k, i + 1, n) {
        long long tmp = sum[k] - sum[i];
        if ((tmp & mask) == mask) f[k][j + 1] = true;
    }
    return f[n][m];
}

void process(void) {
    long long res = 0;
    FOR(pos, 1, NUM_BIT) {
        long long tmpRes = (res << 1) ^ 1;
        long long pattern = tmpRes << (NUM_BIT - pos);
        if (canMatch(pattern)) res = tmpRes; else res = tmpRes ^ 1;
    }
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/