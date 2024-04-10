#include <bits/stdc++.h>

using int64 = long long;
using pair = std::pair<int, int>;

const int N = 200005;
const int M = 524288;

int n, k, DCnt;
int Deep[N], Dfn[N], End[N], Id[N], Vis[N], Fa[N];
int Dec[M];

pair Data[M];

std::vector<int> To[N];

inline void Dfs(int u, int f) {
    Id[Dfn[u] = ++DCnt] = u, Deep[u] = Deep[f] + 1, Fa[u] = f;
    for (int v : To[u]) {
        if (v == f) continue;
        Dfs(v, u);
    }
    End[u] = DCnt;
}

inline void Update(int u) {
    Data[u] = std::max(Data[u << 1], Data[u << 1 | 1]);
    Data[u].first -= Dec[u];
}

inline void Build(int u, int l, int r) {
    if (l == r) return void(Data[u] = pair(Deep[Id[l]], Id[l]));
    int Mid = l + r >> 1;
    Build(u << 1, l, Mid);
    Build(u << 1 | 1, Mid + 1, r);
    Update(u);
}

inline void Red(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return ++Dec[u], void(--Data[u].first);
    int Mid = l + r >> 1;
    if (x <= Mid) Red(u << 1, l, Mid, x, y);
    if (y > Mid) Red(u << 1 | 1, Mid + 1, r, x, y);
    Update(u);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y;
        To[x].push_back(y);
        To[y].push_back(x);
    }
    Dfs(1, 0);
    Build(1, 1, n);
    int64 Ans = -1e17;
    for (int64 r = 0, b = n, e; r <= k; ++r) {
        e = std::min(b, n / 2ll);
        Ans = std::max(Ans, (n - r - e) * (r - e));
        for (int u = Data[1].second; u && !Vis[u]; u = Fa[u]) {
            Vis[u] = 1, Red(1, 1, n, Dfn[u], End[u]), --b;
        }
    }
    std::cout << Ans << std::endl;
    return 0;
}