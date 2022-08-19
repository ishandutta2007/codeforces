#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::vector<int> a;
        for (int i = 0, j; i < n; i = j) {
            for (j = i; j < n && s[i] == s[j]; ++j)
                ;
            a.push_back(j - i);
        }
        int ans = 0;
        for (int i = 0; i < int(a.size()); ++i) ans = std::min(i + 1, ans + a[i] - 1);
        std::cout << ans + (a.size() - ans + 1) / 2 << "\n";
    }
    
    return 0;
}