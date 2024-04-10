#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 0; i < n - 1; ++i)
            if (a[i + 1] > a[i] + 1)
                ok = false;
        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}