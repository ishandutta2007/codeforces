#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> f(32768, -1);
    f[0] = 0;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (auto y : { (x + 32767) % 32768,
            x & 1 ? 0 : (x >> 1 | 16384),
            x & 1 ? 0 : (x >> 1) }) {
            if (f[y] == -1) {
                f[y] = f[x] + 1;
                q.push(y);
            }
        }
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        std::cout << f[a[i]] << " \n"[i == n - 1];
    }
    
    return 0;
}