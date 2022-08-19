#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> h(n);
        for (int i = 0; i < n; i++) {
            std::cin >> h[i];
        }
        std::sort(h.begin(), h.end());
        if (n == 2) {
            std::cout << h[0] << " " << h[1] << "\n";
            continue;
        }
        int x = 1;
        for (int i = 2; i < n; i++) {
            if (h[i] - h[i - 1] < h[x] - h[x - 1]) {
                x = i;
            }
        }
        for (int i = x; i < n; i++) {
            std::cout << h[i] << " ";
        }
        for (int i = 0; i < x; i++) {
            std::cout << h[i] << " \n"[i == x - 1];
        }
    }
    return 0;
}