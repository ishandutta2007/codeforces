#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int d = 0;
    while (d <= 500 && (k * d < n || k * d % 2 != n % 2 || d < 1 + ((k * d - n) / 2 + n - 1) / n * 2)) {
        d++;
    }
    if (d > 500) {
        std::cout << "-1\n";
        return 0;
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1 + ((k * d - n) / 2) / n * 2;
        if (i < (k * d - n) / 2 % n) {
            a[i] += 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < d; i++) {
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int i, int j) {
            return a[i] > a[j];
        });
        std::cout << "?";
        for (int j = 0; j < k; j++) {
            std::cout << " " << p[j] + 1;
            a[p[j]]--;
        }
        std::cout << std::endl;
        int res;
        std::cin >> res;
        ans ^= res;
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}