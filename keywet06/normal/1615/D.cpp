#include <bits/stdc++.h>

inline bool Get(int x) { return __builtin_popcount(x) & 1; }

inline void Main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int> > > To(n);
    for (int i = 1, x, y, v; i < n; ++i) {
        std::cin >> x >> y >> v, --x, --y;
        To[x].emplace_back(y, v);
        To[y].emplace_back(x, v);
    }
    std::vector<int> Up(n), Xor(n), Tp(n), Id(n), Pt(n), Fa(n);
    int DCnt = 1;
    std::function<void(int, int, int, int)> Dfs1 = [&](int u, int F, int U,
                                                       int X) {
        Up[u] = U, Xor[u] = X, Fa[u] = F;
        for (auto [v, w] : To[u]) {
            if (v == F) continue;
            if (w == -1) {
                Pt[Id[v] = DCnt++] = v, Dfs1(v, u, v, X);
            } else {
                Tp[v] = w, Dfs1(v, u, U, X ^ Get(w));
            }
        }
    };
    Dfs1(0, 0, 0, 0);
    std::vector<std::vector<int> > Ro(DCnt << 1);
    auto Insert = [&](int u, int v) { Ro[u].push_back(v); };
    auto Connect = [&](int u, int v) { Insert(u, v), Insert(v, u); };
    for (int i = 1, x, y, p; i <= m; ++i) {
        std::cin >> x >> y >> p, --x, --y;
        p ^= Xor[x] ^ Xor[y], x = Up[x], y = Up[y];
        Connect(Id[x] << 1 | 0, Id[y] << 1 | p);
        Connect(Id[x] << 1 | 1, Id[y] << 1 | !p);
    }
    std::vector<int> Ban(DCnt << 1);
    std::function<void(int)> Dfs2 = [&](int u) {
        Ban[u] = 1;
        for (int v : Ro[u]) {
            if (!Ban[v]) Dfs2(v);
        }
    };
    Dfs2(1);
    std::vector<int> Vis(DCnt << 1);
    std::function<void(int)> Dfs3 = [&](int u) {
        if (Ban[u] || Vis[u]) return;
        Vis[u] = 1;
        for (int v : Ro[u]) Dfs3(v);
    };
    for (int i = 0, x = 0, y = 1; i < DCnt; ++i, x += 2, y += 2) {
        if (Ban[x] && Ban[y]) return void(std::cout << "NO" << '\n');
        if (!Vis[x] && !Vis[y]) Dfs3(Ban[x] ? y : x);
        if (Vis[x] && Vis[y]) return void(std::cout << "NO" << '\n');
    }
    for (int i = 1; i < DCnt; ++i) {
        Tp[Pt[i]] = Vis[i << 1 | 1] ^ Vis[Id[Up[Fa[Pt[i]]]] << 1 | 1];
    }
    std::cout << "YES" << '\n';
    for (int i = 1; i < n; ++i) {
        std::cout << Fa[i] + 1 << ' ' << i + 1 << ' ' << Tp[i] << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) Main();
    return 0;
}