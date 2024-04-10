#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector a(k + 1, std::vector<int>(k)), b(k, std::vector<int>(k + 1));
    
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        
        if (r1 + c1 < r2 + c2) {
            std::swap(r1, r2);
            std::swap(c1, c2);
        }
        
        r2++;
        c2++;
        
        if (r1 == r2) {
            a[r1][c1]++;
            a[k - r1][k - c1 - 1]++;
        } else {
            b[r1][c1]++;
            b[k - r1 - 1][k - c1]++;
        }
    }
    
    std::vector dis(k + 1, std::vector<int>(k + 1, -1));
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> h;
    
    h.emplace(0, k / 2, k / 2);
    
    while (!h.empty()) {
        auto [d, x, y] = h.top();
        h.pop();
        
        if (x == 0 || x == k || y == 0 || y == k) {
            std::cout << n - d << "\n";
            return;
        }
        
        if (dis[x][y] != -1) {
            continue;
        }
        dis[x][y] = d;
        
        if (y < k) {
            h.emplace(d + a[x][y], x, y + 1);
        }
        if (x < k) {
            h.emplace(d + b[x][y], x + 1, y);
        }
        if (y > 0) {
            h.emplace(d + a[x][y - 1], x, y - 1);
        }
        if (x > 0) {
            h.emplace(d + b[x - 1][y], x - 1, y);
        }
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