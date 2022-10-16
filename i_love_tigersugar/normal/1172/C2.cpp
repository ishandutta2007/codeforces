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

#define MAX_PIC   200200
#define MAX   3030
const int MOD = 998244353;

int numPic, numStep;
int weight[MAX_PIC], like[MAX_PIC], sumWeight, sumPos, sumNeg;
int prob[MAX][MAX];
int inv[MAX * 2];

map<int, int> savedInverse;
int inverse(int x) {
    int res = 1, mul = x, k = MOD - 2;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }
    return res;
}

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void init(void) {
    scanf("%d%d", &numPic, &numStep);
    FOR(i, 1, numPic) scanf("%d", &like[i]);
    FOR(i, 1, numPic) scanf("%d", &weight[i]);
    FOR(i, 1, numPic) {
        if (like[i]) add(sumPos, weight[i]); else add(sumNeg, weight[i]);
    }
    sumWeight = (sumPos + sumNeg) % MOD;
    FOR(i, -MAX, MAX) {
        int j = (sumWeight + i + MOD) % MOD;
        inv[i + MAX] = inverse(j);
    }
}

void process(void) {
    prob[0][0] = 1;
    REP(step, numStep) REP(pos, step + 1) if (prob[step][pos] > 0) {
        int neg = step - pos;
        int sum = sumWeight + pos - neg; assert(sum > 0);
        int sumINV = inv[pos - neg + MAX];
        int probPos = 1LL * (sumPos + pos) * sumINV % MOD;
        int probNeg = (1 - probPos + MOD) % MOD;

        add(prob[step + 1][pos + 1], 1LL * probPos * prob[step][pos] % MOD);
        add(prob[step + 1][pos], 1LL * probNeg * prob[step][pos] % MOD);
    }

    int expPos = 0, expNeg = 0;
    FOR(pos, 0, numStep) add(expPos, 1LL * prob[numStep][pos] * pos % MOD);
    expNeg = (numStep - expPos + MOD) % MOD;

    FOR(i, 1, numPic) {
        int res;
        if (like[i]) {
            res = 1LL * weight[i] * inverse(sumPos) % MOD * expPos % MOD;
            printf("%d\n", (weight[i] + res) % MOD);
        } else {
            res = 1LL * weight[i] * inverse(sumNeg) % MOD * expNeg % MOD;
            printf("%d\n", (weight[i] - res + MOD) % MOD);
        }
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/