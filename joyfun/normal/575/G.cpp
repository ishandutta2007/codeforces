#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
    Edge() {}
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

int n, m;
vector<Edge> g[N];
queue<int> Q;

int d[N], tmp[N], d2[N], p[N], tn, vis[N], vv[N], pw[N];
int zero[N], zn;

int cmp(int a, int b) {
    return d2[a] < d2[b];
}

int out[N], on, out2[N], o2n;

void print(int u) {
    out2[o2n++] = u;
    if (u == n - 1) {
        return;
    }
    print(p[u]);
    out[on++] = pw[u];
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        int u, v, w;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(Edge(v, w));
            g[v].push_back(Edge(u, w));
        }
        for (int i = 0; i < n; i++) d[i] = INF;
        d[0] = 0;
        Q.push(0);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i].v;
                if (d[v] == INF) {
                    d[v] = d[u] + 1;
                    Q.push(v);
                }
            }
        }
        Q.push(n - 1);
        memset(vis, 0, sizeof(vis));
        vis[n - 1] = 1;
        memset(d2, 0, sizeof(d2));
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i].v;
                if (vis[v] || g[u][i].w) continue;
                vis[v] = 1;
                d2[v] = d2[u] + 1;
                p[v] = u;
                pw[v] = g[u][i].w;
                Q.push(v);
            }
        }
        int Min = INF;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                for (int j = 0; j < g[i].size(); j++) {
                    int v = g[i][j].v;
                    Min = min(Min, d[v]);
                }
            }
        }
        memset(vv, 0, sizeof(vv));
        zn = 0;
        for (int i = 0; i < n; i++) if (vis[i]) zero[zn++] = i;
        sort(zero, zero + zn, cmp);
        int Min2 = INF;
        for (int i = 0; i < zn; i++) {
            int u = zero[i];
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j].v;
                if (vis[v] || d[v] != Min) continue;
                Min2 = min(Min2, g[u][j].w);
            }
        }

        for (int i = 0; i < zn; i++) {
            int u = zero[i];
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j].v;
                if (d[v] != Min || g[u][j].w != Min2) continue;
                if (vv[v]) continue;
                Q.push(v);
                p[v] = u;
                pw[v] = g[u][j].w;
                vv[v] = 1;
            }
        }
        while (!Q.empty()) {
            tn = 0;
            int Min = INF;
            while (!Q.empty()) {
                tmp[tn++] = Q.front(); Q.pop();
                int u = tmp[tn - 1];
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i].v;
                    if (d[v] == d[u] - 1) {
                        Min = min(Min, g[u][i].w);
                    }
                }
            }
            for (int i = 0; i < tn; i++) {
                int u = tmp[i];
                for (int j = 0; j < g[u].size(); j++) {
                    int v = g[u][j].v;
                    if (d[v] == d[u] - 1 && Min == g[u][j].w && !vv[v]) {
                        vv[v] = 1;
                        Q.push(v);
                        p[v] = u;
                        pw[v] = g[u][j].w;
                    }
                }
            }
        }
        on = 0;
        o2n = 0;
        print(0);
        int i = 0;
        while (i < on) {
            if (out[i] == 0) i++;
            else break;
        }
        if (i == on) {
            printf("0\n");
        } else {
            for (int j = i; j < on; j++) printf("%d", out[j]);
            printf("\n");
        }
        printf("%d\n", o2n);
        int bo = 0;
        for (int j = 0; j < o2n; j++) {
            if (bo) printf(" ");
            else bo = 1;
            printf("%d", out2[j]);
        }
        printf("\n");
    }
    return 0;
}