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

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int a; cin >> a;
    return a;
}

void answer(int x) {
    cout << "! " << x << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   100100
int n;
vector<int> adj[MAX];

void solve(int u, int par, bool needAsk) {
    if (!needAsk && par > 0) {
        adj[u].erase(find(ALL(adj[u]), par));
    }
    REP(i, adj[u].size() / 2) {
        int x = adj[u][2 * i];
        int y = adj[u][2 * i + 1];
        int z = ask(x, y);
        if (z == x || z == y) {
            if (z == par) answer(z); else return solve(z, u, false);
        }
    }
    if (adj[u].size() % 2 == 0) answer(u);
    if (adj[u].back() == par) answer(ask(u, par));
    solve(adj[u].back(), u, true);
}

void process(void) {
    cin >> n;
    REP(love, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1, 0, false);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/