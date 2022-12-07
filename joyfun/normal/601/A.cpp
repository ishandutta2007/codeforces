#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 405;
const int INF = 0x3f3f3f3f;
int n, m;
int G[N][N];
vector<int> g[N];

queue<int> Q;
bool inq[N];
int d[N];

int spfa() {
    inq[1] = 1;
    Q.push(1);
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[1] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = false;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                if (!inq[v]) {
                    inq[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return d[n];
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        for (int j = 1; j <= n; j++)
            if (G[i][j]) g[i].push_back(j);
    }
    int ans = spfa();
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        for (int j = 1; j <= n; j++)
            if (!G[i][j]) g[i].push_back(j);
    }
    ans = max(ans, spfa());
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}