#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string a, b;
        std::cin >> a >> b;
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int pos = (i % 2 == 0) ? i / 2 : n - i / 2 - 1;
            int flip = (i % 2);
            if ((a[pos] ^ flip) == b[n - i - 1]) {
                a[pos] ^= 1;
                ans.push_back(1);
            }
            ans.push_back(n - i);
        }
        std::cout << ans.size() << "\n";
        for (int i = 0; i < int(ans.size()); ++i)
            std::cout << ans[i] << " \n"[i == int(ans.size()) - 1];
    }
    return 0;
}