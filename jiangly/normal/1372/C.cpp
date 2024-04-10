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
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
        }
        int l = 0, r = n;
        while (l < n && a[l] == l)
            ++l;
        while (r && a[r - 1] == r - 1)
            --r;
        bool ok = true;
        for (int i = l; i < r; ++i)
            if (a[i] == i)
                ok = false;
        if (l > r) {
            std::cout << 0 << "\n";
        } else if (ok) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 2 << "\n";
        }
    }
    return 0;
}