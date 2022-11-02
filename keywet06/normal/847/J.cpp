#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

bool vis[N];

int ans, n, m, x, y;

vector<int> a[N];

bool dfs(int x, int y) {
    if (vis[x]) return 0;
    if (vis[x] = 1, a[x].size() < ans) return a[x].push_back(y), 1;
    for (auto &u : a[x]) {
        if (dfs(u, x)) return u = y, 1;
    }
    return 0;
}

bool solve(int x, int y) { return memset(vis, 0, sizeof(vis)), dfs(x, y); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        if (!solve(x, y) && !solve(y, x)) ++ans, solve(x, y) || solve(y, x);
    }
    std::cout << ans << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int x : a[i]) std::cout << i << ' ' << x << '\n';
    }
    return 0;
}