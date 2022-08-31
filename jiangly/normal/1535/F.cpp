#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::pair<std::vector<int>, std::string>> sp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sp[i].second;
        sp[i].first.resize(26);
        for (auto c : sp[i].second) {
            sp[i].first[c - 'a']++;
        }
    }
    std::sort(sp.begin(), sp.end());
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = sp[i].second;
    }
    std::vector<std::string> sv(s);
    for (int i = 0; i < n; i++) {
        std::reverse(sv[i].begin(), sv[i].end());
    }
    i64 ans = i64(n) * (n - 1) / 2 * 1337;
    std::vector inc(n, std::vector<int>(s[0].size() + 1, s[0].size()));
    for (int i = 0; i < n; i++) {
        for (int j = s[i].size() - 2; j >= 0; j--) {
            inc[i][j] = (s[i][j] <= s[i][j + 1]) ? inc[i][j + 1] : j + 1;
        }
    }
    for (int l = 0; l < n; ) {
        int r = l;
        while (r < n && sp[l].first == sp[r].first) {
            r++;
        }
        ans -= i64(r - l) * (r - l - 1) / 2 * 1335;
        if (n <= 10000) {
            std::vector<int> p(r - l);
            std::iota(p.begin(), p.end(), l);
            std::sort(p.begin(), p.end(), [&](int i, int j) {
                return sv[i] < sv[j];
            });
            for (int i = 0; i < r - l; i++) {
                int u = p[i];
                std::vector<int> lcp(r - l);
                int x = 0;
                for (int j = l; j < u; j++) {
                    while (s[u][x] == s[j][x]) {
                        x++;
                    }
                    lcp[j - l] = x;
                }
                x = 0;
                for (int j = r - 1; j > u; j--) {
                    while (s[u][x] == s[j][x]) {
                        x++;
                    }
                    lcp[j - l] = x;
                }
                x = s[0].size() - 1;
                for (int j = r - l - 1; j > i; j--) {
                    while (s[u][x] == s[p[j]][x]) {
                        x--;
                    }
                    int L = lcp[p[j] - l];
                    int R = x + 1;
                    if (inc[u][L] >= R || inc[p[j]][L] >= R) {
                        ans--;
                    }
                }
            }
        } else {
            for (int L = 0; L <= int(s[0].size()); L++) {
                std::vector<char> mn(r - l, 'z'), mx(r - l);
                for (int R = L + 1; R <= int(s[0].size()); R++) {
                    std::vector<int> q;
                    for (int i = l; i < r; i++) {
                        mn[i - l] = std::min(mn[i - l], s[i][R - 1]);
                        mx[i - l] = std::max(mx[i - l], s[i][R - 1]);
                        if ((L == 0 || s[i][L - 1] > mn[i - l]) && (R == int(s[0].size()) || mx[i - l] > s[i][R])) {
                            q.push_back(i);
                        }
                    }
                    std::sort(q.begin(), q.end(), [&](int i, int j) {
                        if (s[i].substr(0, L) != s[j].substr(0, L)) {
                            return s[i].substr(0, L) < s[j].substr(0, L);
                        } else {
                            return s[i].substr(R) < s[j].substr(R);
                        }
                    });
                    int len = q.size();
                    for (int l = 0; l < len; ) {
                        int r = l;
                        while (r < len && s[q[l]].substr(0, L) == s[q[r]].substr(0, L) && s[q[l]].substr(R) == s[q[r]].substr(R)) {
                            r++;
                        }
                        int i = l;
                        while (i < r && inc[q[i]][L] < R) {
                            i++;
                        }
                        if (i < r) {
                            ans -= r - l - 1;
                        }
                        l = r;
                    }
                }
            }
        }
        l = r;
    }
    std::cout << ans << "\n";
    return 0;
}