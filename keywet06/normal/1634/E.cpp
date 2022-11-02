#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m;
    std::cin >> m;
    std::vector<std::vector<int>> a(m);
    std::vector<int> v;
    for (int i = 0; i < m; ++i) {
        int n;
        std::cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; ++j) std::cin >> a[i][j], v.push_back(a[i][j]);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    int nv = v.size();
    std::vector<std::string> ans(m);
    std::vector<std::vector<std::pair<int, int>>> pos(nv);
    for (int i = 0; i < m; ++i) {
        int n = a[i].size();
        ans[i].resize(n, '?');
        for (int j = 0; j < n; ++j) {
            a[i][j] = std::lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
            pos[a[i][j]].emplace_back(i, j);
        }
    }
    for (int i = 0; i < nv; ++i) {
        if (int(pos[i].size()) % 2 != 0) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::vector<int> cur(m), curv(nv);
    for (int i = 0; i < m; ++i) {
        int n = a[i].size();
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] != '?') {
                continue;
            }
            int x = i, y = j;

            while (true) {
                ans[x][y] = 'L';
                while (ans[x][cur[x]] != '?') ++cur[x];
                ans[x][cur[x]] = 'R';
                int v = a[x][cur[x]];
                if (v == a[i][j]) break;
                while (ans[pos[v][curv[v]].first][pos[v][curv[v]].second] != '?') ++curv[v];
                std::tie(x, y) = pos[v][curv[v]];
            }
        }
    }
    std::cout << "YES\n";
    for (int i = 0; i < m; ++i) std::cout << ans[i] << "\n";
    return 0;
}