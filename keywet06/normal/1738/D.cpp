#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, s = 0, x;
        std::cin >> n;
        std::vector<int> a(n + 1);
        std::vector<std::vector<int> > To(n + 2);
        for (int i = 1; i <= n; ++i) std::cin >> x, To[x].push_back(i);
        for (int c = 1, i = To[0].size() ? 0 : n + 1, o = !!i, j = -1; ~i; c += To[i].size(), i = j, j = -1, o = !o) {
            for (int k = 0; k < To[i].size(); ++k) a[c + k] = To[i][k], s += o;
            for (int k = 0; k < To[i].size(); ++k) {
                if (To[To[i][k]].size()) j = To[i][k], std::swap(a[c + k], a[c + To[i].size() - 1]);
            }
        }
        std::cout << s << '\n';
        for (int i = 1; i <= n; ++i) std::cout << a[i] << " \n"[i == n];
    }
    return 0;
}