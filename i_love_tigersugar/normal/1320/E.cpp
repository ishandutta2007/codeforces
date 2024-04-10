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

struct Virus {
    int pos, speed;

    Virus() {
        pos = speed = 0;
    }
};

struct Event {
    int time, index, pos;

    Event(int _time = 0, int _index = 0, int _pos = 0) {
        time = _time; index = _index; pos = _pos;
    }

    bool operator < (const Event &e) const {
        return time == e.time ? index > e.index : time > e.time;
    }
};

#define MAX   200200
#define LOG   18

int numNode, numQuery, cnt;
vector<int> treeAdj[MAX];
int high[MAX], par[MAX][LOG + 1], sta[MAX], fin[MAX];

int numVirus, numCity;
Virus viruses[MAX];
int cities[MAX];
int nodes[MAX * 3], numQueryNode;
vector<int> queryAdj[MAX];
int occupy[MAX];

void loadTree(void) {
    scanf("%d", &numNode);
    REP(love, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        treeAdj[u].push_back(v);
        treeAdj[v].push_back(u);
    }
}

void prepareDFS(int u) {
    sta[u] = ++cnt;
    FORE(it, treeAdj[u]) if (*it != par[u][0]) {
        int v = *it;
        high[v] = high[u] + 1;
        par[v][0] = u;
        prepareDFS(v);
    }
    fin[u] = cnt;
}

void setupLCA(void) {
    high[0] = -1;
    prepareDFS(1);
    FOR(j, 1, LOG) FOR(i, 1, numNode) par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if (high[u] < high[v]) return lca(v, u);
    FORD(i, LOG, 0) if (high[par[u][i]] >= high[v]) u = par[u][i];
    if (u == v) return u;
    FORD(i, LOG, 0) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

int distance(int u, int v) {
    return high[u] + high[v] - 2 * high[lca(u, v)];
}

bool isParent(int parent, int child) {
    return sta[parent] <= sta[child] && sta[child] <= fin[parent];
}

void readQuery(void) {
    scanf("%d%d", &numVirus, &numCity);
    FOR(i, 1, numVirus) scanf("%d%d", &viruses[i].pos, &viruses[i].speed);
    FOR(i, 1, numCity) scanf("%d", &cities[i]);
}

bool compareOrder(const int &x, const int &y) {
    return sta[x] < sta[y];
}

void buildQueryTree(void) {
    numQueryNode = 0;
    FOR(i, 1, numVirus) nodes[++numQueryNode] = viruses[i].pos;
    FOR(i, 1, numCity) nodes[++numQueryNode] = cities[i];
    sort(nodes + 1, nodes + numQueryNode + 1, compareOrder);
    numQueryNode = unique(nodes + 1, nodes + numQueryNode + 1) - nodes - 1;

    FOR(i, 1, numQueryNode - 1) nodes[++numQueryNode] = lca(nodes[i], nodes[i + 1]);
    sort(nodes + 1, nodes + numQueryNode + 1, compareOrder);
    numQueryNode = unique(nodes + 1, nodes + numQueryNode + 1) - nodes - 1;

    FOR(i, 1, numQueryNode) queryAdj[nodes[i]].clear();
    stack<int> st;
    st.push(nodes[1]);
    FOR(i, 2, numQueryNode) {
        while (!st.empty() && !isParent(st.top(), nodes[i])) st.pop();
        assert(!st.empty());
        int par = st.top();
        queryAdj[par].push_back(nodes[i]);
        queryAdj[nodes[i]].push_back(par);
        st.push(nodes[i]);
    }
}

#define CEIL(a, b) (((a) + (b) - 1) / (b))
void infect(void) {
    FOR(i, 1, numQueryNode) occupy[nodes[i]] = -1;
    priority_queue<Event> events;
    FOR(i, 1, numVirus) events.push(Event(0, i, viruses[i].pos));

    while (!events.empty()) {
        Event e = events.top(); events.pop();
        if (occupy[e.pos] > 0) continue;
        occupy[e.pos] = e.index;
        FORE(it, queryAdj[e.pos]) if (occupy[*it] < 0)
            events.push(Event(CEIL(distance(viruses[e.index].pos, *it), viruses[e.index].speed), e.index, *it));
    }

    FOR(i, 1, numCity) printf("%d ", occupy[cities[i]]); printf("\n");
}

int main(void) {
    loadTree();
    setupLCA();
    scanf("%d", &numQuery);
    REP(love, numQuery) {
        readQuery();
        buildQueryTree();
        infect();
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/