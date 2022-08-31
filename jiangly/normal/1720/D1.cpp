#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 300000 * 31;

int cnt;
int trie[N][2];
int f[N][2];

int newNode() {
    ++cnt;
    trie[cnt][0] = trie[cnt][1] = 0;
    f[cnt][0] = f[cnt][1] = 0;
    return cnt;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    cnt = 0;
    newNode();
    
    std::vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int x = a[i] ^ i;
        int p = 1;
        for (int j = 29; j >= 0; j--) {
            int v = x >> j & 1;
            dp[i] = std::max(dp[i], f[trie[p][!v]][i >> j & 1]);
            p = trie[p][v];
            if (!p) {
                break;
            }
        }
        dp[i]++;
        p = 1;
        for (int j = 29; j >= 0; j--) {
            int v = x >> j & 1;
            if (!trie[p][v]) {
                trie[p][v] = newNode();
            }
            p = trie[p][v];
            int &res = f[p][a[i] >> j & 1];
            res = std::max(res, dp[i]);
        }
    }
    
    
    int ans = *std::max_element(dp.begin(), dp.end());
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