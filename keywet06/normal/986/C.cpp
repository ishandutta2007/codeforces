#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> was(1 << n, 1);
    for (int i = 0, x; i < m; ++i) std::cin >> x, was[x] = 0;
    std::vector<int> used(1 << n, 0);
    std::vector<int> que(1 << n);
    std::vector<int> inner(1 << n);
    int ans = 0;
    for (int start = 0; start < (1 << n); ++start) {
        if (was[start]) continue;
        ++ans;
        was[start] = 1;
        que[0] = start;
        int qs = 1;
        for (int q = 0; q < qs; ++q) {
            int u = (1 << n) - 1 - que[q];
            if (!used[u]) {
                used[u] = 1, inner[0] = u;
                int is = 1;
                for (int i = 0; i < is; ++i) {
                    int z = inner[i];
                    if (!was[z]) was[z] = 1, que[qs++] = z;
                    for (int bit = 0; bit < n; ++bit) {
                        if ((z & (1 << bit)) && !used[z ^ (1 << bit)]) {
                            used[z ^ (1 << bit)] = 1;
                            inner[is++] = z ^ (1 << bit);
                        }
                    }
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}