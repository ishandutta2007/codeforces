#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
struct DSU {
    std::vector<int> fa;
    std::vector<std::vector<int>> cnt;
    void init(int n) {
        fa.assign(n, -1);
        cnt.assign(n, std::vector<int>(26));
    }
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0)
            x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (fa[x] > fa[y])
            std::swap(x, y);
        fa[x] += fa[y];
        for (int i = 0; i < 26; ++i)
            cnt[x][i] += cnt[y][i];
        fa[y] = x;
        return true;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        DSU t;
        t.init(n);
        for (int i = 0; i < n; ++i)
            t.cnt[i][s[i] - 'a'] = 1;
        for (int i = 0; i < n; ++i)
            t.merge(i, n - i - 1);
        for (int i = 0; i < n - k; ++i)
            t.merge(i, i + k);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (t.find(i) == i)
                ans += std::accumulate(t.cnt[i].begin(), t.cnt[i].end(), 0) - *std::max_element(t.cnt[i].begin(), t.cnt[i].end());
        std::cout << ans << "\n";
    }
    return 0;
}