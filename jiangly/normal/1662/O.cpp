#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    bool cir[20][360] {}, str[20][360] {};
    bool vis[21][360] {};
    
    for (int i = 0; i < n; i++) {
        char t;
        std::cin >> t;
        
        if (t == 'C') {
            int r, a1, a2;
            std::cin >> r >> a1 >> a2;
            for (int i = a1; i != a2; i = (i + 1) % 360) {
                cir[r - 1][i] = true;
            }
        } else {
            int r1, r2, a;
            std::cin >> r1 >> r2 >> a;
            for (int i = r1; i < r2; i++) {
                str[i][a] = true;
            }
        }
    }
    
    std::queue<std::array<int, 2>> q;
    q.push({0, 0});
    vis[0][0] = true;
    
    auto add = [&](int x, int y) {
        if (!vis[x][y]) {
            vis[x][y] = true;
            q.push({x, y});
        }
    };
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
         
        if (x > 0 && !cir[x - 1][y]) {
            add(x - 1, y);
        }
        if (x < 20 && !cir[x][y]) {
            add(x + 1, y);
        }
        if (x == 20 || !str[x][(y + 1) % 360]) {
            add(x, (y + 1) % 360);
        }
        if (x == 20 || !str[x][y]) {
            add(x, (y + 359) % 360);
        }
    }
    
    if (vis[20][0]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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