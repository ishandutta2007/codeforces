#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    
    // std::vector f(n, std::vector<int>(n));
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         f[i][j] = f[j][i] = std::gcd(x[i] - x[j], y[i] - y[j]) % 4;
    //     }
    // }
    
    for (int i = 0; i < n; i++) {
        x[i] /= 2;
        x[i] %= 2;
        y[i] /= 2;
        y[i] %= 2;
        // x[i] %= 4;
        // y[i] %= 4;
    }
    
    // auto getArea = [&](int x1, int y1, int x2, int y2, int x3, int y3) {
    //     int ans = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    //     ans = (ans % 4 + 4) % 4;
    //     return ans;
    // };
    
    i64 ans = 0;
    
    // int cnt[4][4][4][4][4] = {};
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         cnt[x[i]][y[i]][x[j]][y[j]][f[i][j]]++;
    //     }
    // }
    
    auto get = [&](int x1, int y1, int x2, int y2) {
        return (x1 ^ x2) | (y1 ^ y2);
    };
    
    int cnt[2][2] = {};
    for (int i = 0; i < n; i++) {
        cnt[x[i]][y[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        cnt[x[i]][y[i]]--;
        for (int j = i + 1; j < n; j++) {
            cnt[x[j]][y[j]]--;
            for (int x1 = 0; x1 < 2; x1++) {
                for (int y1 = 0; y1 < 2; y1++) {
                    if ((get(x[i], y[i], x[j], y[j]) ^ get(x[j], y[j], x1, y1) ^ get(x1, y1, x[i], y[i])) == 0) {
                        ans += cnt[x1][y1];
                    }
                }
            }
            cnt[x[j]][y[j]]++;
        }
        cnt[x[i]][y[i]]++;
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i == j) {
    //             continue;
    //         }
    //         cnt[x[i]][y[i]][x[j]][y[j]][f[i][j]]--;
    //     }
    //     for (int x1 = 0; x1 < 4; x1++) {
    //         for (int y1 = 0; y1 < 4; y1++) {
    //             for (int x2 = 0; x2 < 4; x2++) {
    //                 for (int y2 = 0; y2 < 4; y2++) {
    //                     int s = getArea(x[i], y[i], x1, y1, x2, y2);
    //                     if (s % 2 == 0) {
    //                         if (cnt[x1][y1][x2][y2][s] > 0)
    //                         std::cerr << i << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << s << "\n";
    //                         ans += cnt[x1][y1][x2][y2][s];
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     for (int j = 0; j < n; j++) {
    //         if (i == j) {
    //             continue;
    //         }
    //         cnt[x[i]][y[i]][x[j]][y[j]][f[i][j]]++;
    //     }
    // }
    
    ans /= 3;
    std::cout << ans << "\n";
    
    return 0;
}