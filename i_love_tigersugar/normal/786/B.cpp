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

#define MAX   100100

const long long INF = (long long)1e18 + 7LL;

#define NODE   1
#define ARRIVE   2
#define DEPART   3
struct State {
    int type, node;

    State(int _type = 0, int _node = 0) {
        type = _type; node = _node;
    }

    bool operator == (const State &s) const {
        return type == s.type && node == s.node;
    }
};

struct TreeNode {
    int departID, arriveID;
    int l, r;

    vector<pair<int, int> > adj;

    TreeNode() {
        departID = arriveID = l = r = 0;
    }

    void addEdge(int v, int c) {
        adj.push_back(make_pair(v, c));
    }
};

int numState, numNode, numEdge, start;
int nodeState[MAX];
State states[10 * MAX];
TreeNode tree[4 * MAX];
vector<int> atSegment[MAX];
vector<pair<int, int> > adj[MAX], toSegment[MAX];

void buildTree(int i, int l, int r) {
    if (l > r) return;

    tree[i].l = l;
    tree[i].r = r;
    tree[i].departID = ++numState;
    states[numState] = State(DEPART, i);
    tree[i].arriveID = ++numState;
    states[numState] = State(ARRIVE, i);

    FOR(j, l, r) atSegment[j].push_back(i);

    if (l == r) {
        nodeState[l] = ++numState;
        states[numState] = State(NODE, l);
        return;
    }

    int m = (l + r) >> 1;
    buildTree(2 * i, l, m);
    buildTree(2 * i + 1, m + 1, r);
}

#define SINGLE   1
#define TO_SEGMENT   2
#define FROM_SEGMENT   3

void addEdge(int i, int l, int r, int u, int v, int node, int cost, int type) {
    if (l > v || r < u || l > r || v < u) return;
    if (u <= l && r <= v) {
        if (type == TO_SEGMENT) toSegment[node].push_back(make_pair(i, cost));
        else tree[i].addEdge(node, cost);
        return;
    }

    int m = (l + r) >> 1;
    addEdge(2 * i, l, m, u, v, node, cost, type);
    addEdge(2 * i + 1, m + 1, r, u, v, node, cost, type);
}

void loadGraph(void) {
    scanf("%d%d%d", &numNode, &numEdge, &start);

    buildTree(1, 1, numNode);

    REP(love, numEdge) {
        int type; scanf("%d", &type);
        if (type == SINGLE) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            adj[u].push_back(make_pair(v, c));
        } else {
            int l, r, v, c; scanf("%d%d%d%d", &v, &l, &r, &c);
            addEdge(1, 1, numNode, l, r, v, c, type);
        }
    }
}

priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
long long *dist;

void update(int node, long long d) {
    if (dist[node] > d) {
        dist[node] = d;
        q.push(make_pair(dist[node], node));
    }
}

void dijkstra(void) {
    dist = new long long[numState + 3];
    REP(i, numState + 1) dist[i] = INF;
    while (!q.empty()) q.pop();

    FOR(i, 1, numState) if (states[i] == State(NODE, start)) update(i, 0);

    while (!q.empty()) {
        int u = q.top().se;
        long long d = q.top().fi;
        q.pop();
        if (d != dist[u]) continue;

        if (states[u].type == NODE) {
            int node = states[u].node;
            FORE(it, adj[node]) update(nodeState[it->fi], dist[u] + it->se);
            FORE(it, toSegment[node]) update(tree[it->fi].arriveID, dist[u] + it->se);
            FORE(it, atSegment[node]) update(tree[*it].departID, dist[u]);
        } else if (states[u].type == ARRIVE) {
            int seg = states[u].node;
            FOR(i, tree[seg].l, tree[seg].r) update(nodeState[i], dist[u]);
        } else if (states[u].type == DEPART) {
            int seg = states[u].node;
            FORE(it, tree[seg].adj) update(nodeState[it->fi], dist[u] + it->se);
        } else assert(false);
    }

    FOR(i, 1, numNode) {
        long long tmp = dist[nodeState[i]];
        cout << (tmp < INF ? tmp : -1) << " ";
    }
    cout << endl;
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    loadGraph();
    dijkstra();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/