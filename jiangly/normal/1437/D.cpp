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
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int h = 0;
        int res = 0, cnt = 1;
        int lst = 1;
        auto add = [&](int len) {
            if (res == 0) {
                res = cnt;
                cnt = 0;
                h++;
            }
            --res;
            cnt += len;
        };
        for (int i = 2; i < n; ++i) {
            if (a[i - 1] > a[i]) {
                add(i - lst);
                lst = i;
            }
        }
        add(n - lst);
        std::cout << h << "\n";
    }
    
    return 0;
}