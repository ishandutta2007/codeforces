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

#define MAX   3030
const int MOD = (int)1e9 + 7;
const int DEGREE = 6161;

int numNode, numFood;
int numWay[MAX][DEGREE + 7];
vector<int> children[MAX];

int inv[DEGREE + 7], negInv[DEGREE + 7];
int prodLeft[DEGREE + 7], prodRight[DEGREE + 7];

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void loadTree(void) {
    scanf("%d%d", &numNode, &numFood);
    FOR(i, 2, numNode) {
        int p; scanf("%d", &p);
        children[p].push_back(i);
    }
}

void dfs(int u) {
    if (children[u].empty()) {
        FOR(i, 1, DEGREE) numWay[u][i] = i;
        return;
    }

    FORE(it, children[u]) dfs(*it);
    FOR(i, 1, DEGREE) {
        numWay[u][i] = 1;
        FORE(jt, children[u]) numWay[u][i] = 1LL * numWay[u][i] * numWay[*jt][i] % MOD;
    }
    FOR(i, 1, DEGREE) add(numWay[u][i], numWay[u][i - 1]);
}

int inverse(int x) {
    int res = 1, mul = x, k = MOD - 2;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }
    assert(1LL * res * x % MOD == 1);
    return res;
}

void process(void) {
    dfs(1);
//    FOR(i, 1, 10) printf("%d ", numWay[1][i]); printf("\n");

    FOR(i, 1, DEGREE) {
        inv[i] = inverse(i);
        negInv[i] = inverse(MOD - i);
    }

    #define INV(x) ((x) > 0 ? inv[x] : negInv[-(x)])

    prodLeft[0] = prodRight[DEGREE + 1] = 1;
    FOR(i, 1, DEGREE) prodLeft[i] = 1LL * prodLeft[i - 1] * (numFood - i + MOD) % MOD;
    FORD(i, DEGREE, 1) prodRight[i] = 1LL * prodRight[i + 1] * (numFood - i + MOD) % MOD;

    int res = 0;
    FOR(i, 1, DEGREE) {
        int prod = numWay[1][i];
        prod = 1LL * prod * prodLeft[i - 1] % MOD;
        prod = 1LL * prod * prodRight[i + 1] % MOD;
        if (i == numFood) cerr << prod << endl;
        FOR(j, 1, DEGREE) if (j != i) prod = 1LL * prod * INV(i - j) % MOD;
        add(res, prod);
    }
    printf("%d\n", res);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/