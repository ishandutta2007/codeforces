#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string a[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }
    
    int cnt[3][26] {};
    for (int i = 0; i < 3; i++) {
        for (auto c : a[i]) {
            cnt[i][c - 'A']++;
        }
    }
    
    int minlen = std::min({a[0].length(), a[1].length(), a[2].length()});
    
    std::vector<std::array<int, 2>> match;
    for (int i = 0; i < 26; i++) {
        while (int(match.size()) < minlen && (cnt[0][i] > 0) + (cnt[1][i] > 0) + (cnt[2][i] > 0) >= 2) {
            int j = 0;
            for (int x = 0; x < 3; x++) {
                if (cnt[x][i] < cnt[j][i]) {
                    j = x;
                }
            }
            cnt[(j + 1) % 3][i]--;
            cnt[(j + 2) % 3][i]--;
            match.push_back({j, i});
        }
    }
    
    std::vector<std::string> ans;
    for (auto [x, c] : match) {
        std::string s;
        s += 'A' + c;
        for (int i = 0; i < 26; i++) {
            if (cnt[x][i] > 0) {
                cnt[x][i]--;
                s += 'A' + i;
                break;
            }
        }
        ans.push_back(s);
    }
    
    int len[3];
    for (int i = 0; i < 3; i++) {
        len[i] = std::accumulate(cnt[i], cnt[i] + 26, 0);
    }
    while (len[0] || len[1] || len[2]) {
        int x = std::min_element(len, len + 3) - len;
        std::string s;
        for (auto j : {(x + 1) % 3, (x + 2) % 3}) {
            if (len[j] > 0) {
                len[j]--;
                for (int i = 0; i < 26; i++) {
                    if (cnt[j][i] > 0) {
                        cnt[j][i]--;
                        s += 'A' + i;
                        break;
                    }
                }
            }
        }
        if (s.length() == 1) {
            s += s[0];
        }
        ans.push_back(s);
    }
    
    std::cout << ans.size() << "\n";
    for (auto s : ans) {
        std::cout << s << "\n";
    }
    
    return 0;
}