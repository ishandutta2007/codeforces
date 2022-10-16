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

#define MAX   200200
const int MOD = 998244353;

int numNode;
vector<int> adj[MAX];
int f[MAX];

void loadTree(void) {
    scanf("%d", &numNode);
    REP(love, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (numNode == 2) {
        cout << 2 << endl;
        exit(EXIT_SUCCESS);
    }
}

void dfs(int u, int par) {
    int numChild = 0;
    f[u] = 1;
    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        dfs(v, u);
        f[u] = 1LL * f[u] * f[v] % MOD;
        numChild++;
    }
    FOR(i, 2, numChild + 1) f[u] = 1LL * f[u] * i % MOD;
}

void process(void) {
    FOR(i, 1, numNode) if (adj[i].size() > 1) {
        dfs(i, -1);
        int res = numNode;
        FORE(jt, adj[i]) res = 1LL * res * f[*jt] % MOD;
        FOR(j, 2, adj[i].size()) res = 1LL * res * j % MOD;
        cout << res << endl;
        return;
    }
    assert(false);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/