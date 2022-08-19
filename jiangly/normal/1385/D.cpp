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
        int k = __builtin_ctz(n);
        std::vector<std::vector<int>> pre(k, std::vector<int>(n + 1));
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < n; ++j)
                pre[i][j + 1] = pre[i][j] + (s[j] == 'a' + i);
        std::function<int(int, int)> get = [&](int l, int r) {
            if (r - l == 1)
                return (s[l] == 'a' + k) ? 0 : 1;
            int m = (l + r) / 2;
            int x = get(l, m), y = get(m, r);
            int c = k - __builtin_ctz(r - l);
            return std::min(x + r - m - (pre[c][r] - pre[c][m]), y + m - l - (pre[c][m] - pre[c][l]));
        };
        std::cout << get(0, n) << "\n";
    }
    return 0;
}