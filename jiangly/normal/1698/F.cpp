#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::multiset<std::pair<int, int>> sa, sb;
    for (int i = 0; i <= n; i++) {
        sa.insert(std::minmax(i == 0 ? 0 : a[i - 1], i == n ? n + 1 : a[i]));
        sb.insert(std::minmax(i == 0 ? 0 : b[i - 1], i == n ? n + 1 : b[i]));
    }
    
    if (sa != sb) {
        std::cout << "NO\n";
        return;
    }
    
    std::cout << "YES\n";
    std::vector<std::array<int, 2>> ans;
    
    for (int i = 0; i < n; i++) {
        while (a[i] != b[i]) {
            int right = n - 1;
            while (a[right] != b[i - 1]) {
                right--;
            }
            
            bool ok = false;
            for (int j = i; j < right; j++) {
                if (a[j] == b[i] && a[j + 1] == b[i - 1]) {
                    std::reverse(a.begin() + i - 1, a.begin() + j + 2);
                    ans.push_back({i - 1, j + 2});
                    ok = true;
                    break;
                }
                if (a[j] == b[i - 1] && a[j + 1] == b[i]) {
                    std::reverse(a.begin() + j, a.begin() + right + 1);
                    ans.push_back({j, right + 1});
                    std::reverse(a.begin() + i - 1, a.begin() + right + 1);
                    ans.push_back({i - 1, right + 1});
                    ok = true;
                    break;
                }
            }
            
            if (!ok) {
                for (int x = i; x < right; x++) {
                    for (int y = right + 1; y < n; y++) {
                        if (a[x] == a[y]) {
                            std::reverse(a.begin() + x, a.begin() + y + 1);
                            ans.push_back({x, y + 1});
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
            }
        }
    }
    
    std::cout << ans.size() << "\n";
    for (auto [l, r] : ans) {
        std::cout << l + 1 << " " << r << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}