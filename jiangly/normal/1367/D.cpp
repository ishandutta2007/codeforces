#include <bits/stdc++.h>
constexpr int N = 50;
int b[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int z;
    std::cin >> z;
    while (z--) {
        std::string s;
        std::cin >> s;
        int m;
        std::cin >> m;
        for (int i = 0; i < m; ++i)
            std::cin >> b[i];
        int cnt[26] = {};
        for (auto c : s)
            ++cnt[c - 'a'];
        int r = m, l = 25;
        std::string t(m, '?');
        while (r) {
            int c = 0;
            for (int i = 0; i < m; ++i)
                if (!b[i])
                    ++c;
            while (cnt[l] < c)
                --l;
            for (int i = 0; i < m; ++i) {
                if (!b[i]) {
                    t[i] = 'a' + l;
                    --b[i];
                    --r;
                }
            }
            for (int i = 0; i < m; ++i)
                if (t[i] == 'a' + l)
                    for (int j = 0; j < m; ++j)
                        if (b[j] > 0)
                            b[j] -= std::abs(i - j);
            --l;
        }
        std::cout << t << "\n";
    }
    return 0;
}