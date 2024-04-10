#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
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
        bool p = false, m = false;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if ((a[i] < b[i] && !p) || (a[i] > b[i] && !m))
                ok = false;
            p |= a[i] == 1;
            m |= a[i] == -1;
        }
        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}