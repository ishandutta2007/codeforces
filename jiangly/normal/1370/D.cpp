#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int l = 1, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        bool ok = false;
        for (int d = 0; d < 2; ++d) {
            int len = 0;
            for (int i = 0; i < n; ++i)
                if (len % 2 != d || a[i] <= m)
                    ++len;
            if (len >= k)
                ok = true;
        }
        if (ok) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    std::cout << l << "\n";
    return 0;
}