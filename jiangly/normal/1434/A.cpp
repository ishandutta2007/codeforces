#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a[6];
    for (int i = 0; i < 6; ++i) std::cin >> a[i];
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        for (int j = 0; j < 6; ++j) v.emplace_back(b - a[j], i);
    }
    std::sort(v.begin(), v.end());
    std::vector<int> cnt(n);
    int x = 0;
    int ans = 1e9;
    for (int i = 0, j = 0; i < 6 * n; ++i) {
        while (x < n && j < 6 * n) x += !cnt[v[j++].second]++;
        if (x < n) break;
        x -= !--cnt[v[i].second];
        ans = std::min(ans, v[j - 1].first - v[i].first);
    }
    std::cout << ans << "\n";
    
    return 0;
}