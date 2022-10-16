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
vector<int> adj[MAX], revAdj[MAX];
int numNode, numEdge, numComp, cnt;
int low[MAX], num[MAX], compID[MAX];
stack<int> st;
bool vst[MAX], revVst[MAX];

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
}

void tarjan(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);

    FORE(it, adj[u]) if (compID[*it] == 0) {
        int v = *it;
        if (num[v] == 0) {
            tarjan(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        numComp++;
        while (true) {
            int v = st.top(); st.pop();
            compID[v] = numComp;
            if (u == v) break;
        }
    }
}

void bfs(int s, vector<int> adj[], bool vst[]) {
    queue<int> q;
    vst[s] = true; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        FORE(it, adj[u]) if (!vst[*it]) {
            vst[*it] = true;
            q.push(*it);
        }
    }
}

void process(void) {
    FOR(i, 1, numNode) if (num[i] == 0) tarjan(i);
    if (numComp < numNode) {
        cout << -1 << endl;
        exit(EXIT_SUCCESS);
    }

    string res;
    FOR(i, 1, numNode) {
        if (!vst[i] && !revVst[i]) res.push_back('A');
        else res.push_back('E');
        bfs(i, adj, vst);
        bfs(i, revAdj, revVst);
    }

    int numA = 0;
    FORE(it, res) if (*it == 'A') numA++;
    cout << numA << endl << res << endl;
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/