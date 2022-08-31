#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> a(n);
        std::vector<int> v;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i].first >> a[i].second;
            v.push_back(a[i].first);
            v.push_back(a[i].second);
        }
        ++n;
        a.emplace_back(0, 2e5 + 1);
        v.push_back(0);
        v.push_back(2e5 + 1);
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; ++i) {
            a[i].first = std::lower_bound(v.begin(), v.end(), a[i].first) - v.begin();
            a[i].second = std::lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
        }
        std::sort(a.begin(), a.end(), [&](const auto &lhs, const auto &rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second > rhs.second;
            } else {
                return lhs.first < rhs.first;
            }
        });
        std::vector<int> dp(n);
        int m = v.size();
        for (int i = n - 1; i >= 0; --i) {
            int mx = 0;
            std::vector<int> f(m);
            int x = a[i].first - 1;
            for (int j = i + 1; j < n; ++j) {
                if (a[j].second > a[i].second)
                    continue;
                while (x + 1 < a[j].first) {
                    ++x;
                    mx = std::max(mx, f[x]);
                }
                f[a[j].second] = std::max(f[a[j].second], dp[j] + mx);
            }
            while (x < a[i].second) {
                ++x;
                mx = std::max(mx, f[x]);
            }
            dp[i] = 1 + mx;
        }
        std::cout << dp[0] - 1 << "\n";
    }
    return 0;
}