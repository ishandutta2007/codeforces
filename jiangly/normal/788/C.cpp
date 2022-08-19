#include <bits/stdc++.h>

constexpr int N = 1000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    
    if (n < a[0] || n > a.back()) {
        std::cout << -1 << "\n";
        return 0;
    }
    
    std::vector<int> dis(N + 1, -1);
    std::queue<int> que;
    for (int i = 0; i < k; ++i) {
        if (a[i] == n) {
            std::cout << 1 << "\n";
            return 0;
        }
        dis[a[i]] = 1;
        que.push(a[i]);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto x : a) {
            int v = u + x - n;
            if (0 <= v && v <= N && dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    
    std::cout << dis[n] << "\n";
    
    return 0;
}