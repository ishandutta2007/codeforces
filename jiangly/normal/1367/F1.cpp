#include <bits/stdc++.h>
constexpr int N = 2e5;
int a[N], p[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int z;
    std::cin >> z;
    while (z--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::iota(p, p + n, 0);
        std::sort(p, p + n, [&](int i, int j) {return a[i] < a[j] || (a[i] == a[j] && i < j);});
        int ans = 0;
        for (int l = 0, r; l < n; l = r) {
            for (r = l + 1; r < n && p[r] > p[r - 1]; ++r)
                ;
            int res = r - l;
            if (l)
                for (int i = l - 1; i >= 0 && a[p[i]] == a[p[l - 1]]; --i)
                    if (p[i] < p[l])
                        ++res;
            if (r < n)
                for (int i = r; i < n && a[p[i]] == a[p[r]]; ++i)
                    if (p[i] > p[r - 1])
                        ++res;
            ans = std::max(ans, res);
        }
        for (int l = 0, m, r; l < n; l = m) {
            for (m = l; m < n && a[p[m]] == a[p[l]]; ++m)
                ;
            if (m == n)
                break;
            for (r = m; r < n && a[p[r]] == a[p[m]]; ++r)
                ;
            for (int i = l, j = m; i < m; ++i) {
                while (j < r && p[j] < p[i])
                    ++j;
                ans = std::max(ans, i + 1 - l + r - j);
            }
        }
        std::cout << n - ans << "\n";
    }
    return 0;
}