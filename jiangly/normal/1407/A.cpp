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
        if (std::count(a.begin(), a.end(), 1) % 2 == 1)
            a.erase(std::find(a.begin(), a.end(), 1));
        for (int i = 0, j = -1; i < int(a.size()); ++i) {
            if (a[i] == 1) {
                if (j != -1 && (i - j) % 2 == 0) {
                    a.erase(a.begin() + j + 1);
                    --i;
                }
                j = i;
            }
        }
        std::cout << a.size() << "\n";
        for (int i = 0; i < int(a.size()); ++i)
            std::cout << a[i] << " \n"[i == int(a.size()) - 1];
    }
    return 0;
}