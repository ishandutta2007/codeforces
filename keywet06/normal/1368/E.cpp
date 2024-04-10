#include <bits/stdc++.h>

const int N = 2e5;

int T, n, m;

int e[N][2], p[N], l[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) e[i][0] = e[i][1] = -1;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v, --u, --v;
            if (e[u][0] == -1) {
                e[u][0] = v;
            } else if (v != e[u][0]) {
                e[u][1] = v;
            }
        }
        for (int i = 0; i < n; ++i) l[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] == 2) {
                p[cnt++] = i;
                continue;
            }
            for (int j = 0; j < 2; ++j) {
                if (e[i][j] != -1) l[e[i][j]] = std::max(l[e[i][j]], l[i] + 1);
            }
        }
        std::cout << cnt << "\n";
        for (int i = 0; i < cnt; ++i) {
            std::cout << p[i] + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}