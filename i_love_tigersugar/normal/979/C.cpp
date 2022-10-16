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

#define MAX   300300

int n, x, y;
vector<int> adj[MAX];
int numChild[MAX], par[MAX];
bool marked[MAX];

void loadTree(void) {
    scanf("%d%d%d", &n, &x, &y);
    REP(aye, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u) {
    numChild[u] = 1;
    FORE(it, adj[u]) if (*it != par[u]) {
        int v = *it;
        par[v] = u;
        dfs(v);
        numChild[u] += numChild[v];
    }
}

void process(void) {
    dfs(x);
    for (int u = y; u != x; u = par[u]) marked[u] = true;

    int numX = 1;
    FORE(it, adj[x]) if (!marked[*it]) numX += numChild[*it];
    int numY = numChild[y];
    cout << 1LL * n * (n - 1) - 1LL * numX * numY << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/