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

/* Author: Van Hanh Pham - skyvn97 */

class DisjointSet {
    private:
    vector<int> lab;

    public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
    }

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }
    bool join(int u, int v) {
        int x = find(u);
        int y = find(v);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   200200
#define LOG   18
const long long INF = (long long)1e18 + 7LL;

struct Edge {
    int u, v, value, cost, id;
    bool inTree;

    Edge() {
        u = v = value = cost = id = 0;
        inTree = false;
    }

    int other(int x) const {
        assert(u == x  || v == x);
        return u ^ v ^ x;
    }
    bool operator < (const Edge &e) const {
        return value < e.value;
    }
};

Edge edges[MAX];
vector<int> treeAdj[MAX];
int par[MAX][LOG + 1], maxEdge[MAX][LOG + 1];
int n, m, allow, high[MAX];

void loadGraph(void) {
    scanf("%d%d", &n, &m);
    REP(i, m) edges[i].id = i + 1;
    REP(i, m) scanf("%d", &edges[i].value);
    REP(i, m) scanf("%d", &edges[i].cost);
    REP(i, m) scanf("%d%d", &edges[i].u, &edges[i].v);
    scanf("%d", &allow);
}

void buildSpanningTree(void) {
    sort(edges, edges + m);
    DisjointSet dsu(n);
    REP(i, m) edges[i].inTree = dsu.join(edges[i].u, edges[i].v);
    REP(i, m) if (edges[i].inTree) {
        treeAdj[edges[i].u].push_back(i);
        treeAdj[edges[i].v].push_back(i);
    }
}

void dfs(int u) {
    FORE(it, treeAdj[u]) {
        int v = edges[*it].other(u);
        if (v != par[u][0]) {
            par[v][0] = u;
            maxEdge[v][0] = edges[*it].value;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}

void setupLCA(void) {
    high[0] = -1;
    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[par[i][j - 1]][j - 1]);
    }
}
int getMaxEdge(int u, int v) {
    if (high[u] < high[v]) return getMaxEdge(v, u);
    int res = -1;
    FORD(i, LOG, 0) if (high[par[u][i]] >= high[v]) {
        maximize(res, maxEdge[u][i]);
        u = par[u][i];
    }
    if (u == v) return res;
    FORD(i, LOG, 0) if (par[u][i] != par[v][i]) {
        maximize(res, maxEdge[u][i]);
        maximize(res, maxEdge[v][i]);
        u = par[u][i];
        v = par[v][i];
    }
    maximize(res, maxEdge[u][0]);
    maximize(res, maxEdge[v][0]);
    return res;
}

void process(void) {
    long long totValue = 0;
    REP(i, m) if (edges[i].inTree) totValue += edges[i].value;
    long long best = INF;
    int bestRemEdge = 0;
    REP(i, m) {
        long long newTotValue = totValue + edges[i].value - getMaxEdge(edges[i].u, edges[i].v);
        int canRem = allow / edges[i].cost;
        if (newTotValue - canRem < best) {
            best = newTotValue - canRem;
            bestRemEdge = i;
        }
    }

    cout << best << endl;
    cout << edges[bestRemEdge].id << " " << edges[bestRemEdge].value - allow / edges[bestRemEdge].cost << endl;
    DisjointSet dsu(n);
    assert(dsu.join(edges[bestRemEdge].u, edges[bestRemEdge].v));
    REP(i, m) if (i != bestRemEdge)
        if (dsu.join(edges[i].u, edges[i].v)) cout << edges[i].id << " " << edges[i].value << "\n";
}

int main(void) {
    loadGraph();
    buildSpanningTree();
    setupLCA();
    process();
    return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/