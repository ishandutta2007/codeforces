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

#define MAX   300300

int numNode, numEdge, numQuery, numTree;
vector<int> adj[MAX];
vector<int> nodes[MAX];
bool isRoot[MAX];
int treeID[MAX], treeSize[MAX];
int maxDistIn[MAX], maxDistOut[MAX], maxDist[MAX], maxDistTree[MAX];
vector<int> cntMaxDist[MAX];
vector<long long> sumMaxDist[MAX];

map<pair<int, int>, double> cache;

void loadGraph(void) {
    scanf("%d%d%d", &numNode, &numEdge, &numQuery);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int par) {
    treeID[u] = numTree;
    treeSize[numTree]++;
    nodes[numTree].push_back(u);
    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        dfs(v, u);
        maximize(maxDistIn[u], maxDistIn[v] + 1);
    }
}

void update(pair<int, int> &a, pair<int, int> &b, const pair<int, int> &c) {
    if (c > a) {
        b = a; a = c;
    } else maximize(b, c);
}

void calcMaxDist(int u, int par) {
    pair<int, int> maxBranch = make_pair(-1, -1), secondMaxBranch = make_pair(-1, -1);

    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        update(maxBranch, secondMaxBranch, make_pair(maxDistIn[v], v));
    }

    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        maxDistOut[v] = maxDistOut[u] >= 0 ? maxDistOut[u] + 1 : -1;
        int tmp = v == maxBranch.se ? secondMaxBranch.fi : maxBranch.fi;
        if (tmp >= 0) maximize(maxDistOut[v], tmp + 2);
    }

    FORE(it, adj[u]) if (*it != par) calcMaxDist(*it, u);
}

void prepare(void) {
    memset(treeID, -1, sizeof treeID);
    FOR(i, 1, numNode) if (treeID[i] < 0) {
        isRoot[i] = true;
        numTree++;
        dfs(i, -1);
    }

    FOR(i, 1, numNode) if (isRoot[i]) calcMaxDist(i, -1);

    FOR(i, 1, numTree) {
        cntMaxDist[i].assign(treeSize[i] + 1, 0);
        sumMaxDist[i].assign(treeSize[i] + 1, 0);
    }

    FOR(i, 1, numNode) {
        maxDist[i] = max(maxDistIn[i], maxDistOut[i]);
        cntMaxDist[treeID[i]][maxDist[i]]++;
        sumMaxDist[treeID[i]][maxDist[i]] += maxDist[i];
        maximize(maxDistTree[treeID[i]], maxDist[i]);
    }

    FOR(i, 1, numTree) FORD(j, treeSize[i] - 1, 0) {
        cntMaxDist[i][j] += cntMaxDist[i][j + 1];
        sumMaxDist[i][j] += sumMaxDist[i][j + 1];
    }

//    FOR(i, 1, numNode) printf("Max dist of %d is %d\n", i, maxDist[i]);
//    FOR(i, 1, numTree) {
//        printf("Tree %d has %d nodes. Maxdist = %d\n", i, treeSize[i], maxDistTree[i]);
//        FORE(it, nodes[i]) printf("%d ", *it); printf("\n");
//    }
}

int countGreater(const vector<int> &v, int x) {
    if (x >= v.size()) return 0;
    if (x < 0) return v[0];
    return v[x];
}

long long getSumGreater(const vector<long long> &v, int x) {
    if (x >= v.size()) return 0;
    if (x < 0) return v[0];
    return v[x];
}

double calcAnswer(int u, int v) {
    if (u == v) return -1;
    if (treeSize[u] > treeSize[v]) swap(u, v);

    int maxBoth = max(maxDistTree[u], maxDistTree[v]);

    double res = 0.0;
    FORE(it, nodes[u]) {
        int x = maxDist[*it];
        int numGreater = countGreater(cntMaxDist[v], maxBoth - x);
        long long sumGreater = getSumGreater(sumMaxDist[v], maxBoth - x);

        res += (sumGreater + 1.0 * numGreater * (x + 1)) / treeSize[v];
        res += maxBoth * (1 - 1.0 * numGreater / treeSize[v]);
    }

    return res / treeSize[u];
}

double query(int u, int v) {
    u = treeID[u]; v = treeID[v];
    if (u > v) swap(u, v);

    if (cache.find(make_pair(u, v)) == cache.end())
        cache[make_pair(u, v)] = calcAnswer(u, v);
    return cache[make_pair(u, v)];
}

void process(void) {
    REP(love, numQuery) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%.10lf\n", query(u, v));
    }
}

int main(void) {
    loadGraph();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/