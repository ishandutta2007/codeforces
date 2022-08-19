#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int mxr = 0, mxw = 0;
    for (int i = 0; i < m; i++) {
        int r, w;
        std::cin >> r >> w;
        mxr = std::max(mxr, r);
        mxw = std::max(mxw, w);
    }
    if (mxr + mxw > n) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << std::string(mxr, 'R') + std::string(n - mxr, 'W') << "\n";
    }
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