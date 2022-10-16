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

#define MAX   200200
int numNode, numEdge;
vector<int> adj[MAX], revAdj[MAX];
int dist[MAX];
vector<int> path;

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    int k; scanf("%d", &k);
    REP(love, k) {
        int x; scanf("%d", &x);
        path.push_back(x);
    }
}

void bfs(void) {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[path.back()] = 0; q.push(path.back());

    while (!q.empty()) {
        int u = q.front(); q.pop();
        FORE(it, revAdj[u]) if (dist[*it] < 0) {
            dist[*it] = dist[u] + 1;
            q.push(*it);
        }
    }
}

void process(void) {
    int cntMin = path.size() - 1, cntMax = path.size() - 1;
    REP(i, path.size() - 1) {
        int fr = path[i], to = path[i + 1];
        if (dist[fr] == dist[to] + 1) {
            cntMin--;
            bool only = true;
            FORE(jt, adj[fr]) if (*jt != to && dist[fr] == dist[*jt] + 1) only = false;
            if (only) cntMax--;
        }
    }
    cout << cntMin << " " << cntMax << endl;
}

int main(void) {
    loadGraph();
    bfs();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/