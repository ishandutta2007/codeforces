#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        if (b[i] > 0) {
            --b[i];
            ++deg[b[i]];
        }
    }
    std::vector<std::vector<int>> e(n);
    std::queue<int> que;
    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0)
            que.push(i);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans += a[u];
        if (b[u] == -1)
            continue;
        if (a[u] > 0) {
            e[u].push_back(b[u]);
            a[b[u]] += a[u];
        } else {
            e[b[u]].push_back(u);
        }
        if (--deg[b[u]] == 0)
            que.push(b[u]);
    }
    std::cout << ans << "\n";
    std::vector<int> seq;
    for (int i = 0; i < n; ++i)
        for (auto v : e[i])
            ++deg[v];
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0)
            seq.push_back(i);
    for (int i = 0; i < n; ++i) {
        std::cout << seq[i] + 1 << " \n"[i == n - 1];
        for (auto v : e[seq[i]])
            if (--deg[v] == 0)
                seq.push_back(v);
    }
    return 0;
}