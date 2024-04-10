#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m;
const int sz = 1 << 13;
vector<int> gos[5001];
int rev[5001];

template <class T>
class Dinic {
    struct _edge {
        int x, y;
        T c, rc;
        _edge(int x, int y, T c, T rc) : x(x), y(y), c(c), rc(rc) {}
    };
    int s, e;
    
    int n;
    vector<T> nowFlow;
    vector<vector<int>> edge;
    vector<_edge> es;
    vector<int> dist;
    vector<int> it;
    T inf;
    
    int bfs() {
        for (int i = 0; i < n; ++i) dist[i] = -1;
        
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i : edge[x]) {
                if (i < 0) {
                    i = ~i;
                    if (dist[es[i].x] != -1) continue;
                    if (es[i].rc > 0) {
                        dist[es[i].x] = dist[x] + 1;
                        q.push(es[i].x);
                    }
                }
                else {
                    if (dist[es[i].y] != -1) continue;
                    if (es[i].c > 0) {
                        dist[es[i].y] = dist[x] + 1;
                        q.push(es[i].y);
                    }
                }
            }
        }
        
        return dist[e] != -1;
    }
    
    T dfs(int x, T f) {
        if (x == e) return f;
        for (int &i = it[x]; i < edge[x].size(); ++i) {
            int y; T c;
            if (edge[x][i] < 0) y = es[~edge[x][i]].x, c = es[~edge[x][i]].rc;
            else y = es[edge[x][i]].y, c = es[edge[x][i]].c;
            if (dist[x] + 1 != dist[y]) continue;
            if (c == 0) continue;
            c = dfs(y, min(f, c));
            if (c > 0) {
                if (edge[x][i] < 0) {
                    es[~edge[x][i]].c += c;
                    es[~edge[x][i]].rc -= c;
                    nowFlow[~edge[x][i]] -= c;
                }
                else {
                    es[edge[x][i]].c -= c;
                    es[edge[x][i]].rc += c;
                    nowFlow[edge[x][i]] += c;
                }
                return c;
            }
        }
        return 0;
    }
    
    int matchdfs(int x) {
        if (::n + ::sz <= x && x < ::n + ::sz + ::m) return x - ::n - sz + 1;
        for (int &i = it[x]; i < edge[x].size(); ++i) {
            int y; T c;
            if (edge[x][i] < 0) y = es[~edge[x][i]].x, c = -nowFlow[~edge[x][i]];
            else y = es[edge[x][i]].y, c = nowFlow[edge[x][i]];
            if (c <= 0) continue;
            if (edge[x][i] < 0) ++nowFlow[~edge[x][i]];
            else --nowFlow[edge[x][i]];
            return matchdfs(y);
        }
        return 0;
    }
public:
    void init(int N) {
        n = N;
        inf = 0;
        edge.clear();
        edge.resize(n);
        dist.resize(n);
        it.resize(n);
        nowFlow.clear();
        es.clear();
    }
    
    int addEdge(int x, int y, T C, T RC) {
        inf = max(inf, C + RC);
        int idx = es.size();
        es.emplace_back(x, y, C, RC);
        nowFlow.push_back(0);
        
        edge[x].push_back(idx);
        edge[y].push_back(~idx);
        return idx;
    }
    
    T findMaximumFlow(int source, int sink) {
        s = source;
        e = sink;
        
        T flow = 0;
        while (bfs()) {
            for (int i = 0; i < n; ++i) it[i] = 0;
            while (1) {
                T ret = dfs(s, inf);
                if (ret == 0) break;
                flow += ret;
            }
        }
        return flow;
    }
    
    T getFlow(int idx) {
        return nowFlow[idx];
    }
    
    void findMatching() {
        for (int i = 0; i < n; ++i) it[i] = 0;
        for (int i = 1; i <= ::n; ++i) {
            int r = matchdfs(i);
            if (r) {
                gos[i].push_back(r);
                rev[r] = i;
                --i;
            }
        }
    }
};


struct weapon {
    int type;
    int l, r;
    vector<int> ps;
    void scan() {
        cin >> type;
        if (type == 0) {
            int k, x;
            cin >> k;
            for (int i = 0; i < k; ++i) {
                cin >> x;
                ps.push_back(x);
            }
        }
        else if (type == 1) {
            cin >> l >> r;
        }
        else {
            for (int i = 0; i < 3; ++i) {
                int x;
                cin >> x;
                ps.push_back(x);
            }
        }
    }
} wps[5001];

Dinic<int> dinic;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        wps[i].scan();
    }
    dinic.init(n + sz + m + 10);
    int S = 0, E = n + sz + m + 9;
    for (int i = sz + m - 1; i > 1; --i) {
        dinic.addEdge(n + (i >> 1), n + i, m, 0);
    }
    for (int i = 1; i <= n; ++i) {
        dinic.addEdge(S, i, wps[i].type == 2 ? 2 : 1, 0);
        
        if (wps[i].type == 1) {
            int s = sz + wps[i].l - 1, e = sz + wps[i].r - 1;
            while (s <= e) {
                if ((s & 1) == 1) dinic.addEdge(i, n + (s++), 1, 0);
                if ((e & 1) == 0) dinic.addEdge(i, n + (e--), 1, 0);
                s >>= 1;
                e >>= 1;
            }
        }
        else {
            for (int j : wps[i].ps)
                dinic.addEdge(i, n + sz + j - 1, 1, 0);
        }
    }
    for (int i = 0; i < m; ++i) {
        dinic.addEdge(n + sz + i, E, 1, 0);
    }
    
    int ans = dinic.findMaximumFlow(S, E);
    printf("%d\n", ans);
    dinic.findMatching();
    for (int i = 1; i <= n; ++i) {
        if (wps[i].type != 2) continue;
        if (gos[i].size() != 1) continue;
        for (int j = 0; j < 3; ++j) {
            if (gos[i][0] == wps[i].ps[j]) continue;
            gos[rev[wps[i].ps[j]]].clear();
            rev[wps[i].ps[j]] = i;
            gos[i].push_back(wps[i].ps[j]);
            break;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j : gos[i]) {
            printf("%d %d\n", i, j);
        }
    }
}