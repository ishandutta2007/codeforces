#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        std::cin >> L[i] >> R[i];
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int v = L[i]; v <= R[i]; v++) {
                double pr = 1.0 / (R[i] - L[i] + 1);
                pr *= 1.0 * std::max(0, R[j] - std::max(L[j], v + (j < i)) + 1) / (R[j] - L[j] + 1);
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) {
                        continue;
                    }
                    pr *= 1.0 * std::max(0, std::min(R[k], v - (k > i)) - L[k] + 1) / (R[k] - L[k] + 1);
                }
                ans += pr * v;
            }
        }
    }
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
    return 0;
}