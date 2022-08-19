#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
            e[a[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
            --b[i];
            e[b[i]].push_back(i);
        }
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if (e[i].size() != 2)
                ok = false;
        if (!ok) {
            std::cout << -1 << "\n";
            continue;
        }
        std::vector<int> vis(n);
        std::vector<int> rev;
        for (int i = 0; i < n; ++i) {
            if (vis[i])
                continue;
            if (e[i][0] == e[i][1])
                continue;
            std::vector<int> x, y;
            for (int j = i, k = e[i][0]; !vis[j]; ) {
                vis[j] = 1;
                k = e[j][0] ^ e[j][1] ^ k;
                if (a[k] == j) {
                    x.push_back(k);
                    j = b[k];
                } else {
                    y.push_back(k);
                    j = a[k];
                }
            }
            if (x.size() < y.size()) {
                rev.insert(rev.end(), x.begin(), x.end());
            } else {
                rev.insert(rev.end(), y.begin(), y.end());
            }
        }
        std::cout << rev.size() << "\n";
        for (auto i : rev)
            std::cout << i + 1 << " \n"[i == rev.back()];
    }
    return 0;
}