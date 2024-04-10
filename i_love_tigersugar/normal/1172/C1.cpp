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

#define MAX   55
const int MOD = 998244353;

int numPic, numStep;
int weight[MAX], like[MAX], sumWeight, sumPos, sumNeg;
int prob[MAX][MAX][MAX];
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

int calc(int picID) {
    memset(prob, 0, sizeof prob);
    prob[0][0][0] = 1;
    REP(step, numStep) REP(pos, step + 1) REP(cur, step + 1) if (prob[step][pos][cur] > 0) {
        int neg = step - pos;
        int sum = sumWeight + pos - neg; assert(sum > 0);
        int sumINV = inv[pos - neg + MAX];

        int probPos = 1LL * (sumPos + pos) * sumINV % MOD;
        int probNeg = (1 - probPos + MOD) % MOD;
        int probThis = 1LL * (weight[picID] + (like[picID] ? cur : -cur) + MOD) * sumINV % MOD;
        if (like[picID]) probPos = (probPos - probThis + MOD) % MOD;
        else probNeg = (probNeg - probThis + MOD) % MOD;

        add(prob[step + 1][like[picID] ? pos + 1 : pos][cur + 1], 1LL * probThis * prob[step][pos][cur] % MOD);
        add(prob[step + 1][pos + 1][cur], 1LL * probPos * prob[step][pos][cur] % MOD);
        add(prob[step + 1][pos][cur], 1LL * probNeg * prob[step][pos][cur] % MOD);
    }

    int res = 0;
    FOR(i, 0, numStep) {
        int value = like[picID] ? weight[picID] + i : weight[picID] - i;
        FOR(j, 0, numStep) add(res, 1LL * value * prob[numStep][j][i] % MOD);
    }
    return res;
}

void process(void) {
    FOR(i, 1, numPic) printf("%d\n", calc(i));
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/