#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   300300
vector<int> adj[MAX];
int numNode, numEdge, numSpecial;
vector<int> special;
int fromStart[MAX], fromEnd[MAX];

void loadGraph(void) {
    scanf("%d%d%d", &numNode, &numEdge, &numSpecial);
    REP(love, numSpecial) {
        int x; scanf("%d", &x);
        special.push_back(x);
    }

    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int start, int dist[]) {
    FOR(i, 1, numNode) dist[i] = -1;

    queue<int> q;
    dist[start] = 0; q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        FORE(it, adj[u]) if (dist[*it] < 0) {
            dist[*it] = dist[u] + 1;
            q.push(*it);
        }
    }
}

void reportUnchange(void) {
    cout << fromStart[numNode] << endl;
    exit(EXIT_SUCCESS);
}

bool compareFromStart(const int &x, const int &y) {
    return fromStart[x] < fromStart[y];
}

void process(void) {
    bfs(1, fromStart);
    bfs(numNode, fromEnd);

    sort(ALL(special), compareFromStart);
    REP(i, numSpecial - 1) if (fromStart[special[i]] == fromStart[special[i + 1]]) reportUnchange();

    int res = 0;
    int maxFromEnd = -1;
    FORD(i, numSpecial - 1, 0) {
        if (maxFromEnd >= 0) {
            maximize(res, fromStart[special[i]] + 1 + maxFromEnd);
            if (res >= fromStart[numNode]) reportUnchange();
        }

        maximize(maxFromEnd, fromEnd[special[i]]);
    }

    cout << min(res, fromStart[numNode]) << endl;
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/