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
    int m = (n + 1) / 2;
    auto s = query(0, m), t = query(1, m);
    for (auto &&i : t) s.erase(s.find(i));
    std::vector<std::string> pre(s.begin(), s.end());
    std::sort(pre.begin(), pre.end(), [&](const auto &lhs, const auto &rhs) {
        return lhs.length() < rhs.length();
    });
    std::string hf = pre[0];
    for (int i = 1; i < m; ++i) {
        std::vector<int> cnt(26);
        for (char c : pre[i]) ++cnt[c - 'a'];
        for (char c : pre[i - 1]) --cnt[c - 'a'];
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] == 1) hf += 'a' + j;
        }
    }
    std::string ans(n, 'a');
    auto f = query(0, n);
    std::vector<std::vector<std::string>> sl(n);
    for (auto s : f) sl[s.length() - 1].push_back(s);
    for (int i = 0; i < m; ++i) ans[i] = hf[i];
    for (int i = 0; i < n / 2; ++i) {
        std::vector<int> cnt(26);
        for (auto &t : sl[n - i - 2]) {
            for (char c : t) ++cnt[c - 'a'];
        }
        for (int j = 0; j <= i; ++j) cnt[ans[j] - 'a'] -= j + 1;
        for (int j = n - i; j < n; ++j) cnt[ans[j] - 'a'] -= n - j;
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] % (i + 2) != 0) ans[n - i - 1] = 'a' + j;
        }
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}