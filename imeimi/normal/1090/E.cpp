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
    
    T& getFlow(int idx) {
        return nowFlow[idx];
    }
};

void pr(int i) {
    char x = i / 8, y = i % 8;
    printf("%c%c", y + 'a', x + '1');
}

const int S = 64, E = 65;
int B[64];
int main() {
    int n;
    cin >> n;
    char in[10];
    Dinic<int> d;
    d.init(66);
    for (int i = 0; i < n; ++i) {
        cin >> in;
        int x = (in[0] - 'a') + 8 * (in[1] - '1');
        B[x] = 1;
        d.addEdge(S, x, 1, 0);
        d.addEdge(i, E, 1, 0);
    }
    vector<pair<pair<int, int>, int>> es;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int nx, ny, nidx, idx = i * 8 + j;
            nx = i + 2, ny = j + 1;
            nidx = nx * 8 + ny;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                es.emplace_back(pair<int, int>(idx, nidx), d.addEdge(idx, nidx, 1, 1));
            }
            nx = i + 2, ny = j - 1;
            nidx = nx * 8 + ny;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                es.emplace_back(pair<int, int>(idx, nidx), d.addEdge(idx, nidx, 1, 1));
            }
            nx = i + 1, ny = j + 2;
            nidx = nx * 8 + ny;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                es.emplace_back(pair<int, int>(idx, nidx), d.addEdge(idx, nidx, 1, 1));
            }
            nx = i + 1, ny = j - 2;
            nidx = nx * 8 + ny;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                es.emplace_back(pair<int, int>(idx, nidx), d.addEdge(idx, nidx, 1, 1));
            }
        }
    }
    if (d.findMaximumFlow(S, E) < n) return 1;
    vector<pair<int, int>> ans;
    while (1) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += B[i];
        if (cnt == n) break;
        for (auto _i : es) {
            int x, y, i = _i.second;
            tie(x, y) = _i.first;
            if (d.getFlow(i) != 0) {
                if (d.getFlow(i) > 0) {
                    if (B[x] == 1 && B[y] == 0) {
                        ans.emplace_back(x, y);
                        B[x] = 0;
                        B[y] = 1;
                        --d.getFlow(i);
                    }
                }
                else {
                    if (B[x] == 0 && B[y] == 1) {
                        ans.emplace_back(y, x);
                        B[x] = 1;
                        B[y] = 0;
                        ++d.getFlow(i);
                    }
                }
            }
        }
    }

    printf("%u\n", ans.size());
    for (auto i : ans) {
        pr(i.first);
        printf("-");
        pr(i.second);
        printf("\n");
    }
    return 0;
}