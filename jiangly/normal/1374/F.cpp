#include <bits/stdc++.h>
constexpr int N = 500;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int i, int j) {return a[i] < a[j];});
        std::vector<int> vis(n);
        int cnt = n;
        for (int i = 0; i < n; ++i) {
            if (vis[i])
                continue;
            for (int j = i; !vis[j]; j = p[j])
                vis[j] = 1;
            --cnt;
        }
        if (cnt % 2 == 1) {
            bool ok = false;
            for (int i = 0; i < n - 1; ++i) {
                if (a[p[i]] == a[p[i + 1]]) {
                    ok = true;
                    std::swap(p[i], p[i + 1]);
                    break;
                }
            }
            if (!ok) {
                std::cout << -1 << "\n";
                continue;
            }
        }
        for (int i = 0; i < n; ++i)
            a[p[i]] = i;
        std::vector<int> t;
        auto shift = [&](int x) {
            t.push_back(x);
            std::swap(a[x], a[x + 2]);
            std::swap(a[x + 1], a[x + 2]);
        };
        for (int i = 0; i < n - 2; ++i) {
            int j = i;
            while (a[j] != i)
                ++j;
            while (j != i) {
                if (j - 2 >= i) {
                    shift(j - 2);
                    j -= 2;
                } else {
                    shift(j - 1);
                    ++j;
                }
            }
        }
        std::cout << t.size() << "\n";
        for (int i = 0; i < int(t.size()); ++i)
            std::cout << t[i] + 1 << " \n"[i == int(t.size()) - 1];
    }
    return 0;
}