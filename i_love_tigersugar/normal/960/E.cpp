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
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   300300
const int MOD = (int)1e9 + 7;

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void sub(int &x, const int &y) {
    x -= y;
    if (x < 0) x += MOD;
}

int value[MAX], n;
vector<int> adj[MAX];
int countPath[MAX][2], sumPath[MAX][2], sumPathWithLCA[MAX];

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);
    REP(aye, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) value[i] = (value[i] % MOD + MOD) % MOD;
}

#define DEBUG(x) ((x) < MOD / 2 ? (x) : (x) - MOD)

void dfs(int u, int par) {
    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        dfs(v, u);

        REP(i, 2) {
            int tmp = (1LL * sumPath[u][i] * countPath[v][i] + 1LL * sumPath[v][i] * countPath[u][i]) % MOD;
            if (i == 0) sub(sumPathWithLCA[u], tmp); else add(sumPathWithLCA[u], tmp);
            tmp = 1LL * countPath[u][i] * countPath[v][i] % MOD * value[u] % MOD;
            if (i == 0) add(sumPathWithLCA[u], tmp); else sub(sumPathWithLCA[u], tmp);
        }

        REP(i, 2) {
            add(sumPath[u][i], sumPath[v][i]);
            add(countPath[u][i], countPath[v][i]);
        }
    }

    REP(i, 2) sumPath[u][i] = (1LL * countPath[u][i] * value[u] - sumPath[u][i] + MOD) % MOD;
    swap(countPath[u][0], countPath[u][1]);
    swap(sumPath[u][0], sumPath[u][1]);
    add(countPath[u][1], 1);
    add(sumPath[u][1], value[u]);
    add(sumPathWithLCA[u], sumPath[u][1]);

//    printf("AT NODE %d: %d\n", u, DEBUG(sumPathWithLCA[u]));
//    REP(i, 2) printf("With parity %d: sum = %d, count = %d\n", i, DEBUG(sumPath[u][i]), DEBUG(countPath[u][i]));
}

void process(void) {
    dfs(1, -1);
    int res = 0;
    FOR(i, 1, n) add(res, sumPathWithLCA[i]);
    res = (2 * res) % MOD;
    FOR(i, 1, n) sub(res, value[i]);
    cout << res << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/