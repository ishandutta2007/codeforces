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
        auto getMex = [&]() {
            std::vector<int> cnt(n + 1);
            for (int i = 0; i < n; ++i)
                ++cnt[a[i]];
            int x = 0;
            while (cnt[x])
                ++x;
            return x;
        };
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int x = getMex();
            if (x == 0) {
                int j = 0;
                while (j < n && a[j] == j + 1)
                    ++j;
                if (j == n)
                    break;
                a[j] = 0;
                ans.push_back(j + 1);
                x = getMex();
            }
            ans.push_back(x);
            a[x - 1] = x;
        }
        std::cout << ans.size() << "\n";
        for (int i = 0; i < int(ans.size()); ++i)
            std::cout << ans[i] << " \n"[i == int(ans.size()) - 1];
    }
    return 0;
}