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

const string WIN = "Win";
const string DRAW = "Draw";
const string LOSE = "Lose";

void answer(const string &s) {
    cout << s << endl;
    exit(EXIT_SUCCESS);
}

struct Edge {
    int from, to;

    Edge(int u = 0, int v = 0) {
        from = u; to = v;
    }
};

#define MAX   200200
Edge edges[MAX];
int numNode, numEdge, cnt, start;
int low[MAX], num[MAX], compID[MAX];
vector<int> adj[MAX];
stack<int> st;
int par[MAX][2];

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge); numEdge = 0;
    FOR(i, 1, numNode) {
        int x; scanf("%d", &x);
        REP(aye, x) {
            int j; scanf("%d", &j);
            edges[++numEdge] = Edge(i, j);
            adj[i].push_back(numEdge);
        }
    }
    scanf("%d", &start);
}

void trace(int fin) {
    vector<int> nodes;
    int u = fin, d = 1;
    while (u != start || d != 0) {
        nodes.push_back(u);
        u = par[u][d];
        d ^= 1;
    }
    nodes.push_back(start);
    reverse(ALL(nodes));
    printf("%s\n", WIN.c_str());
    FORE(it, nodes) printf("%d ", *it); printf("\n");
    exit(EXIT_SUCCESS);
}

void bfs(void) {
    memset(par, -1, sizeof par);
    queue<pair<int, int>> q;

    par[start][0] = 0; q.push(make_pair(start, 0));
    while (!q.empty()) {
        int u = q.front().fi;
        int d = q.front().se;
        q.pop();
        if (adj[u].empty() && d == 1) return trace(u);

        FORE(it, adj[u]) {
            int v = edges[*it].to;
            if (par[v][d ^ 1] < 0) {
                par[v][d ^ 1] = u;
                q.push(make_pair(v, d ^ 1));
            }
        }
    }
}

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);

    FORE(it, adj[u]) {
        int v = edges[*it].to;
        if (compID[v] > 0) continue;
        if (num[v] == 0) {
            dfs(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        int compSize = 0;
        int v;
        do {
            v = st.top(); st.pop();
            compID[v] = 1;
            compSize++;
        } while (v != u);
        if (compSize > 1) answer(DRAW);
    }
}

void process(void) {
    bfs();
    dfs(start);
    answer(LOSE);
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/