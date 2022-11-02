#include <bits/stdc++.h>

void Solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, T;
    std::cin >> s >> T;
    std::vector<int> Pre(m + 1), Suf(m + 1);
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && s[j] != T[i]) ++j;
        if (j == n) return void(std::cout << "-1\n");
        Pre[i + 1] = ++j;
    }
    Suf[m] = n;
    for (int i = m - 1, j = n - 1; i >= 0; --i) {
        while (s[j] != T[i]) --j;
        Suf[i] = --j;
    }
    std::vector LCP(n + 1, std::vector<int>(m + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) LCP[i][j] = s[i] == T[j] ? 1 + LCP[i + 1][j + 1] : 0;
    }
    int Ans = n - Suf[0];
    for (int i = 0; i < m; ++i) {
        for (int j = Pre[i]; j < n; ++j) {
            int Len = LCP[j][i];
            if (Suf[i + Len] >= j + Len) Ans = std::min(Ans, (j > 0) + j + (m - i - Len));
        }
    }
    Ans += n - m;
    std::cout << Ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}