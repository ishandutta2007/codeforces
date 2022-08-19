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
    
    std::vector cnt(n, std::vector(4, std::vector(4, std::vector<int>(4))));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int f = std::gcd(x[i] - x[j], y[i] - y[j]) % 4;
            cnt[i][x[j] % 4][y[j] % 4][f]++;
            cnt[j][x[i] % 4][y[i] % 4][f]++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        x[i] %= 4;
        y[i] %= 4;
    }
    
    i64 ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int x1 = 0; x1 < 4; x1++) {
            for (int y1 = 0; y1 < 4; y1++) {
                for (int x2 = x1 % 2; x2 < 4; x2 += 2) {
                    for (int y2 = y1 % 2; y2 < 4; y2 += 2) {
                        int area = x[i] * y1 - x1 * y[i] + x1 * y2 - x2 * y1 + x2 * y[i] - x[i] * y2;
                        area = (area % 4 + 4) % 4;
                        if (area % 2 == 1) {
                            continue;
                        }
                        for (int f1 = 0; f1 < 4; f1++) {
                            int f3 = (x1 ^ x2) | (y1 ^ y2);
                            int f2 = (area - f1 - f3 + 8) % 4;
                            int coef = f1 % 2 == 1 ? 3 : 1;
                            ans += coef * cnt[i][x1][y1][f1] * cnt[i][x2][y2][f2];
                            if (x1 == x2 && y1 == y2 && f1 == f2) {
                                ans -= coef * cnt[i][x1][y1][f1];
                            }
                        }
                    }
                }
            }
        }
    }
    
    ans /= 6;
    
    std::cout << ans << "\n";
    
    return 0;
}