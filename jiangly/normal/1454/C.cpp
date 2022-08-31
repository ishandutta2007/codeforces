#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            --x;
            a[x].push_back(i);
        }
        int ans = n;
        for (int x = 0; x < n; ++x) {
            if (a[x].empty()) continue;
            int res = 0;
            if (a[x][0] != 0) ++res;
            if (a[x].back() != n - 1) ++res;
            for (int i = 0; i + 1 < int(a[x].size()); ++i)
                if (a[x][i] + 1 != a[x][i + 1]) ++res;
            ans = std::min(ans, res); 
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}