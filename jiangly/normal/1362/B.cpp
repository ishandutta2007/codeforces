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
        int ans = -1;
        for (int x = 1; x < 1024; ++x) {
            bool ok = true;
            for (auto i : a)
                if (!std::binary_search(a.begin(), a.end(), i ^ x))
                    ok = false;
            if (ok) {
                ans = x;
                break;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}