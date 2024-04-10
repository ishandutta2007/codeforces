#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        
        int ans = n + 1;
        if (std::is_sorted(a.begin(), a.end())) ans = 0;
        for (int i = 0; i < n; ++i) {
            std::vector<int> b(a);
            b[i] = x;
            std::sort(b.begin(), b.end());
            int cur = x;
            bool ok = true;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (a[j] != b[j]) {
                    ++cnt;
                    if (cur == b[j] && b[j] < a[j]) cur = a[j];
                    else ok = false;
                }
            }
            if (ok) ans = std::min(ans, cnt);
        }
        if (ans > n) ans = -1;
        std::cout << ans << "\n";
    }
    
    return 0;
}