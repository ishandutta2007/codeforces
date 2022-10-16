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

struct Edge {
    int from, to;

    Edge(int _from = 0, int _to = 0) {
        from = _from; to = _to;
    }

    int other(int x) const {
        assert(x == from || x == to);
        return x ^ from ^ to;
    }

    int costDirectTo(int x) const {
        assert(x == from || x == to);
        return x == from ? 1 : 0;
    }
};

#define MAX   3030
const int INF = (int)1e9 + 7;

Edge edges[MAX];
int numNode;
vector<int> adj[MAX];
int cacheCenterCost[MAX][MAX];
int pathCost[MAX][2], bestResult;

void loadTree(void) {
    scanf("%d", &numNode);
    FOR(i, 1, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        edges[i] = Edge(u, v);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
}

int centerCost(int u, int par) {
    int &result = cacheCenterCost[u][par];
    if (result >= 0) return result;

    result = 0;
    FORE(it, adj[u]) {
        int v = edges[*it].other(u);
        if (v == par) continue;

        result += edges[*it].costDirectTo(v) + centerCost(v, u);
    }

//    printf("CENTER COST %d parent %d is %d\n", u, par, result);
    return result;
}

#define UP   0
#define DOWN   1
void calcPathCost(int u, int par) {
    REP(i, 2) minimize(bestResult, pathCost[u][i] + centerCost(u, par));
//    printf("\tCost at %d, UP is %d\n", u, pathCost[u][UP]);
//    printf("\tCost at %d, DOWN is %d\n", u, pathCost[u][DOWN]);

    FORE(it, adj[u]) {
        int v = edges[*it].other(u);
        if (v == par) continue;

        int branchCost = centerCost(u, par) - edges[*it].costDirectTo(v) - centerCost(v, u);
        minimize(pathCost[v][UP], pathCost[u][DOWN] + branchCost + edges[*it].costDirectTo(u));
        minimize(pathCost[v][UP], pathCost[u][UP] + branchCost + edges[*it].costDirectTo(u));
        minimize(pathCost[v][DOWN], pathCost[u][DOWN] + branchCost + edges[*it].costDirectTo(v));

        calcPathCost(v, u);
    }
}

void process(void) {
    memset(cacheCenterCost, -1, sizeof cacheCenterCost);

    bestResult = INF;
    FOR(root, 1, numNode) {
//        printf("At root %d\n", root);
        memset(pathCost, 0x3f, sizeof pathCost);
        pathCost[root][0] = pathCost[root][1] = 0;
        calcPathCost(root, 0);
    }

    cout << bestResult << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/