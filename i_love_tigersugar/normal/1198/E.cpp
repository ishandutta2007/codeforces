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

const long long INF = (long long) 1e18 + 7LL;
struct DinicFlow {
    int numNode, numEdge;
    vector<int> dist, head, work;
    vector<int> point, next;
    vector<long long> flow, capa;

    DinicFlow(int n = 0) {
        numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }

    int addEdge(int u, int v, long long c1, long long c2 = 0) {
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
    long long dfs(int s, int t, long long f) {
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

    long long maxFlow(int s, int t) {
        long long totFlow = 0;
        while (bfs(s, t)) {
            for (int i = 1; i <= numNode; i++) work[i] = head[i];
            while (true) {
                long long d = dfs(s, t, INF);
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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Area {
  int x1, y1, x2, y2;

  Area() {
    x1 = y1 = x2 = y2 = 0;
  }

  Area(int _x1, int _y1, int _x2, int _y2) {
    x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2;
  }
};

#define MAX   1111
vector<int> rows, cols;
bool mark[MAX][MAX];
int n, numArea, numRow, numCol;
Area areas[MAX];

void init(void) {
  cin >> n >> numArea;
  FOR(i, 1, numArea) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    areas[i] = Area(x1, y1, x2, y2);
    rows.push_back(x1);
    rows.push_back(x2 + 1);
    cols.push_back(y1);
    cols.push_back(y2 + 1);
  }

  rows.push_back(1);
  cols.push_back(1);
  rows.push_back(n + 1);
  cols.push_back(n + 1);

  sort(ALL(rows));
  rows.resize(unique(ALL(rows)) - rows.begin());
  sort(ALL(cols));
  cols.resize(unique(ALL(cols)) - cols.begin());

  numRow = rows.size() - 1;
  numCol = cols.size() - 1;

  FOR(i, 1, numArea) {
    int r1 = lower_bound(ALL(rows), areas[i].x1) - rows.begin() + 1;
    int r2 = upper_bound(ALL(rows), areas[i].x2) - rows.begin();
    int c1 = lower_bound(ALL(cols), areas[i].y1) - cols.begin() + 1;
    int c2 = upper_bound(ALL(cols), areas[i].y2) - cols.begin();

    FOR(j, r1, r2) FOR(k, c1, c2) mark[j][k] = true;
  }
}

void process(void) {
  DinicFlow df(numRow + numCol + 2);
  int src = numRow + numCol + 1;
  int snk = numRow + numCol + 2;

  FOR(i, 1, numRow) df.addEdge(src, i, rows[i] - rows[i - 1]);
  FOR(i, 1, numCol) df.addEdge(i + numRow, snk, cols[i] - cols[i - 1]);

  FOR(i, 1, numRow) FOR(j, 1, numCol) if (mark[i][j]) df.addEdge(i, j + numRow, INF);
  cout << df.maxFlow(src, snk) << endl;
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/