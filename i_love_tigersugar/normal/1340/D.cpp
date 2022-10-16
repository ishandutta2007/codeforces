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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   300300
int numNode, maxDegree;
vector<int> adj[MAX];
vector<pair<int, int>> events;

void loadTree(void) {
    scanf("%d", &numNode);
    REP(love, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (numNode == 1) {
        cout << "1" << endl;
        cout << "1 0" << endl;
        exit(EXIT_SUCCESS);
    }

    FOR(i, 1, numNode) maximize(maxDegree, (int)adj[i].size());
}

void dfs(int u, int par, int &value) {
    int numChild = par < 0 ? adj[u].size() : adj[u].size() - 1;

    if (numChild == 0) {
        value--;
        return;
    }

    int startValue = value;
    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        if (value == maxDegree) {
            value = maxDegree - 1 - numChild;
        }

        events.push_back(make_pair(u, value));
        events.push_back(make_pair(v, ++value));
        dfs(v, u, value);
        events.push_back(make_pair(v, value));
        events.push_back(make_pair(u, ++value));
    }

    value = startValue - 1;
}

void process(void) {
    events.push_back(make_pair(1, 0));
    int value = 0;
    dfs(1, -1, value);

    vector<pair<int, int>> newEvents;
    FORE(it, events) if (newEvents.empty() || *it != newEvents.back()) newEvents.push_back(*it);

    printf("%d\n", (int)newEvents.size());
    FORE(it, newEvents) printf("%d %d\n", it->fi, it->se);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/