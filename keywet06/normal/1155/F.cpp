#include <bits/stdc++.h>

const int N = 210;

struct node {
    int v, next, use;
} Edge[N << 2];

bool Flag;
bool Bri[N];

int ip, sol, Cnt, n, m, i, s, ans = -1, j;
int Low[N], Dfn[N], Vis[N], Head[N], Pre[N], Viss[N], u[N], v[N], p[N], t[N];

void Init() {
    memset(Head, -1, sizeof(Head));
    memset(Vis, false, sizeof(Vis));
    memset(Bri, false, sizeof(Bri));
    Cnt = sol = ip = 0;
}

void AddEdge(int u, int v) {
    Edge[ip].v = v;
    Edge[ip].use = 0;
    Edge[ip].next = Head[u];
    Head[u] = ip++;
}

void Tarjan(int u) {
    Vis[u] = 1;
    Dfn[u] = Low[u] = Cnt++;
    for (int i = Head[u]; i != -1; i = Edge[i].next) {
        if (!Edge[i].use) {
            Edge[i].use = Edge[i ^ 1].use = 1;
            int v = Edge[i].v;
            if (!Vis[v]) {
                Pre[v] = u, Tarjan(v), Low[u] = std::min(Low[u], Low[v]);
                if (Dfn[u] < Low[v]) ++sol, Flag = 0;
            } else if (Vis[v] == 1) {
                Low[u] = std::min(Low[u], Dfn[v]);
            }
        }
    }
    Vis[u] = 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (i = 1; i <= m; ++i) std::cin >> u[i] >> v[i];
    for (i = 1; i <= m; ++i) p[i] = i;
    for (int jo = 1; jo <= 2000; ++jo) {
        for (i = 1; i <= 100; ++i) {
            int x = rand() % m + 1, y = rand() % m + 1;
            std::swap(p[x], p[y]);
        }
        memset(Viss, 0, sizeof(Viss));
        for (i = 1; i <= m; ++i) {
            Init();
            Viss[i] = 1;
            for (j = 1; j <= m; ++j) {
                if (Viss[j] == 0) {
                    AddEdge(u[p[j]], v[p[j]]);
                    AddEdge(v[p[j]], u[p[j]]);
                }
            }
            Flag = 1;
            Tarjan(1);
            for (j = 1; j <= n; ++j) {
                if (Vis[j] == 0) Flag = 0;
            }
            if (!Flag) Viss[i] = 0;
        }
        s = 0;
        for (i = 1; i <= m; ++i) s += Viss[i] == 1;
        if (ans < s) {
            ans = s;
            int y = 0;
            for (i = 1; i <= m; ++i) {
                if (Viss[i] == 0) t[++y] = p[i];
            }
        }
    }
    std::cout << m - ans << '\n';
    for (i = 1; i <= m - ans; ++i)
        std::cout << u[t[i]] << ' ' << v[t[i]] << '\n';
    return 0;
}