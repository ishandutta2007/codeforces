#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int x;
        std::cin >> x;
        int s1 = 0;
        int64 s2 = 0, s3 = 0;
        for (int i = 2; i < n; ++i) {
            std::cin >> x;
            if (x & 1) {
                ++s1, s3 += x >> 1;
            } else {
                s2 += x >> 1; 
            }
        }
        std::cin >> x;
        if (s1 == 1 ? s2 < 1 : s2 + s3 < 1) {
            std::cout << -1 << '\n';
            continue;
        }
        std::cout << s1 + s2 + s3 << '\n';
    }
    return 0;
}