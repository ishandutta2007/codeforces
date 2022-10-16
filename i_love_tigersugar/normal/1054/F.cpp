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

    bool havePath(int node) const {
        return dist[node] >= 0;
    }
};

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Triple {
    int a, b, c;
    Triple(int a = 0, int b = 0, int c = 0) {
        this->a = a; this->b = b; this->c = c;
    }
};

#define MAX   1010
const int INF = (int)1e9 + 7;

pair<int, int> points[MAX];
map<int, vector<int>> atX, atY;
int numPoint;
int rightPoint[MAX], upPoint[MAX], rightNode[MAX], upNode[MAX];

void init(void) {
    scanf("%d", &numPoint);
    FOR(i, 1, numPoint) scanf("%d%d", &points[i].fi, &points[i].se);
}

int pointID(int x, int y) {
    int id = lower_bound(points + 1, points + numPoint + 1, make_pair(x, y)) - points;
    assert(id <= numPoint && points[id].fi == x && points[id].se == y);
    return id;
}

void prepare(void) {
    sort(points + 1, points + numPoint + 1);

    FOR(i, 1, numPoint) {
        int x = points[i].fi, y = points[i].se;
        atX[x].push_back(y);
        atY[y].push_back(x);
    }

    memset(upPoint, -1, sizeof upPoint);
    FORE(it, atX) {
        int x = it->fi;
        vector<int> &y = it->se;
        sort(ALL(y));
        REP(j, (int)y.size() - 1) {
            int y1 = y[j], y2 = y[j + 1];
            int id1 = pointID(x, y1);
            int id2 = pointID(x, y2);
            upPoint[id1] = id2;
        }
    }

    memset(rightPoint, -1, sizeof rightPoint);
    FORE(jt, atY) {
        int y = jt->fi;
        vector<int> &x = jt->se;
        sort(ALL(x));
        REP(i, (int)x.size() - 1) {
            int x1 = x[i], x2 = x[i + 1];
            int id1 = pointID(x1, y);
            int id2 = pointID(x2, y);
            rightPoint[id1] = id2;
        }
    }
}

bool intersect(int rightID, int upID) {
    int x = points[upID].fi, y1 = points[upID].se, y2 = points[upPoint[upID]].se;
    int y = points[rightID].se, x1 = points[rightID].fi, x2 = points[rightPoint[rightID]].fi;
    return x1 < x && x < x2 && y1 < y && y < y2;
}

void process(void) {
    int numNode = 0;
    FOR(i, 1, numPoint) if (upPoint[i] > 0) upNode[i] = ++numNode;
    FOR(i, 1, numPoint) if (rightPoint[i] > 0) rightNode[i] = ++numNode;

    DinicFlow df(numNode + 2);
    int src = numNode + 1, snk = numNode + 2;
    FOR(i, 1, numPoint) if (upPoint[i] > 0) df.addEdge(src, upNode[i], 1);
    FOR(i, 1, numPoint) if (rightPoint[i] > 0) df.addEdge(rightNode[i], snk, 1);

    FOR(i, 1, numPoint) if (upPoint[i] > 0) FOR(j, 1, numPoint) if (rightPoint[j] > 0)
        if (intersect(j, i)) df.addEdge(upNode[i], rightNode[j], INF);

    df.maxFlow(src, snk);
    vector<Triple> segX;
    FORE(it, atX) {
        int x = it->fi;
        vector<int> &y = it->se;
        vector<bool> isCut;
        REP(j, (int)y.size() - 1) {
            int id = pointID(x, y[j]);
            assert(upNode[id] > 0);
            isCut.push_back(!df.havePath(upNode[id]));
        }
        vector<int> sta, fin;
        REP(j, y.size()) {
            if (j == 0 || isCut[j - 1]) sta.push_back(y[j]);
            if (j == (int)y.size() - 1 || isCut[j]) fin.push_back(y[j]);
        }
        assert(sta.size() == fin.size());
        REP(t, sta.size()) segX.push_back(Triple(x, sta[t], fin[t]));
    }

    vector<Triple> segY;
    FORE(jt, atY) {
        int y = jt->fi;
        vector<int> &x = jt->se;
        vector<bool> isCut;
        REP(i, (int)x.size() - 1) {
            int id = pointID(x[i], y);
            assert(rightNode[id] > 0);
            isCut.push_back(df.havePath(rightNode[id]));
        }
        vector<int> sta, fin;
        REP(i, x.size()) {
            if (i == 0 || isCut[i - 1]) sta.push_back(x[i]);
            if (i == (int)x.size() - 1 || isCut[i]) fin.push_back(x[i]);
        }
        assert(sta.size() == fin.size());
        REP(t, sta.size()) segY.push_back(Triple(y, sta[t], fin[t]));
    }

    printf("%d\n", (int)segY.size());
    FORE(it, segY) printf("%d %d %d %d\n", it->b, it->a, it->c, it->a);
    printf("%d\n", (int)segX.size());
    FORE(it, segX) printf("%d %d %d %d\n", it->a, it->b, it->a, it->c);
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/