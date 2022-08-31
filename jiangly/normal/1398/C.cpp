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
        std::vector<int> p(n + 1);
        for (int i = 0; i < n; ++i)
            p[i + 1] = p[i] + s[i] - '1';
        std::map<int, int> cnt;
        int64_t ans = 0;
        for (int i = 0; i <= n; ++i)
            ans += cnt[p[i]]++;
        std::cout << ans << "\n";
    }
    return 0;
}