#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int D = 0, K = 0;
        std::map<std::pair<int, int>, int> cnt;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                D++;
            } else {
                K++;
            }
            int d = D, k = K;
            int g = std::gcd(d, k);
            d /= g;
            k /= g;
            std::cout << ++cnt[{d, k}] << " \n"[i == n - 1];
        }
    }
    return 0;
}