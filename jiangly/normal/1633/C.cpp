#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 hc, dc, hm, dm;
    std::cin >> hc >> dc >> hm >> dm;
    
    i64 k, w, a;
    std::cin >> k >> w >> a;
    
    for (int i = 0; i <= k; i++) {
        i64 h = hc + a * i;
        i64 d = dc + w * (k - i);
        
        i64 cm = (hm + d - 1) / d;
        i64 mc = (h + dm - 1) / dm;
        
        if (cm <= mc) {
            std::cout << "YES\n";
            return;
        }
    }
    
    std::cout << "NO\n";
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