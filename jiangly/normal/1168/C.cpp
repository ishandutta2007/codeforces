#include <bits/stdc++.h>

constexpr int N = 3e5;

int n, q;
int a[N];
int f[N][19];
int b[19];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 19; ++j)
            f[i][j] = n;
    std::memset(b, -1, sizeof(b));
    
    for (int i = n - 1; i >= 0; --i) {
        for (int x = 0; x < 19; ++x) {
            if (a[i] >> x & 1) {
                f[i][x] = i;
            } else {
                for (int y = 0; y < 19; ++y)
                    if ((a[i] >> y & 1) && b[y] != -1)
                        f[i][x] = std::min(f[i][x], f[b[y]][x]);
            }
        }
        for (int x = 0; x < 19; ++x)
            if (a[i] >> x & 1)
                b[x] = i;
    }
    
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;
        bool ok = false;
        for (int i = 0; i < 19; ++i)
            if ((a[y] >> i & 1) && f[x][i] <= y)
                ok = true;
        std::cout << (ok ? "Shi" : "Fou") << "\n";
    }
    
    return 0;
}