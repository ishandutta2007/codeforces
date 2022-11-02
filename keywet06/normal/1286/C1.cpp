#include <bits/stdc++.h>

int n;

auto query(int l, int r) {
    std::multiset<std::string> s;
    std::cout << "? " << l + 1 << " " << r << std::endl;
    for (int i = 0; i < (r - l) * (r - l + 1) / 2; ++i) {
        std::string t;
        std::cin >> t;
        std::sort(t.begin(), t.end());
        s.insert(t);
    }
    return s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    if (n <= 3) {
        std::string s;
        for (int i = 0; i < n; ++i) s += *query(i, i + 1).begin();
        std::cout << "! " << s << std::endl;
        return 0;
    }
    auto s = query(0, n), t = query(1, n);
    for (auto &&i : t) s.erase(s.find(i));
    std::vector<std::string> pre(s.begin(), s.end());
    std::sort(pre.begin(), pre.end(), [&](const auto &lhs, const auto &rhs) {
        return lhs.length() < rhs.length();
    });
    std::string ans = pre[0];
    for (int i = 1; i < n; ++i) {
        std::vector<int> cnt(26);
        for (char c : pre[i]) ++cnt[c - 'a'];
        for (char c : pre[i - 1]) --cnt[c - 'a'];
        for (int j = 0; j < 26; ++j)
            if (cnt[j] == 1) ans += 'a' + j;
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}