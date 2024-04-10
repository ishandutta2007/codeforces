#include <bits/stdc++.h>

using i64 = long long;

int query(int i, int j, int k) {
    std::cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    
    int x = 0, y = 1;
    for (int i = 2; i < n; i += 2) {
        std::vector p{x, y, i};
        if (i + 1 < n) {
            p.push_back(i + 1);
        } else {
            int z = 0;
            while (z == x || z == y) {
                z++;
            }
            p.push_back(z);
        }
        
        std::vector<int> f(4);
        f[0] = query(p[1], p[2], p[3]);
        f[1] = query(p[0], p[2], p[3]);
        f[2] = query(p[0], p[1], p[3]);
        f[3] = query(p[0], p[1], p[2]);
        
        std::vector q{0, 1, 2, 3};
        std::sort(q.begin(), q.end(), [&](int i, int j) { return f[i] < f[j]; });
        
        x = p[q[0]];
        y = p[q[1]];
    }
    
    std::cout << "! " << x + 1 << " " << y + 1 << std::endl;
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