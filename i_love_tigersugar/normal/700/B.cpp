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

#define MAX   200200

vector<int> adj[MAX];
int numNode, numPair;
bool marked[MAX];
int numMarked[MAX];
int dist[MAX], par[MAX], branch[MAX];

void loadTree(void) {
    scanf("%d%d", &numNode, &numPair);
    REP(pmp, 2 * numPair) {
        int x; scanf("%d", &x);
        marked[x] = true;
    }
    REP(pmp, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u) {
    numMarked[u] = marked[u];
    FORE(it, adj[u]) if (*it != par[u]) {
        int v = *it;
        par[v] = u;
        dist[v] = dist[u] + 1;
        branch[v] = dist[v] < 2 ? v : branch[u];
        dfs(v);
        numMarked[u] += numMarked[v];
    }
}

bool isCentroid(int u) {
    FORE(it, adj[u]) if (*it != par[u] && numMarked[*it] > numPair) return false;
    return numMarked[u] >= numPair;
}

int findRoot(void) {
    FOR(i, 1, numNode) if (isCentroid(i)) return i;
    assert(false);
}

void process(void) {
    dfs(1);
    int root = findRoot();
    par[root] = dist[root] = 0;
    dfs(root);

    long long res = 0;
    FOR(i, 1, numNode) if (marked[i]) res += dist[i];
    cout << res << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/