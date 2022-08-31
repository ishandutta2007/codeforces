#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), c(n);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            --x;
            ++c[x];
            a[x] = i;
        }
        int ans = 0;
        while (ans < n && c[ans] != 1) ++ans;
        std::cout << (ans == n ? -1 : a[ans] + 1) << "\n";
    }
    
    return 0;
}