#include <bits/stdc++.h>

using int64 = long long;

const int C = 11;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::array<int, C> f, g;
    f.fill(0), g.fill(0);
    int64 Ans = 0;
    for (auto ch : s) {
        if (ch -= '0') ++g[ch];
        for (int i = ch + 1; i < C; ++i) g[((i - 1) * i / 2 + 9 + ch + 1) % C] += f[i];
        for (int i = 0; i < C; ++i) Ans += f[i] = g[i], g[i] = 0;
    }
    std::cout << Ans << std::endl;
    return 0;
}