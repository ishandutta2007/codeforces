#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        std::vector<int> b(n);
        std::vector<int> cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i],
            --b[i],
            ++cnt[b[i]];
        }
        int no = 0;
        while (cnt[no]) ++no;
        std::vector<int> a(n, -1);
        int lim = (n - x + n - y) / 2;
        int need = 0;
        for (int i = 0; i <= n; ++i) {
            if (cnt[i] > lim) need += cnt[i] - lim;
        }
        if (need > x) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[b[i]] > lim) {
                a[i] = b[i], --cnt[b[i]], ++cur;
            }
        }
        int t = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1 && b[i] == t && cur < x) {
                a[i] = b[i], --cnt[b[i]], ++cur;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1 && cur < x) {
                a[i] = b[i], --cnt[b[i]], ++cur;
            }
        }
        std::vector<int> f;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) f.push_back(i);
        }
        std::sort(f.begin(), f.end(),
                  [&](int i, int j) { return b[i] < b[j]; });
        int mx = *std::max_element(cnt.begin(), cnt.end());
        for (int i = 0; i < int(f.size()); ++i) {
            int p = f[(i + mx) % f.size()];
            a[f[i]] = b[p];
        }
        int del = n - y, g = 0;
        for (int i = 0; i < n; ++i) g += a[i] == b[i];
        for (int i = 0; i < n; ++i) {
            if (g > x && a[i] == b[i]) {
                --g, --del, a[i] = no;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i] && a[i] != no && del > 0) {
                --del, a[i] = no;
            }
        }
        for (int i = 0; i < n; ++i) std::cout << a[i] + 1 << " \n"[i == n - 1];
    }
    return 0;
}