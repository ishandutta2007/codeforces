#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int N = 3005;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[N];
int d[N][N], vis[N];
queue<int> Q;

void bfs(int u, int* d) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) d[i] = INF;
    Q.push(u);
    d[u] = 0; vis[u] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (vis[v]) continue;
            vis[v] = 1;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
}

set<pair<int, int> > s[N], t[N];
int aa, bb, cc, dd;

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) bfs(i, d[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) d[i][j] = -INF;
            if (i == j) continue;
            s[i].insert(make_pair(d[i][j], j));
            if (s[i].size() > 3) s[i].erase(s[i].begin());
            t[j].insert(make_pair(d[i][j], i));
            if (t[j].size() > 3) t[j].erase(t[j].begin());
        }
    }
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int tmp = d[i][j];
            if (tmp == -INF) continue;
            set<pair<int, int> >::iterator t1 = t[i].end(); t1--;
            if (t1->second == j) t1--;
            set<pair<int, int> >::iterator t2 = t1; t2--;
            if (t2->second == j) t2--;
            set<pair<int, int> >::iterator s1 = s[j].end(); s1--;
            if (s1->second == i) s1--;
            set<pair<int, int> >::iterator s2 = s1; s2--;
            if (s2->second == i) s2--;
            if (t1->second != s1->second) {
                int tt = tmp + t1->first + s1->first;
                if (Max < tt) {
                    Max = tt;
                    aa = t1->second;
                    bb = i; cc = j;
                    dd = s1->second;
                }
            } else {
                int tt = tmp + t1->first + s2->first;
                if (Max < tt) {
                    Max = tt;
                    aa = t1->second;
                    bb = i; cc = j;
                    dd = s2->second;
                }
                tt = tmp + t2->first + s1->first;
                if (Max < tt) {
                    Max = tt;
                    aa = t2->second;
                    bb = i; cc = j;
                    dd = s1->second;
                }
            }
        }
    }
    printf("%d %d %d %d\n", aa, bb, cc, dd);
    return 0;
}