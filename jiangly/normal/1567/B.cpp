#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 300000;

int pre[N + 1];

void solve() {
    int a, b;
    std::cin >> a >> b;
    
    int res;
    b ^= pre[a];
    if (b == 0) {
        res = a;
    } else if (b != a) {
        res = a + 1;
    } else {
        res = a + 2;
    }
    
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    pre[0] = 0;
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] ^ i;
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}