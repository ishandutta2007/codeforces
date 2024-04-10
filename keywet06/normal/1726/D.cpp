#include <bits/stdc++.h>

const int N = 200005;

int T, n, m;
int Ans[N], Fa[N], Dep[N], Eu[N], Ev[N];

std::vector<int> To[N];

std::vector<std::pair<int, int> > Ext;

inline void Dfs(int u, int F) {
    Fa[u] = F, Dep[u] = Dep[F] + 1;
    for (auto v : To[u]) {
        if (v == F) continue;
        if (!Fa[v]) {
            Dfs(v, u);
        } else {
            if (u < v) Ext.emplace_back(u, v);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        memset(Ans, 0, sizeof(int) * (n + 1));
        memset(Fa, 0, sizeof(int) * (n + 1));
        memset(Dep, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; ++i) To[i].clear();
        Ext.clear();
        for (int i = 1, x, y; i <= m; ++i) {
            std::cin >> x >> y, Eu[i] = x, Ev[i] = y;
            To[x].push_back(y), To[y].push_back(x);
        }
        Dfs(1, 1);
        std::vector<int> t;
        for (auto [u, v] : Ext) t.push_back(u), t.push_back(v);
        std::sort(t.begin(), t.end());
        if (t.size() == 6 && t[0] == t[1] && t[2] == t[3] && t[4] == t[5]) {
            auto [u, v] = Ext.back();
            Ext.pop_back();
            if (Dep[u] < Dep[v]) std::swap(u, v);
            v = Fa[u];
            Ext.emplace_back(u, v);
        }
        for (int i = Ext.size() - 1; i >= 0; --i) Ext.emplace_back(Ext[i].second, Ext[i].first);
        for (int i = 1; i <= m; ++i) {
            int Ans = 0;
            for (auto [u, v] : Ext) Ans |= Eu[i] == u && Ev[i] == v;
            std::cout << Ans;
        }
        std::cout << '\n';
    }
    return 0;
}