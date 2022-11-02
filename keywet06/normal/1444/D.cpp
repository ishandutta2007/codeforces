#include <bits/stdc++.h>

const int N = 500005;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::cin >> m;
        std::vector<int> b(m);
        for (int i = 0; i < m; ++i) std::cin >> b[i];
        if (n != m) {
            std::cout << "No\n";
            continue;
        }
        auto work = [&](const std::vector<int> &a) {
            std::vector<int> a0, a1;
            int sum = std::accumulate(a.begin(), a.end(), 0);
            if (sum % 2 == 1) return std::make_pair(a0, a1);
            std::vector<std::bitset<N>> f(n + 1);
            f[0][0] = 1;
            for (int i = 0; i < n; ++i) f[i + 1] = f[i] | f[i] << a[i];
            if (!f[n][sum / 2]) return std::make_pair(a0, a1);
            int cur = sum / 2;
            for (int i = n - 1; i >= 0; --i) {
                if (f[i][cur])
                    a0.push_back(a[i]);
                else {
                    a1.push_back(a[i]);
                    cur -= a[i];
                }
            }
            if (a0.size() > a1.size()) std::swap(a0, a1);
            return std::make_pair(a0, a1);
        };
        auto [a0, a1] = work(a);
        auto [b0, b1] = work(b);
        if (a0.empty() || b0.empty()) {
            std::cout << "No\n";
            continue;
        }
        std::cout << "Yes\n";
        bool rev = false;
        if (a0.size() > b0.size()) {
            std::swap(a0, b0);
            std::swap(a1, b1);
            rev = true;
        }
        int x = 0, y = 0;
        std::sort(a0.begin(), a0.end(), std::greater<>());
        std::sort(a1.begin(), a1.end(), std::greater<>());
        std::sort(b0.begin(), b0.end());
        std::sort(b1.begin(), b1.end());
        auto print = [&]() {
            if (rev)
                std::cout << y << " " << x << "\n";
            else
                std::cout << x << " " << y << "\n";
        };
        for (int i = 0; i < int(a0.size()); ++i) {
            print();
            x += a0[i];
            print();
            y += b0[i];
        }
        for (int i = a0.size(); i < int(b0.size()); ++i) {
            print();
            x -= a1[i - a0.size()];
            print();
            y += b0[i];
        }
        for (int i = b0.size(); i < n; ++i) {
            print();
            x -= a1[i - a0.size()];
            print();
            y -= b1[i - b0.size()];
        }
    }
    return 0;
}