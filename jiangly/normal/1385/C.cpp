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
        int x = n - 1;
        while (x && a[x - 1] >= a[x])
            --x;
        while (x && a[x - 1] <= a[x])
            --x;
        std::cout << x << "\n";
    }
    return 0;
}