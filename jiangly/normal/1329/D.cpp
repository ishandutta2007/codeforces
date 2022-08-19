#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();
        int last = 0;
        std::vector<std::pair<int, char>> v;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                v.emplace_back(i + 1 - last, s[i]);
                last = i + 1;
            }
        }
        int cnt[26] = {};
        for (auto [len, c] : v)
            ++cnt[c - 'a'];
        std::vector<std::pair<int, int>> ans;
        std::vector<std::pair<int, char>> g;
        int tmp = 0;
        int m = v.size();
        int tot = 0;
        char dom = -1;
        for (int i = 0; i < 26; ++i)
            if (2 * cnt[i] >= m)
                dom = 'a' + i;
        for (auto [len, c] : v) {
            len += tmp;
            if (!g.empty() && c != g.back().second && (dom == -1 || c == dom || g.back().second == dom)) {
                --cnt[c - 'a'];
                --cnt[g.back().second - 'a'];
                m -= 2;
                int l = g.back().first;
                int r = l + len;
                ans.emplace_back(l, r);
                tot += r - l;
                g.pop_back();
                tmp = l - (g.empty() ? 0 : g.back().first);
                for (int i = 0; i < 26; ++i)
                    if (2 * cnt[i] >= m)
                        dom = 'a' + i;
            } else {
                g.emplace_back((g.empty() ? 0 : g.back().first) + len, c);
                tmp = 0;
            }
        }
        last = 0;
        for (auto [r, c] : g) {
            ans.emplace_back(0, r - last);
            tot += r - last;
            last = r;
        }
        ans.emplace_back(0, n - tot);
        std::cout << ans.size() << "\n";
        for (auto [l, r] : ans)
            std::cout << l + 1 << " " << r << "\n";
    }
    return 0;
}