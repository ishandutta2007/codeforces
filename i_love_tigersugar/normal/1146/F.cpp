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

const int MOD = 998244353;

#define MAX   200200
int f[MAX][3];
vector<int> children[MAX];
int n;

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 2, n) {
        int u; scanf("%d", &u);
        children[u].push_back(i);
    }
}

void dfs(int u) {
    if (children[u].empty()) {
        f[u][2] = 1;
        return;
    }

    int prev[3] = {0, 0, 0};
    f[u][0] = 1;

    FORE(it, children[u]) {
        int v = *it;
        dfs(v);

        REP(i, 3) {
            prev[i] = f[u][i];
            f[u][i] = 0;
        }
        REP(i, 3) REP(j, 3) REP(chs, 2) if (j + chs != 1) {
            int newI = min(i + chs, 2);
            f[u][newI] = (f[u][newI] + 1LL * prev[i] * f[v][j]) % MOD;
        }
    }
}

void process(void) {
    dfs(1);
    cout << (f[1][0] + f[1][2]) % MOD << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/