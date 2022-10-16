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

struct GoToNextTest {
};

void noAnswer(void) {
    printf("-1\n");
    throw GoToNextTest();
}

#define MAX   1111111

int n, next[MAX];
int numNode;
int child[MAX][2];
vector<int> adj[MAX]; // node << 1 ^ cost

int cnt, numComp, low[MAX], num[MAX], compID[MAX], compSize[MAX];
stack<int> st;
vector<int> bigRevAdj[MAX];

int res[MAX], usedValue;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &next[i]);
}

int buildSegmentEdge(int l, int r) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    int id = ++numNode;
    adj[id].clear();
    child[id][0] = buildSegmentEdge(l, m);
    child[id][1] = buildSegmentEdge(m + 1, r);
    REP(j, 2) adj[child[id][j]].push_back(id << 1);
    return id;
}

void buildMaxEdge(int i, int l, int r, int u, int v, int maxID) {
    if (l > v || r < u || l > r || v < u) return;
    if (u <= l && r <= v) {
        adj[i].push_back((maxID << 1) ^ 1);
        return;
    }
    int m = (l + r) >> 1;
    buildMaxEdge(child[i][0], l, m, u, v, maxID);
    buildMaxEdge(child[i][1], m + 1, r, u, v, maxID);
}

void buildGraph(void) {
    numNode = n;
    FOR(i, 1, n) adj[i].clear();
    buildSegmentEdge(1, n);

    FOR(i, 1, n) if (next[i] > 0) {
        int j = next[i];
        if (i + 1 < j) buildMaxEdge(n + 1, 1, n, i + 1, j - 1, i);
        if (j < n + 1) adj[i].push_back((j << 1) ^ 1);
    }
}

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);

    FORE(it, adj[u]) {
        int v = *it >> 1;
        if (compID[v] > 0) continue;
        if (num[v] == 0) {
            dfs(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        compSize[++numComp] = 0;
        while (true) {
            int v = st.top(); st.pop();
            compID[v] = numComp;
            if (v <= n) {
                if (++compSize[compID[v]] > 1) noAnswer();
            }
            if (u == v) break;
        }
    }
}

//int getMinLabel(int x) {
//    if (minLabel[x] >= 0) return minLabel[x];
//    minLabel[x] = 1;
//    FORE(it, bigRevAdj[x]) {
//        int y = *it >> 1, cost = *it & 1;
//        maximize(minLabel[x], getMinLabel(y) + cost);
//    }
//    return minLabel[x];
//}

int getResult(int x) {
    if (res[x] >= 0) return res[x];
    FORE(it, bigRevAdj[x]) getResult(*it >> 1);
    return res[x] = compSize[x] == 0 ? 0 : ++usedValue;
}

void process(void) {
    FOR(i, 1, numNode) low[i] = num[i] = compID[i] = 0;
    cnt = numComp = 0;
    while (!st.empty()) st.pop();

    FOR(i, 1, numNode) if (num[i] == 0) dfs(i);
    FOR(i, 1, numComp) {
        bigRevAdj[i].clear();
        res[i] = -1;
    }
    FOR(i, 1, numNode) FORE(jt, adj[i]) {
        int j = *jt >> 1, cost = *jt & 1;
        if (cost > 0 && compID[i] == compID[j]) noAnswer();
        if (compID[i] != compID[j]) bigRevAdj[compID[j]].push_back((compID[i] << 1) ^ cost);
    }

    usedValue = 0;
    FOR(i, 1, n) if (getResult(compID[i]) > n) noAnswer();
    FOR(i, 1, n) {
        int j = getResult(compID[i]);
        assert(1 <= j && j <= n);
        printf("%d ", j);
    }
    printf("\n");
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) {
        try {
            init();
            buildGraph();
            process();
        } catch (GoToNextTest e) {
        }
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/