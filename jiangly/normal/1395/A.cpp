#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a[4];
        for (int i = 0; i < 4; ++i)
            std::cin >> a[i];
        int s = 0;
        for (int i = 0; i < 4; ++i)
            s += a[i] % 2;
        if (s <= 1) {
            std::cout << "Yes\n";
            continue;
        }
        s = 0;
        for (int i = 0; i < 4; ++i) {
            if (i < 3) {
                --a[i];
            } else {
                ++a[i];
            }
            if (a[i] < 0)
                s += 100;
            s += a[i] % 2;
        }
        if (s <= 1) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}