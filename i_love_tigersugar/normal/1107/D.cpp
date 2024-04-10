#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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

#define MAX   5555

bool val[MAX][MAX];
int sum[MAX][MAX];
int n;
char input[MAX];

int getSum(int x1, int y1, int t) {
    int x2 = x1 + t - 1;
    int y2 = y1 + t - 1;
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

bool sameValue(int x, int y, int t) {
    int tmp = getSum(x, y, t);
    return tmp == 0 || tmp == t * t;
}

bool ok(int t) {
    if (n % t != 0) return false;
    REP(i, n / t) REP(j, n / t) if (!sameValue(i * t + 1, j * t + 1, t)) return false;
    return true;
}

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%s", input);
        int pos = 0;
        REP(j, n / 4) {
            int mask = '0' <= input[j] && input[j] <= '9' ? input[j] - '0' : input[j] - 'A' + 10;
            FORD(k, 3, 0) val[i][++pos] = BIT(mask, k);
        }
    }

    FOR(i, 1, n) FOR(j, 1, n) sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + val[i][j];

    FORD(i, n, 1) if (ok(i)) {
        printf("%d\n", i);
        return;
    }
    assert(false);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/