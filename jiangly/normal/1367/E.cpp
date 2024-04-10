#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int z;
    std::cin >> z;
    while (z--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        int cnt[26] = {};
        for (auto c : s)
            ++cnt[c - 'a'];
        for (int i = n; i; --i) {
            int t = i / std::gcd(i, k);
            int c = 0;
            for (int j = 0; j < 26; ++j)
                c += cnt[j] / t;
            if (c * t >= i) {
                std::cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}