#include <bits/stdc++.h>
using i64 = long long;
constexpr int Log = 18;
int main() {
    int q;
    std::cin >> q;
    std::vector<int> a(q + 1), c(q + 1), dep(q + 1);
    std::vector p(q + 1, std::vector<int>(Log + 1, -1));
    std::cin >> a[0] >> c[0];
    for (int i = 1; i <= q; i++) {
        int op;
        std::cin >> op;
        if (op == 1) {
            std::cin >> p[i][0];
            dep[i] = dep[p[i][0]] + 1;
            for (int j = 0; (1 << j) <= dep[i]; j++) {
                p[i][j + 1] = p[p[i][j]][j];
            }
            std::cin >> a[i] >> c[i];
        } else {
            int v, w;
            std::cin >> v >> w;
            int sum = 0;
            i64 cost = 0;
            while (w && a[v]) {
                int u = v;
                for (int j = Log; j >= 0; j--) {
                    if (p[u][j] != -1 && a[p[u][j]]) {
                        u = p[u][j];
                    }
                }
                int t = std::min(w, a[u]);
                sum += t;
                cost += i64(t) * c[u];
                a[u] -= t;
                w -= t;
            }
            std::cout << sum << " " << cost << std::endl;
        }
    }
    return 0;
}