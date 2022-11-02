#include <bits/stdc++.h>

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

template <typename Type1, typename Type2>
inline Type1 &Mad(Type1 &x, Type2 y) {
    return x > y ? x : (x = y);
}

const int N = 100005;
const int B = 2;

bool Col[N], Ena[N][B];

int t, T, n, m, n1, n2, d;
int El[N], Er[N], Vis[N];

std::vector<int> To[N];

inline void insert(int u, int v) {
    To[u].push_back(v);
    To[v].push_back(u);
}

inline void Dfs(int u, bool c, const int C) {
    Vis[u] = C, d += !Ena[u][Col[u] = c];
    for (int v : To[u]) {
        if (Vis[v] == C && (d += Col[v] == c, true)) continue;
        Dfs(v, !c, C);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> t >> T >> n >> m, n1 = 1, n2 = 1e9;
    for (int i = 1; i <= n; ++i) {
        std::cin >> El[i] >> Er[i];
        Mad(n1, El[i]), Mid(n2, Er[i]);
    }
    for (int i = 1, u, v; i <= m; ++i) std::cin >> u >> v, insert(u, v);
    if (n1 + n2 < t) n1 += t - n1 - n2;
    if (n1 + n2 > T) n2 -= n1 + n2 - T;
    if (n1 < 0 || n2 < 0) return std::cout << "IMPOSSIBLE" << '\n', 0;
    for (int i = 1; i <= n; ++i) {
        Ena[i][0] = n1 >= El[i] && n1 <= Er[i];
        Ena[i][1] = n2 >= El[i] && n2 <= Er[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (Vis[i]) continue;
        d = 0, Dfs(i, false, 1);
        if (!d) continue;
        d = 0, Dfs(i, true, 2);
        if (d) return std::cout << "IMPOSSIBLE" << '\n', 0;
    }
    std::cout << "POSSIBLE" << '\n';
    std::cout << n1 << ' ' << n2 << '\n';
    for (int i = 1; i <= n; ++i) std::cout << Col[i] + 1;
    std::cout << '\n';
    return 0;
}