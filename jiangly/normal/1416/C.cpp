#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int64_t cnt = 0;
    int x = 0;
    for (int d = 1; d <= 30; ++d) {
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int i, int j) { return (a[i] >> d) < (a[j] >> d) || ((a[i] >> d) == (a[j] >> d) && i < j); });
        int64_t c0 = 0, c1 = 0;
        for (int i = 0, j; i < n; i = j) {
            for (j = i; j < n && (a[p[i]] >> d) == (a[p[j]] >> d); ++j)
                ;
            int x0 = 0, x1 = 0;
            for (int k = i; k < j; ++k) {
                if (a[p[k]] >> (d - 1) & 1) {
                    c0 += x0;
                    ++x1;
                } else {
                    c1 += x1;
                    ++x0;
                }
            }
        }
        if (c0 < c1) {
            std::swap(c0, c1);
            x ^= (1 << (d - 1));
        }
        cnt += c1;
    }
    std::cout << cnt << " " << x << "\n";
    return 0;
}