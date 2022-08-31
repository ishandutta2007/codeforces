#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n), a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        for (int i = 0; i < n; ++i) std::cin >> c[i];
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                p[i] = a[i];
            } else if (a[i] != p[i - 1] && (i + 1 < n || a[i] != p[0])) {
                p[i] = a[i];
            } else if (b[i] != p[i - 1] && (i + 1 < n || b[i] != p[0])) {
                p[i] = b[i];
            } else {
                p[i] = c[i];
            }
        }
        for (int i = 0; i < n; ++i) std::cout << p[i] << " \n"[i == n - 1];
    }
    return 0;
}