#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<int> len(n);
    std::vector<std::string> ans(n);
    std::string t;
    char cur = 0;
    int clen = 0;
    char sec = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == cur) {
            ++clen;
        } else {
            if (t.empty() || (t.back() == cur ? sec : t.back()) <= cur) {
                clen %= 2;
            }
            sec = (t.empty() || cur == t.back() || clen == 0) ? sec : t.back();
            t += std::string(clen, cur);
            assert(sec == 0 || sec != t.back());
            cur = s[i];
            clen = 1;
        }
        int alen = clen;
        if (t.empty() || (t.back() == cur ? sec : t.back()) <= cur) alen %= 2;
        len[i] = alen + t.length();
        if (len[i] <= 10) {
            ans[i] = std::string(alen, cur);
            for (int j = int(t.size()) - 1; j >= 0; --j) ans[i] += t[j];
        } else {
            ans[i] = std::string(std::min(5, alen), cur);
            int j = t.length() - 1;
            while (ans[i].size() < 5) ans[i] += t[j--];
            ans[i] += "...";
            ans[i] += t.length() >= 2 ? t[1] : cur;
            ans[i] += t.length() >= 1 ? t[0] : cur;
        }
    }
    for (int i = 0; i < n; ++i) std::cout << len[i] << " " << ans[i] << "\n";
    return 0;
}