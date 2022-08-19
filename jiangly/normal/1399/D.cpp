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
        int cnt = 0;
        std::vector<int> seq[2];
        std::vector<int> ans;
        ans.reserve(n);
        for (auto c : s) {
            int x = c - '0';
            if (seq[!x].empty()) {
                seq[x].push_back(++cnt);
                ans.push_back(cnt);
            } else {
                ans.push_back(seq[!x].back());
                seq[x].push_back(seq[!x].back());
                seq[!x].pop_back();
            }
        }
        std::cout << cnt << "\n";
        for (int i = 0; i < n; ++i)
            std::cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}