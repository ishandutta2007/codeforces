#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        for (int i = 0; i < n; ++i)
            std::cin >> b[i];
        long long suma = std::accumulate(a.begin(), a.end(), 0ll);
        long long sumb = std::accumulate(b.begin(), b.end(), 0ll);
        bool ok = true;
        if (suma > sumb)
            ok = false;
        long long s = 0;
        long long mx = -1e18;
        for (int i = 0; i < 2 * n; ++i) {
            s += b[i % n] - a[i % n];
            mx = std::max(mx, s - b[i % n]);
            if (s < mx)
                ok = false;
        }
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}