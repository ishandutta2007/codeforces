#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    std::cout << std::fixed << std::setprecision(10);
    while (t--) {
        int n, l;
        std::cin >> n >> l;
        std::vector<int> a(n + 2);
        a[n + 1] = l;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::vector<double> x(n + 2), y(n + 2);
        for (int i = 1; i <= n + 1; ++i) x[i] = x[i - 1] + 1.0 * (a[i] - a[i - 1]) / i;
        for (int i = 1; i <= n + 1; ++i) y[n + 1 - i] = y[n + 1 - (i - 1)] + 1.0 * (a[n + 1 - (i - 1)] - a[n + 1 - i]) / i;
        int k = 0;
        while (x[k] < y[k]) ++k;
        if (y[k] <= x[k - 1]) std::cout << x[k - 1] + (a[k] - a[k - 1] - (n + 1 - (k - 1)) * (x[k - 1] - y[k])) / (n + 2) << "\n";
        else std::cout << y[k] + (a[k] - a[k - 1] - k * (y[k] - x[k - 1])) / (n + 2) << "\n";
    }
    return 0;
}