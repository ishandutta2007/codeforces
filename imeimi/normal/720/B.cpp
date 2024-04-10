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
};

Dinic<int> dinic;
int n, m;

struct _edge {
    int x, c;
    _edge(int x, int c) : x(x), c(c) {}
};

vector<_edge> edge[10001];
int dep[10001];
int par[10001];
int pro[10001];
int col[10001];
int ord;

void dfs(int x, int p) {
    par[x] = p;
    dep[x] = dep[p] + 1;
    for (_edge i : edge[x]) {
        if (i.x == p) continue;
        if (dep[i.x]) {
            if (dep[i.x] < dep[x]) {
                ++ord;
                map<int, int> cs;
                ++cs[i.c];
                for (int j = x; j != i.x; j = par[j]) {
                    ++cs[col[j]];
                    pro[j] = 1;
                }
                for (auto j : cs) {
                    dinic.addEdge(ord, n + j.first, j.second, 0);
                }
                
                dinic.addEdge(0, ord, dep[x] - dep[i.x], 0);
            }
        }
        else col[i.x] = i.c, dfs(i.x, x);
    }
    if (p && pro[x] != 1) {
        ++ord;
        dinic.addEdge(ord, n + col[x], 1, 0);
        dinic.addEdge(0, ord, 1, 0);
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        edge[x].emplace_back(y, c);
        edge[y].emplace_back(x, c);
	}
	ord = 0;
	dinic.init(n + m + 2);
	dfs(1, 0);
	for (int i = 1; i <= m; ++i) dinic.addEdge(n + i, n + m + 1, 1, 0);
	int ans = dinic.findMaximumFlow(0, n + m + 1);
	printf("%d\n", ans);
	return 0;
}