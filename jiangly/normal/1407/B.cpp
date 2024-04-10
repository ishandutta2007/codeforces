#include <bits/stdc++.h>
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
        int cur = 0;
        while (!a.empty()) {
            int mx = 0, j = -1;
            for (int i = 0; i < int(a.size()); ++i) {
                int x = std::gcd(a[i], cur);
                if (x > mx) {
                    mx = x;
                    j = i;
                }
            }
            cur = mx;
            std::cout << a[j] << " \n"[a.size() == 1];
            a.erase(a.begin() + j);
        }
    }
    return 0;
}