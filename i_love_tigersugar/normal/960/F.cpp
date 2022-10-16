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

class FenwickTree {
    vector<int> v;
    int n;

public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) maximize(v[x], d);
    }

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) maximize(res, v[x]);
        return res;
    }
};

struct Edge {
    int from, to, cost;

    Edge() {
        from = to = cost = 0;
    }

    void input(void) {
        scanf("%d%d%d", &from, &to, &cost);
    }
};

#define MAX   300300

Edge edges[MAX];
vector<int> inEdges[MAX], inCosts[MAX];
int maxPath[MAX];
int numNode, numEdge;
FenwickTree bit[MAX];

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    FOR(i, 1, numEdge) edges[i].input();
}

void prepare(void) {
    FOR(i, 1, numEdge) {
        inEdges[edges[i].to].push_back(i);
        inCosts[edges[i].to].push_back(edges[i].cost);
    }

    FOR(i, 1, numNode) if (!inCosts[i].empty()) {
        vector<int> &costs = inCosts[i];
        sort(ALL(costs));
        costs.resize(unique(ALL(costs)) - costs.begin());
    }

    FOR(i, 1, numEdge) {
        vector<int> &costs = inCosts[edges[i].to];
        int j = lower_bound(ALL(costs), edges[i].cost) - costs.begin();
        edges[i].cost = j;
    }

    FOR(i, 1, numNode) if (!inCosts[i].empty()) bit[i] = FenwickTree(inCosts[i].size());
}

int getRealCost(int id) {
    int tmp = edges[id].cost;
    return inCosts[edges[id].to][tmp];
}

int getMaxPath(int node, int maxCost) {
    vector<int> &costs = inCosts[node];
    FenwickTree &curBit = bit[node];

    if (costs.empty()) return 0;
    if (maxCost > costs.back()) return curBit.get(costs.size());

    int id = lower_bound(ALL(costs), maxCost) - costs.begin();
    return curBit.get(id);
}

void process(void) {
    int res = 0;
    FOR(i, 1, numEdge) {
        maxPath[i] = getMaxPath(edges[i].from, getRealCost(i)) + 1;
        maximize(res, maxPath[i]);
        bit[edges[i].to].update(edges[i].cost + 1, maxPath[i]);
    }

    printf("%d\n", res);
}

int main(void) {
    loadGraph();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/