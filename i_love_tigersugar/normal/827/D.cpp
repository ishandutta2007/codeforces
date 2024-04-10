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
	vector<int> label; //label[x] stores the root of x if x is not root, otherwise it stores -(size of x's set).
	public:
	DisjointSet(){}
	DisjointSet(int n) {
		label.assign(n+7,-1); //label should contains at least n+1 elements, as x is 1-indexed.
		//At first, each node is a seperate set of size 1.
	}
	int find(int x) { //find the root of set which contains x.
		if (label[x]<0) return (x); //x is root iff label[x] is negative.
		label[x]=find(label[x]);
		return (label[x]); //find the root of x by recursion.
	}
	bool join(int a,int b) { // join the sets which contains a and b. Return false iff a and b are already in the same set.
		int x=find(a);
		int y=find(b);
		if (x==y) return (false); //A set contains both a and b.
		if (label[x]>label[y]) swap(x,y); //label[x]>label[y] means size(x)<size(y).
		//We speed up the disjoint set by joinning the smaller set to the bigger set
		label[x]+=label[y];
		label[y]=x; //Update the label of x and y.
		return (true);
	}
	int getSize(int x) { //return the size of set which contains x.
		return (-label[find(x)]);
	}
};

class FenwickTree {
private:
    vector<int> v;
    int n;

    void update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int l, int r, int d) {
        update(l, d);
        if (r < n) update(r + 1, -d);
    }

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }
};

const int INF = (int)1e9 + 7;

struct Edge {
    int u, v, c, id, answer;
    bool inTree;

    Edge() {
        u = v = c = id = 0; inTree = false; answer = INF;
    }

    void input(int i) {
        id = i;
        scanf("%d%d%d", &u, &v, &c);
    }

    int other(int x) const {
        assert(u == x || v == x);
        return u ^ v ^ x;
    }
};

#define MAX   200200
#define LOG   18

Edge edges[MAX];
vector<int> adj[MAX];
int n, m, cnt;
int parEdgeID[MAX];
int par[MAX][LOG + 1], maxEdge[MAX][LOG + 1];
int high[MAX], sta[MAX], fin[MAX];
FenwickTree numRemEdge;

void loadGraph(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) edges[i].input(i);
    FOR(i, 1, m) {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }
}

bool compEdge(const int &x, const int &y) {
    return edges[x].c < edges[y].c;
}

void buildTree(void) {
    vector<int> indices;
    FOR(i, 1, m) indices.push_back(i);
    sort(ALL(indices), compEdge);

    DisjointSet dsu(n);
    FORE(it, indices) edges[*it].inTree = dsu.join(edges[*it].u, edges[*it].v);
}

void dfs(int u) {
    sta[u] = ++cnt;
    FORE(it, adj[u]) if (edges[*it].inTree) {
        int v = edges[*it].other(u);
        if (v == par[u][0]) continue;
        high[v] = high[u] + 1;
        parEdgeID[v] = *it;
        par[v][0] = u;
        maxEdge[v][0] = edges[*it].c;
        dfs(v);
    }
    fin[u] = cnt;
}

void setupLCA(void) {
    high[0] = -1;
    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[par[i][j - 1]][j - 1]);
    }
}

pair<int, int> calcLCA(int u, int v) {
    if (high[u] < high[v]) return calcLCA(v, u);
    int res = -1;

    FORD(i, LOG, 0) if (high[par[u][i]] >= high[v]) {
        maximize(res, maxEdge[u][i]);
        u = par[u][i];
    }
    if (u == v) return make_pair(u, res);

    FORD(i, LOG, 0) if (par[u][i] != par[v][i]) {
        maximize(res, maxEdge[u][i]);
        maximize(res, maxEdge[v][i]);
        u = par[u][i];
        v = par[v][i];
    }

    maximize(res, maxEdge[u][0]);
    maximize(res, maxEdge[v][0]);
    return make_pair(par[u][0], res);
}
int LCA(int u, int v) {
    return calcLCA(u, v).fi;
}
int getMaxEdge(int u, int v) {
    return calcLCA(u, v).se;
}

int getNextEdge(int u) {
    int tmp = numRemEdge.get(sta[u]);
    if (tmp == 0) return 0;

    FORD(i, LOG, 0) if (par[u][i] > 0) {
        int v = par[u][i];
        if (tmp == numRemEdge.get(sta[v])) u = v;
    }

    return u;
}

void process(void) {
    numRemEdge = FenwickTree(n);
    FOR(i, 2, n) numRemEdge.update(sta[i], fin[i], 1);
    FOR(i, 1, n) assert(numRemEdge.get(sta[i]) == high[i]);

    vector<int> indices;
    FOR(i, 1, m) indices.push_back(i);
    sort(ALL(indices), compEdge);

    FORE(it, indices) if (!edges[*it].inTree) {
        int u = edges[*it].u;
        int v = edges[*it].v;
        edges[*it].answer = getMaxEdge(u, v) - 1;

        int w = LCA(u, v);
        for (u = getNextEdge(u); high[u] > high[w]; u = getNextEdge(u)) {
            int id = parEdgeID[u];
            assert(edges[id].answer >= INF);
            edges[id].answer = edges[*it].c - 1;
            numRemEdge.update(sta[u], fin[u], -1);
        }
        for (v = getNextEdge(v); high[v] > high[w]; v = getNextEdge(v)) {
            int id = parEdgeID[v];
            assert(edges[id].answer >= INF);
            edges[id].answer = edges[*it].c - 1;
            numRemEdge.update(sta[v], fin[v], -1);
        }
    }

    FOR(i, 1, m) printf("%d ", edges[i].answer < INF ? edges[i].answer : -1); printf("\n");
}

int main(void) {
    loadGraph();
    buildTree();
    setupLCA();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/