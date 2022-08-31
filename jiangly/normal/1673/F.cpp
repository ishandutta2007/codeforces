#include <bits/stdc++.h>

using i64 = long long;

int f(int x) {
    int y = 0;
    for (int i = 0; i < 5; i++) {
        if (x >> i & 1) {
            y |= 1 << (2 * i);
        }
    }
    return y;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = f(i ^ (i >> 1)) * 2 + f(j ^ (j >> 1));
        }
    }
    
    std::vector<std::array<int, 2>> pos(1 << 10, { -1, -1 });
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pos[a[i][j]] = { i, j };
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int v = a[i][j] ^ a[i][j + 1];
            std::cout << v << " \n"[j == n - 2];
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int v = a[i][j] ^ a[i + 1][j];
            std::cout << v << " \n"[j == n - 1];
        }
    }
    
    std::cout.flush();
    
    int cur = 0;
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        cur ^= x;
        
        std::cout << pos[cur][0] + 1 << " " << pos[cur][1] + 1 << std::endl;
    }
    
    return 0;
}