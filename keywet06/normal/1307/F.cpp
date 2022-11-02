// LUOGU_RID: 90783546
#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << ": "
#define Deline Debug << std::endl

const int C = 20;
const int N = 400005;

int n, k, r;
int f[N], Id[N], Dis[N], Dep[N], Fa[N][C];

std::vector<int> To[N];

inline void Dfs(int u, int f) {
    Fa[u][0] = f, Dep[u] = Dep[f] + 1;
    for (int i = 1; i < C; ++i) Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
    for (auto v : To[u]) {
        if (v != f) Dfs(v, u);
    }
}

inline int Up(int u, int x) {
    while (x) u = Fa[u][__builtin_ctz(x)], x &= x - 1;
    return u;
}

inline int LCA(int u, int v) {
    if (Dep[v] > Dep[u]) std::swap(u, v);
    u = Up(u, Dep[u] - Dep[v]);
    for (int i = C - 1; i >= 0; --i) {
        if (Fa[u][i] != Fa[v][i]) u = Fa[u][i], v = Fa[v][i];
    }
    return u == v ? u : Fa[u][0];
}

inline int Find(int u) { return f[u] == u ? u : f[u] = Find(f[u]); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> k >> r;
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y;
        To[x].push_back(i + n);
        To[i + n].push_back(x);
        To[i + n].push_back(y);
        To[y].push_back(i + n);
    }
    Dfs(1, 1);
    {  // BFS
        std::queue<int> Que;
        n += n - 1;
        for (int i = 1, u; i <= r; ++i) std::cin >> u, f[i] = Id[u] = i, Que.push(u);
        while (!Que.empty()) {
            int u = Que.front();
            Que.pop();
            for (auto v : To[u]) {
                if (!Id[v]) {
                    if (Id[v] = Id[u], (Dis[v] = Dis[u] + 1) < k) Que.push(v);
                } else {
                    f[Find(Id[u])] = Find(Id[v]);
                }
            }
        }
    }
    int Q;
    std::cin >> Q;
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        int x = LCA(u, v);
        if (Dep[u] + Dep[v] - Dep[x] * 2 <= 2 * k && (std::cout << "YES\n", true)) continue;
        if (Dep[u] - Dep[x] < k) std::swap(u, v);
        v = Dep[v] - Dep[x] < k ? Up(u, Dep[u] + Dep[v] - Dep[x] * 2 - k) : Up(v, k), u = Up(u, k);
        std::cout << (Find(Id[u]) == Find(Id[v]) && Find(Id[u]) ? "YES" : "NO") << '\n';
    }
    return 0;
}