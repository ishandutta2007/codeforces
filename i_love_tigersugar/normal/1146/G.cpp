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

struct DinicFlow {
    static const int INF = (int) 1e9 + 7;
    int numNode, numEdge;
    vector<int> dist, head, work;
    vector<int> point, flow, capa, next;

    DinicFlow(int n = 0) {
        numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }

    int addEdge(int u, int v, int c1, int c2 = 0) {
        int ret = numEdge;
        point.push_back(v); capa.push_back(c1); flow.push_back(0); next.push_back(head[u]); head[u] = numEdge++;
        point.push_back(u); capa.push_back(c2); flow.push_back(0); next.push_back(head[v]); head[v] = numEdge++;
        return ret;
    }

    bool bfs(int s, int t) {
        queue<int> q;
        for (int i = 1; i <= numNode; i++) dist[i] = -1;
        dist[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] < 0) {
                dist[point[i]] = dist[u] + 1;
                q.push(point[i]);
            }
        }
        return dist[t] >= 0;
    }
    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] == dist[s] + 1) {
            int d = dfs(point[i], t, min(f, capa[i] - flow[i]));
            if (d > 0) {
                flow[i] += d;
                flow[i ^ 1] -= d;
                return d;
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int totFlow = 0;
        while (bfs(s, t)) {
            for (int i = 1; i <= numNode; i++) work[i] = head[i];
            while (true) {
                int d = dfs(s, t, INF);
                if (d == 0) break;
                totFlow += d;
            }
        }
        return totFlow;
    }

    int getFlow(int id) const {
        return flow[id];
    }
};

struct Fine {
    int l, r, limit, cost;

    Fine() {
        l = r = limit = cost = 0;
    }

    void input(void) {
        scanf("%d%d%d%d", &l, &r, &limit, &cost);
    }
};

#define SQR(x) ((x) * (x))
#define MAX   55
const int INF = (int)1e8 + 7;

Fine fines[MAX];
int numHome, maxHigh, numFine;
int recID[MAX][MAX], bonusID[MAX];

void init(void) {
    scanf("%d%d%d", &numHome, &maxHigh, &numFine);
    FOR(i, 1, numFine) fines[i].input();
}

void process(void) {
    int numNode = 0;
    FOR(i, 1, numHome) FOR(j, 1, maxHigh) recID[i][j] = ++numNode;
    FOR(i, 1, numFine) bonusID[i] = ++numNode;

    DinicFlow df(numNode + 2);
    int src = numNode + 1;
    int snk = numNode + 2;

    FOR(i, 1, numHome) FOR(j, 1, maxHigh) df.addEdge(src, recID[i][j], SQR(j) - SQR(j - 1));
    FOR(i, 1, numFine) {
        df.addEdge(bonusID[i], snk, fines[i].cost);
        FOR(j, fines[i].l, fines[i].r) FOR(k, fines[i].limit + 1, maxHigh)
            df.addEdge(recID[j][k], bonusID[i], INF);
    }

    cout << numHome * SQR(maxHigh) - df.maxFlow(src, snk) << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/