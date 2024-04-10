#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    int ans = 0;
    
    i64 alice = 0, bob = 0;
    for (int i = 0, j = n - 1; i < n; i++) {
        alice += w[i];
        while (alice > bob) {
            bob += w[j];
            j--;
        }
        if (alice == bob && i <= j) {
            ans = std::max(ans, i + n - j);
        }
    }
    
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