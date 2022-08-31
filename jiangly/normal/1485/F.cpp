#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 1e9 + 7;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    i64 sum = 0;
    int sumdp = 0;
    std::map<i64, int> dp;
    for (int i = 0; i < n; i++) {
        int v = i == 0 ? 1 : (sumdp - dp[sum] + P) % P;
        sumdp = (sumdp + v) % P;
        dp[sum] = (dp[sum] + v) % P;
        sum += b[i];
    }
    std::cout << sumdp << "\n";
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