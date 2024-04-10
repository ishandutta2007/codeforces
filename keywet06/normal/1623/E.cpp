#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s, s = ' ' + s;
    std::vector<int> ls(n + 1), rs(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> ls[i] >> rs[i];
    std::string Ds(n + 1, ' ');
    std::vector<int> Dfn(n + 1);
    int Clock = 0;
    std::function<void(int)> Dfs1 = [&](int u) {
        if (ls[u]) Dfs1(ls[u]);
        Ds[Dfn[u] = ++Clock] = s[u];
        if (rs[u]) Dfs1(rs[u]);
    };
    Dfs1(1);
    std::vector<bool> Bo(n + 1);
    for (int i = n - 1; i; --i) Bo[i] = Ds[i] == Ds[i + 1] ? Bo[i + 1] : Ds[i] < Ds[i + 1];
    std::vector<bool> Ans(n + 1);
    std::function<void(int)> Dfs2 = [&](int u) {
        if (!k) return;
        if (Bo[Dfn[u]]) {
            Ans[u] = true, --k;
            if (ls[u]) Dfs2(ls[u]);
            if (rs[u]) Dfs2(rs[u]);
        } else {
            Ans[u] = true;
            int t = --k;
            if (ls[u]) Dfs2(ls[u]);
            if (t == k) return void((++k, Ans[u] = false));
            if (rs[u]) Dfs2(rs[u]);
        }
    };
    Dfs2(1);
    std::function<void(int)> DfsO = [&](int u) {
        if (ls[u]) DfsO(ls[u]);
        std::cout << s[u];
        if (Ans[u]) std::cout << s[u];
        if (rs[u]) DfsO(rs[u]);
    };
    DfsO(1), std::cout << std::endl;
    return 0;
}