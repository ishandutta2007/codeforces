#include <bits/stdc++.h>

const int N = 26;

int T, n, k, c;
int Num[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k, c = n / k;
        std::string s;
        std::cin >> s;
        memset(Num, 0, sizeof(Num));
        for (auto ch : s) ++Num[ch - 'a'];
        for (int i = 1, j; i <= k; ++i) {
            for (j = 0; j < c && Num[j]; ++j) --Num[j];
            std::cout << char('a' + j);
        }
        std::cout << '\n';
    }
    return 0;
}