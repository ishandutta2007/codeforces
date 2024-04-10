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
    vector<int> lab;
public:
    DisjointSet(int n = 0) {
        if (n > 0) lab.assign(n + 7, -1);
    }

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }

    bool join(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

struct Edge {
    int u, v, c;

    Edge() {
        u = v = c = 0;
    }

    void input(void) {
        scanf("%d%d%d", &u, &v, &c);
    }

    bool operator < (const Edge &e) const {
        return c < e.c;
    }
};

#define MAX   500500
int numNode, numEdge, numQuery;
Edge edges[MAX];
int edgeIndices[MAX];
DisjointSet dsu;

struct Query {
    int index, cost;
    vector<int> edges;

    Query(int i = 0) {
        index = i;
        cost = -1;
        edges.clear();
    }

    void addEdge(int id) {
        edges.push_back(id);
        if (cost < 0) cost = ::edges[id].c;
        assert(cost == ::edges[id].c);
    }
};

vector<Query> queries;
vector<int> queryIndices;
bool answer[MAX];

bool compareEdge(const int &x, const int &y) {
    return edges[x].c < edges[y].c;
}
void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    FOR(i, 1, numEdge) edges[i].input();
    FOR(i, 1, numEdge) edgeIndices[i] = i;
    sort(edgeIndices + 1, edgeIndices + numEdge + 1, compareEdge);
}

bool compareQuery(const int &x, const int &y) {
    return queries[x].cost < queries[y].cost;
}
void loadQuery(void) {
    scanf("%d", &numQuery);
    FOR(i, 1, numQuery) {
        vector<int> ids;
        int tmp; scanf("%d", &tmp);
        REP(love, tmp) {
            int x; scanf("%d", &x);
            ids.push_back(x);
        }
        sort(ALL(ids), compareEdge);
        int l = 0;
        while (l < ids.size()) {
            int r = l;
            while (r < ids.size() && edges[ids[r]].c == edges[ids[l]].c) r++;
            queries.push_back(Query(i));
            FOR(j, l, r - 1) queries.back().addEdge(ids[j]);
            l = r;
        }
    }

    REP(i, queries.size()) queryIndices.push_back(i);
    sort(ALL(queryIndices), compareQuery);

//    FORE(it, queries) {
//        printf("Query for %d cost %d: ", it->index, it->cost);
//        FORE(jt, it->edges) printf("%d ", *jt); printf("\n");
//    }
}

vector<int> adj[MAX];
bool visited[MAX];
vector<int> visitedNodes;

bool add(bool arr[], vector<int> &v, int pos) {
    if (arr[pos]) return false;
    arr[pos] = true;
    v.push_back(pos);
    return true;
}
void cleanup(bool arr[], vector<int> &v) {
    FORE(it, v) arr[*it] = false;
    v.clear();
}

void bfs(int s) {
    assert(add(visited, visitedNodes, s));
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        FORE(it, adj[u]) if (add(visited, visitedNodes, *it)) q.push(*it);
    }
}

bool answerQuery(const Query &query) {
    assert(visitedNodes.empty());

    FORE(it, query.edges) {
        int u = dsu.find(edges[*it].u);
        int v = dsu.find(edges[*it].v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int numComp = 0;
    FORE(it, query.edges) {
        int u = dsu.find(edges[*it].u);
        int v = dsu.find(edges[*it].v);
        if (!visited[u]) {
            bfs(u);
            numComp++;
        }
        if (!visited[v]) {
            bfs(v);
            numComp++;
        }
    }

    bool res = (int)visitedNodes.size() == (int)query.edges.size() + numComp;

    FORE(it, query.edges) {
        int u = dsu.find(edges[*it].u);
        int v = dsu.find(edges[*it].v);
        adj[u].clear();
        adj[v].clear();
    }
    cleanup(visited, visitedNodes);
    return res;
}

void process(void) {
    FOR(i, 1, numQuery) answer[i] = true;

    dsu = DisjointSet(numNode);
    int j = 1;
    FORE(it, queryIndices) {
        while (j <= numEdge && edges[edgeIndices[j]].c < queries[*it].cost) {
            int u = edges[edgeIndices[j]].u;
            int v = edges[edgeIndices[j]].v;
            dsu.join(u, v);
            j++;
        }
        answer[queries[*it].index] &= answerQuery(queries[*it]);
    }

    FOR(i, 1, numQuery) printf("%s\n", answer[i] ? "YES" : "NO");
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    loadGraph();
    loadQuery();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/