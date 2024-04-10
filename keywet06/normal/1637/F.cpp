#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> h(n + 1);
    int Root = 1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> h[i];
        if (h[i] > h[Root]) Root = i;
    }
    std::vector<std::vector<int> > To(n + 1);
    for (int i = 1, u, v; i < n; ++i) std::cin >> u >> v, To[u].push_back(v), To[v].push_back(u);
    int64 Ans = 0;
    std::function<int(int, int)> Dfs = [&](int u, int F) -> int {
        int Max = 0;
        for (int v : To[u]) {
            if (v == F) continue;
            Max = std::max(Max, Dfs(v, u));
        }
        if (h[u] > Max) Ans += h[u] - Max, Max = h[u];
        return Max;
    };
    int Max = 0, RMax = 0;
    for (int v : To[Root]) {
        int x = Dfs(v, Root);
        if (x > Max) {
            RMax = Max, Max = x;
        } else if (x > RMax) {
            RMax = x;
        }
    }
    Ans += h[Root] - Max + h[Root] - RMax;
    std::cout << Ans << '\n';
    return 0;
}