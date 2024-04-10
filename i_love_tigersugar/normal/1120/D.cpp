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
const long long INF = (long long)1e18 + 7LL;

int n;
vector<int> adj[MAX];
int cost[MAX];
long long bestTree[MAX][2];
vector<long long> bestSub[MAX][2];
vector<int> nodes;
int numChild[MAX];

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &cost[i]);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void calcdp(int u, int par) {
    FORE(it, adj[u]) if (*it != par) {
        numChild[u]++;
        calcdp(*it, u);
    }

    if (numChild[u] == 0) {
        bestTree[u][0] = cost[u];
        bestTree[u][1] = 0;
        return;
    }

    REP(i, 2) {
        bestSub[u][i].assign(adj[u].size() + 3, INF);
    }
    bestSub[u][0][0] = 0;

    int pos = 0;
    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        REP(i, 2) REP(j, 2) if (i + j < 2)
            minimize(bestSub[u][i + j][pos + 1], bestSub[u][i][pos] + bestTree[v][j]);
        pos++;
    }
    assert(pos == numChild[u]);

    REP(i, 2) {
        bestTree[u][i] = bestSub[u][i][pos];
        minimize(bestTree[u][0], bestSub[u][i][pos] + cost[u]);
    }
}

void trace(int u, int mask, int par) {
    if (numChild[u] == 0) {
        if (BIT(mask, 0)) nodes.push_back(u);
        return;
    }

    int curMask = 0;
    int pos = numChild[u];
    REP(i, 2) {
        if (BIT(mask, i) && bestTree[u][i] == bestSub[u][i][pos]) curMask |= MASK(i);
        if (BIT(mask, 0) && bestTree[u][0] == bestSub[u][i][pos] + cost[u]) {
            nodes.push_back(u);
            curMask |= MASK(i);
        }
    }

    reverse(ALL(adj[u]));

    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        int newMask = 0, childMask = 0;
        REP(i, 2) REP(j, 2)
            if (BIT(curMask, i + j) && bestSub[u][i][pos - 1] + bestTree[v][j] == bestSub[u][i + j][pos]) {
                newMask |= MASK(i); childMask |= MASK(j);
            }
        trace(v, childMask, u);
        pos--;
        curMask = newMask;
    }
}

void process(void) {
    calcdp(1, -1);

    trace(1, MASK(0), -1);
    sort(ALL(nodes));
    nodes.resize(unique(ALL(nodes)) - nodes.begin());

    cout << bestTree[1][0] << " " << nodes.size() << endl;
    FORE(it, nodes) cout << *it << " "; cout << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/