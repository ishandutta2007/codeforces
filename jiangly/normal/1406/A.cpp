#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int cnt[102] = {};
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            ++cnt[x];
        }
        int a = 0;
        while (cnt[a] >= 2)
            ++a;
        int b = a;
        while (cnt[b] >= 1)
            ++b;
        std::cout << a + b << "\n";
    }
    return 0;
}