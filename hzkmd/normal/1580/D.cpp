#include <bits/stdc++.h>

const long long INF = std::numeric_limits<long long>::max() / 2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> sta;
    std::vector<int> ls(n, -1), rs(n, -1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        while (!sta.empty() && a[i] < a[sta.back()]) {
            ls[i] = sta.back();
            sta.pop_back();
        }
        if (!sta.empty()) {
            rs[sta.back()] = i;
        }
        sta.push_back(i);
    }

    std::vector<int> sz(n);
    std::vector<std::vector<long long>> f(n);

    auto upd = [&](auto &a, auto b) {
        a = std::max(a, b);
    };

    auto dfs = [&](auto &self, int u) -> void {
        sz[u] = 1;
        if (ls[u] != -1) {
            self(self, ls[u]);
            sz[u] += sz[ls[u]];
        }
        if (rs[u] != -1) {
            self(self, rs[u]);
            sz[u] += sz[rs[u]];
        }
        f[u].assign(sz[u] + 1, -INF);
        if (ls[u] != -1 && rs[u] != -1) {
            for (int i = 0; i <= sz[ls[u]]; ++i) {
                for (int j = 0; j <= sz[rs[u]]; ++j) {
                    upd(f[u][i + j], f[ls[u]][i] + f[rs[u]][j]
                                     - 2ll * a[u] * i * j);
                    upd(f[u][i + j + 1], f[ls[u]][i] + f[rs[u]][j]
                                         + 1ll * (m - 1 - 2 * (i + j)) * a[u]
                                         - 2ll * a[u] * i * j);
                }
            }
        } else if (ls[u] != -1 || rs[u] != -1) {
            int v = ls[u] != -1 ? ls[u] : rs[u];
            for (int i = 0; i <= sz[v]; ++i) {
                upd(f[u][i], f[v][i]);
                upd(f[u][i + 1], f[v][i] + 1ll * (m - 1 - 2 * i) * a[u]);
            }
        } else {
            f[u][0] = 0;
            f[u][1] = 1ll * (m - 1) * a[u];
        }
    };

    dfs(dfs, sta[0]);
    std::cout << f[sta[0]][m] << "\n";
}