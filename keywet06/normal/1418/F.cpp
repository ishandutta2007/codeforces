#include <bits/stdc++.h>

const int N = 2e5;

int cnt[N + 1];

std::vector<int> ds[N + 1];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int64_t l, r;
    std::cin >> l >> r;
    --l;
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i) ds[j].push_back(i);
    std::set<int> s;
    for (int x1 = 1, L = m, R = m; x1 <= n; ++x1) {
        int64_t ly = l / x1;
        int64_t ry = std::min<int64_t>(m, r / x1);
        if (ly >= ry) {
            std::cout << -1 << "\n";
            continue;
        }
        while (L > ly) {
            for (auto c : ds[L]) {
                if (cnt[c] == 0) s.insert(c);
                ++cnt[c];
            }
            --L;
        }
        while (R > ry) {
            for (auto c : ds[R]) {
                --cnt[c];
                if (cnt[c] == 0) s.erase(c);
            }
            --R;
        }
        bool ok = false;
        for (auto b : ds[x1]) {
            int a = x1 / b;
            auto it = s.upper_bound(b);
            if (it != s.end() && *it <= n / a) {
                int c = *it;
                int d = R / c;
                std::cout << a * b << " " << c * d << " " << a * c << " "
                          << b * d << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) std::cout << -1 << "\n";
    }
    return 0;
}