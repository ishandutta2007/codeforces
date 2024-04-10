#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

struct Fenwick {
    const int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n, -inf) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = std::max(a[i - 1], v);
        }
    }
    int sum(int x) {
        int ans = -inf;
        for (int i = x; i > 0; i -= i & -i) {
            ans = std::max(ans, a[i - 1]);
        }
        return ans;
    }
};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    auto v = s;
    std::sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
        s[i] = std::lower_bound(v.begin(), v.end(), s[i]) - v.begin();
    }
    
    Fenwick fen(n + 1);
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        fen.add(s[i - 1], dp[i - 1] - (i - 1));
        dp[i] = std::max(dp[i - 1] + (a[i - 1] < 0 ? -1 : 0), i + fen.sum(s[i]));
    }
    
    std::cout << dp[n] << "\n";
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