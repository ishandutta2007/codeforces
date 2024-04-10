#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r;
    std::cin >> l >> r;
    
    std::vector<int> a(r - l + 1);
    for (int i = 0; i <= r - l; i++) {
        std::cin >> a[i];
    }
    
    if (l == r) {
        std::cout << (a[0] ^ l) << "\n";
        return;
    }
    
    int k = std::min(l ? __builtin_ctz(l) : 30, __builtin_ctz(r + 1));
    
    auto tryAns = [&](int x) {
        auto b = a;
        for (auto &y : b) {
            y ^= x;
        }
        std::sort(b.begin(), b.end());
        if (b[0] == l && b.back() == r) {
            std::cout << x << "\n";
            return true;
        }
        return false;
    };
    
    std::sort(a.begin(), a.end());
    for (int i = 0; i < r - l + 1; ) {
        int j = i;
        while (j < r - l + 1 && (a[j] >> (k + 1)) == (a[i] >> (k + 1))) {
            j++;
        }
        if (j - i != (2 << k)) {
            if (tryAns(a[i] ^ l)) {
                return;
            }
            if (tryAns(a[i] ^ r)) {
                return;
            }
        }
        i = j;
    }
    assert(false);
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