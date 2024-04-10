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

const string YES = "Yes";
const string NO = "No";

void answer(const string &s) {
    cout << s << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   100100
int numNode, level;
vector<int> adj[MAX];
int par[MAX], high[MAX];

void loadTree(void) {
    scanf("%d%d", &numNode, &level);
    REP(love, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int bfs(int s) {
    memset(par, 0, sizeof par);
    memset(high, -1, sizeof high);
    par[s] = high[s] = 0;
    queue<int> q; q.push(s);

    int last = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        last = u;
        FORE(it, adj[u]) if (high[*it] < 0) {
            par[*it] = u;
            high[*it] = high[u] + 1;
            q.push(*it);
        }
    }
    return last;
}

int findRoot(void) {
    int leaf = bfs(bfs(1));

    vector<int> path;
    path.push_back(leaf);
    for (; high[leaf] > 0; leaf = par[leaf]) path.push_back(par[leaf]);

    if (path.size() != 2 * level + 1) answer(NO);
    return path[level];
}

void dfs(int u, int par, int dist) {
    if (dist > level) answer(NO);

    int numChild = 0;
    FORE(it, adj[u]) if (*it != par) {
        dfs(*it, u, dist + 1);
        numChild++;
    }

    if (dist == level && numChild > 0) answer(NO);
    if (dist < level && numChild < 3) answer(NO);
}

void process(void) {
    dfs(findRoot(), -1, 0);
    answer(YES);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/