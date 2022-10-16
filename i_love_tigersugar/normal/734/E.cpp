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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

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

    bool join(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

#define MAX   200200

pair<int, int> edges[MAX];
int color[MAX], numNode, numComp;
int compID[MAX];
vector<int> adj[MAX];
int high[MAX];

void loadTree(void) {
    scanf("%d", &numNode);
    FOR(i, 1, numNode) scanf("%d", &color[i]);
    REP(i, numNode - 1) scanf("%d%d", &edges[i].fi, &edges[i].se);
}

void buildTree(void) {
    DisjointSet dsu(numNode);
    REP(i, numNode - 1) if (color[edges[i].fi] == color[edges[i].se]) dsu.join(edges[i].fi, edges[i].se);

    FOR(i, 1, numNode) if (dsu.find(i) == i) compID[i] = ++numComp;
    FOR(i, 1, numNode) if (dsu.find(i) != i) compID[i] = compID[dsu.find(i)];
    REP(i, numNode - 1) if (color[edges[i].fi] != color[edges[i].se]) {
        int u = compID[edges[i].fi];
        int v = compID[edges[i].se];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int bfs(int s) {
    memset(high, -1, sizeof high);
    queue<int> q;
    high[s] = 0; q.push(s);
    int res = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res = u;
        FORE(it, adj[u]) if (high[*it] < 0) {
            high[*it] = high[u] + 1;
            q.push(*it);
        }
    }
    return res;
}

void process(void) {
    int t = bfs(bfs(1));
    printf("%d\n", (high[t] + 1) / 2);
}

int main(void) {
    loadTree();
    buildTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/