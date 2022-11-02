#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    std::string Ans(1 << 20, '0');
    for (int i = 0; i < n; ++i) {
        int p = b[i];
        for (int j = i; j < n; ++j) {
            if (j > i) {
                if (b[j] >= 20) break;
                if (((1LL * p) << b[j]) >= (1 << 20)) break;
                p <<= b[j];
            }
            int Fr = n - 1 - (j - i) - (i > 0) - (j < n - 1);
            int Lea = std::max(0, k - (i > 0) - (j < n - 1));
            if (Lea > Fr) continue;
            if (Fr == 0) {
                Ans[(1 << 20) - p - 1] ^= 1;
                continue;
            }
            int t = __builtin_ctz(Fr);
            if (Lea & ((1 << t) - 1)) Lea &= ~((1 << t) - 1), Lea += 1 << t;
            if ((Lea & Fr) == Lea && (Lea >> t & 1)) Ans[(1 << 20) - p - 1] ^= 1;
        }
    }
    int i = 0;
    while (i < (1 << 20) - 1 && Ans[i] == '0') ++i;
    std::cout << Ans.substr(i) << "\n";
    return 0;
}