// Luogu Remote

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int N = n;
        std::vector<std::vector<int> > To(n);
        for (int i = 1, u, v; i < n; ++i) {
            std::cin >> u >> v, --u, --v;
            To[u].push_back(v), To[v].push_back(u);
        }
        std::vector<int> RDep(n), MDep(n), Son(n, -1);
        std::function<void(int, int)> Dfs = [&](int u, int f) -> void {
            for (int v : To[u]) {
                if (v == f) continue;
                Dfs(v, u);
                if (MDep[v] + 1 > MDep[u]) {
                    RDep[u] = MDep[u], MDep[u] = MDep[v] + 1, Son[u] = v;
                } else if (MDep[v] + 1 > RDep[u]) {
                    RDep[u] = MDep[v] + 1;
                }
            }
        };
        Dfs(0, -1);
        std::vector<int> Dep;
        for (int u = 0; u != -1; u = Son[u]) Dep.push_back(RDep[u]);
        n = Dep.size();
        std::cout << std::flush;
        std::vector<std::vector<int> > Nodes(n + 1);
        for (int i = 0; i < n; ++i) Nodes[Dep[i] + i].push_back(i);
        std::vector<int> R(n + 1);
        int Max = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int x : Nodes[i + 1]) Max = std::max(Max, n - 1 - x + Dep[x]);
            R[i] = i - (Max + 1) / 2;
        }
        R[n - 1] = N;
        std::vector<int> Ans(N + 1);
        for (int i = 1; i < n; ++i) {
            for (int j = std::max(R[i - 1] + 1, 1); j <= R[i]; ++j) Ans[j] = i;
        }
        for (int i = 1; i <= N; ++i) std::cout << Ans[i] << " \n"[i == N];
    }
    return 0;
}