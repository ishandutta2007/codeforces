#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<i64> ans(n + 1);
        int timeStamp = 0;
        std::vector<int> in(n), out(n), siz(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            in[u] = timeStamp++;
            for (auto v : e[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
            }
            out[u] = timeStamp;
            siz[u] = out[u] - in[u];
        };
        dfs(0, -1);
        ans[0] = ans[1] = i64(n) * (n - 1) / 2;
        int l = -1;
        for (auto v : e[0]) {
            ans[1] -= i64(siz[v]) * (siz[v] - 1) / 2;
            if (in[v] <= in[1] && in[1] < out[v]) {
                l = v;
            }
        }
        int u = 1, v = -1;
        for (int i = 1; i < n; i++) {
            bool ok = false;
            if (in[i] <= in[u] && in[u] < out[i]) {
                ok = true;
            }
            if (v != -1 && in[i] <= in[v] && in[v] < out[i]) {
                ok = true;
            }
            if (!ok) {
                if (in[u] <= in[i] && in[i] < out[u]) {
                    u = i;
                } else if ((v == -1 && !(in[l] <= in[i] && in[i] < out[l])) || (in[v] <= in[i] && in[i] < out[v])) {
                    v = i;
                } else {
                    break;
                }
            }
            if (v == -1) {
                ans[i + 1] = i64(siz[u]) * (n - siz[l]);
            } else {
                ans[i + 1] = i64(siz[u]) * siz[v];
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] -= ans[i + 1];
        }
        for (int i = 0; i <= n; i++) {
            std::cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}