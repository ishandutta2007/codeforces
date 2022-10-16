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

#define MAX   100100
vector<int> notAdj[MAX];
int numNode, numEdge;
set<int> notVisited;

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        notAdj[u].push_back(v);
        notAdj[v].push_back(u);
    }
    FOR(i, 1, numNode) if (!notAdj[i].empty()) sort(ALL(notAdj[i]));
}

int newNodes[MAX], newNodeSize;
void bfs(int s) {
    queue<int> q;
    notVisited.erase(s); q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        newNodeSize = 0;
        FORE(it, notVisited) {
            int v = *it;
            if (!binary_search(ALL(notAdj[u]), v)) newNodes[newNodeSize++] = v;
        }
        REP(i, newNodeSize) {
            int v = newNodes[i];
            notVisited.erase(v);
            q.push(v);
        }
    }
}

void process(void) {
    FOR(i, 1, numNode) notVisited.insert(i);
    int numComp = 0;
    while (!notVisited.empty()) {
        int u = *notVisited.begin();
        bfs(u);
        numComp++;
    }

    cout << numComp - 1 << endl;
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/