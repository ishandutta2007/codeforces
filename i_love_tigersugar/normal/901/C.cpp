#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

class DisjointSet {
private:
    vector<int> lab;
    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

public:
    DisjointSet(int n = 0) {
        if (n > 0) lab.assign(n + 7, -1);
    }

    bool join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

struct Edge {
    int u, v;
    bool inTree;

    Edge(int _u = 0, int _v = 0) {
        u = _u; v = _v;
        if (u > v) swap(u, v);
        inTree = false;
    }

    void input(void) {
        int x, y; scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        u = x; v = y;
    }

    bool operator < (const Edge &e) const {
        return v - u < e.v - e.u;
    }

    int other(int x) const {
        assert(u == x || v == x);
        return u ^ v ^ x;
    }
};

#define MAX   300300
#define LOG   19
int numNode, numEdge, numQuery;
Edge edges[MAX];
vector<int> adj[MAX];
int high[MAX], par[MAX][LOG + 1], minValue[MAX][LOG + 1], maxValue[MAX][LOG + 1];
int treeRange[MAX];
long long sumRange[MAX];

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    FOR(i, 1, numEdge) edges[i].input();
    sort(edges + 1, edges + numEdge + 1);
    FOR(i, 1, numEdge) {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }
}

void dfs(int u) {
    FORE(it, adj[u]) if (edges[*it].inTree) {
        int v = edges[*it].other(u);
        if (v == par[u][0]) continue;
        par[v][0] = u;
        high[v] = high[u] + 1;
        dfs(v);
    }
}

void buildSpanningTree(void) {
    DisjointSet dsu(numNode);
    FOR(i, 1, numEdge) edges[i].inTree = dsu.join(edges[i].u, edges[i].v);
    high[0] = -1;
    FOR(i, 1, numNode) if (par[i][0] == 0) dfs(i);
    FOR(i, 1, numNode) minValue[i][0] = maxValue[i][0] = par[i][0];
    FOR(j, 1, LOG) FOR(i, 1, numNode) {
        int tmp = par[i][j - 1];
        par[i][j] = par[tmp][j - 1];
        minValue[i][j] = min(minValue[i][j - 1], minValue[tmp][j - 1]);
        maxValue[i][j] = max(maxValue[i][j - 1], maxValue[tmp][j - 1]);
    }
}

pair<int, int> findRange(int u, int v) {
    if (high[u] < high[v]) return findRange(v, u);
    int minNode = min(u, v), maxNode = max(u, v);
    FORD(i, LOG, 0) if (high[par[u][i]] >= high[v]) {
        minimize(minNode, minValue[u][i]);
        maximize(maxNode, maxValue[u][i]);
        u = par[u][i];
    }
    if (u == v) return make_pair(minNode, maxNode);
    FORD(i, LOG, 0) if (par[u][i] != par[v][i]) {
        minimize(minNode, min(minValue[u][i], minValue[v][i]));
        maximize(maxNode, max(maxValue[u][i], maxValue[v][i]));
        u = par[u][i]; v = par[v][i];
    }
    minimize(minNode, min(minValue[u][0], minValue[v][0]));
    maximize(maxNode, max(maxValue[u][0], maxValue[v][0]));
    return make_pair(minNode, maxNode);
}

void calcRange(void) {
    vector<pair<int, int>> blockedRange;
    FOR(i, 1, numEdge) if (!edges[i].inTree) blockedRange.push_back(findRange(edges[i].u, edges[i].v));
    sort(ALL(blockedRange), greater<pair<int, int>> ());

    int j = 0;
    int maxRange = numNode;
    FORD(i, numNode, 1) {
        while (j < blockedRange.size() && blockedRange[j].fi >= i)
            minimize(maxRange, blockedRange[j++].se - 1);
        treeRange[i] = max(i - 1, maxRange);
    }

    FOR(i, 1, numNode) sumRange[i] = sumRange[i - 1] + (treeRange[i] - i + 1);
}

long long query(int l, int r) {
    int id = upper_bound(treeRange + 1, treeRange + numNode + 1, r) - treeRange;
    if (id > r) return sumRange[r] - sumRange[l - 1];
    if (id <= l) return 1LL * (r - l + 1) * (r - l + 2) / 2;
    long long res = 0;
    if (id > l) res += sumRange[id - 1] - sumRange[l - 1];
    if (r >= id) res += 1LL * (r - id + 1) * (r - id + 2) / 2;
    return res;
}

void process(void) {
    scanf("%d", &numQuery);
    REP(love, numQuery) {
        int l, r; scanf("%d%d", &l, &r);
        cout << query(l, r) << "\n";
    }
}

int main(void) {
    loadGraph();
    buildSpanningTree();
    calcRange();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/