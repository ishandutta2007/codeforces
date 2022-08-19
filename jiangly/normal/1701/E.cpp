#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s, t;
    std::cin >> s >> t;
    
    std::vector<int> pre(m + 1), suf(m + 1);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && s[j] != t[i]) {
            j++;
        }
        if (j == n) {
            std::cout << "-1\n";
            return;
        }
        pre[i + 1] = ++j;
    }
    
    suf[m] = n;
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (s[j] != t[i]) {
            j--;
        }
        suf[i] = j--;
    }
    
    std::vector lcp(n + 1, std::vector<int>(m + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            lcp[i][j] = s[i] == t[j] ? 1 + lcp[i + 1][j + 1] : 0;
        }
    }
    
    int ans = n - suf[0];
    
    for (int i = 0; i < m; i++) {
        for (int j = pre[i]; j < n; j++) {
            int len = lcp[j][i];
            if (suf[i + len] >= j + len) {
                ans = std::min(ans, (j > 0) + j + (m - i - len));
            }
        }
    }
    
    ans += n - m;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}