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

#define MAX   400400

struct Edge {
    #define FORWARD 1
    #define BACKWARD -1

    int u, v, dir;
    bool used, isBridge;

    Edge() {
        u = v = dir = 0;
        used = false; isBridge = false;
    }

    void input(void) {
        scanf("%d%d", &u, &v);
    }

    int other(int x) const {
        assert(u == x || v == x);
        return u ^ v ^ x;
    }
    void setDir(int x) {
        assert(u == x || v == x);
        dir = u == x ? FORWARD : BACKWARD;
        used = true;
    }
    int getFrom(void) const {
        assert(dir == FORWARD || dir == BACKWARD);
        return dir == FORWARD ? u : v;
    }

    void printEdge(void) const {
        assert(dir == FORWARD || dir == BACKWARD);
        if (dir == FORWARD) printf("%d %d\n", u, v);
        else printf("%d %d\n", v, u);
    }

};

struct TreeEdge {
    int comp, id, node;
    TreeEdge() {
        comp = id = node = 0;
    }
    TreeEdge(int _comp, int _id, int _node) {
        comp = _comp; id = _id; node = _node;
    }
};

struct Component {
    int root, size;
    vector<TreeEdge> adj;

    Component(int root = 0) {
        this->root = root;
        size = root > 0 ? 1 : 0;
    }
};

Edge edges[MAX];
vector<int> adjGraph[MAX];
int low[MAX], num[MAX], cnt;
int n, m;

Component components[MAX];
int numComp, compID[MAX];
int numCanGo[MAX];

void loadGraph(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) edges[i].input();
    FOR(i, 1, m) {
        adjGraph[edges[i].u].push_back(i);
        adjGraph[edges[i].v].push_back(i);
    }
}

void dfsGraph(int u) {
    low[u] = n + 7;
    num[u] = ++cnt;
    FORE(it, adjGraph[u]) if (!edges[*it].used) {
        int v = edges[*it].other(u);
        edges[*it].setDir(u);
        if (num[v] == 0) {
            dfsGraph(v);
            edges[*it].isBridge = low[v] > num[u];
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }
}
void loadTree(void) {
    dfsGraph(1);
    DisjointSet dsu(n);
    FOR(i, 1, m) if (!edges[i].isBridge) dsu.join(edges[i].u, edges[i].v);

    FOR(i, 1, n) if (dsu.find(i) == i) {
        components[++numComp] = Component(i);
        compID[i] = numComp;
    }
    FOR(i, 1, n) if (dsu.find(i) != i) {
        compID[i] = compID[dsu.find(i)];
        components[compID[i]].size++;
    }

    FOR(i, 1, m) if (edges[i].isBridge) {
        int u = edges[i].u;
        int v = edges[i].v;
        components[compID[u]].adj.push_back(TreeEdge(compID[v], i, u));
        components[compID[v]].adj.push_back(TreeEdge(compID[u], i, v));
    }
}

int dfsTree(int u, int par, int req) {
    int res = components[u].size;
    FORE(it, components[u].adj) {
        int v = it->comp;
        if (v != par) {
            int tmp = dfsTree(v, u, req);
            edges[it->id].setDir(tmp < req ? edges[it->id].other(it->node) : it->node);
            if (tmp >= req) res += tmp;
        }
    }
    return res;
}

int canGo(int u) {
    if (numCanGo[u] >= 0) return numCanGo[u];
    int res = components[u].size;
    FORE(it, components[u].adj) {
        int from = edges[it->id].getFrom();
        if (compID[from] == u) res += canGo(it->comp);
    }
    return numCanGo[u] = res;
}

bool ok(int x) {
    memset(numCanGo, -1, sizeof numCanGo);
    dfsTree(1, -1, x);
    FOR(i, 1, numComp) if (canGo(i) < x) return false;
    return true;
}

int findResult(void) {
    int L = 0;
    int R = n;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return ok(R) ? R : L;
        int M = (L + R) >> 1;
        if (ok(M)) L = M; else R = M - 1;
    }
}

void process(void) {
    int res = findResult();
    printf("%d\n", res);
    assert(ok(res));
    FOR(i, 1, m) edges[i].printEdge();
}

int main(void) {
    loadGraph();
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/