#include <bits/stdc++.h>

struct DisjointSetUnion {
    std::vector<int> fa;
    DisjointSetUnion() {}
    DisjointSetUnion(int n) : fa(n, -1) {}
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0) x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) { return find(x) == find(y); }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        fa[y] += fa[x];
        fa[x] = y;
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> x[2];
    std::vector<std::vector<int>> p[2];
    for (int d = 0; d < 2; ++d) {
        x[d].resize(n + 1);
        for (int i = n - 1; i >= 0; --i)
            x[d][i] = (s[i] == '0' + d || s[i] == '?') ? 1 + x[d][i + 1] : 0;
        p[d].resize(n + 1);
        for (int i = 0; i < n; ++i) p[d][x[d][i]].push_back(i);
    }
    DisjointSetUnion dsu[2];
    for (int i = 0; i < 2; ++i) dsu[i] = n + 1;
    for (int k = 1; k <= n; ++k) {
        int ans = 0;
        for (int d = 0; d < 2; ++d)
            for (auto j : p[d][k - 1]) dsu[d].join(j, j + 1);
        for (int i = 0;;) {
            int x = std::min(dsu[0].find(i), dsu[1].find(i));
            if (x == n) break;
            i = x + k;
            ++ans;
        }
        std::cout << ans << " \n"[k == n];
    }
    return 0;
}