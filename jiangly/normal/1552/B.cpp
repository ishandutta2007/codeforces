#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector r(n, std::vector<int>(5));
    
    int u = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> r[i][j];
        }
        if (i == 0) {
            continue;
        }
        int x = 0;
        for (int j = 0; j < 5; j++) {
            x += r[i][j] < r[u][j];
        }
        if (x >= 3) {
            u = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (u == i) {
            continue;
        }
        int x = 0;
        for (int j = 0; j < 5; j++) {
            x += r[i][j] < r[u][j];
        }
        if (x >= 3) {
            u = -1;
            break;
        }
    }
    
    if (u < 0) {
        std::cout << "-1\n";
    } else {
        std::cout << u + 1 << "\n";
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