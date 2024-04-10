// Luogu Remote

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }
    auto Check = [&](int a, int b, int c, int d) -> bool {
        int x = a | b | c | d;
        return x && !(a && a != x || b && b != x || c && c != x || d && d != x);
    };
    auto Vert = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x + 1 < n && y + 1 < m && Check(a[x][y], a[x][y + 1], a[x + 1][y], a[x + 1][y + 1]);
    };
    std::queue<std::pair<int, int> > Que;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (Vert(i, j)) Que.emplace(i, j);
        }
    }
    std::stack<std::tuple<int, int, int> > Ans;
    while (!Que.empty()) {
        auto [x, y] = Que.front();
        Que.pop();
        int c = a[x][y] | a[x][y + 1] | a[x + 1][y] | a[x + 1][y + 1];
        if (!c) continue;
        Ans.emplace(x, y, c);
        a[x][y] = a[x][y + 1] = a[x + 1][y] = a[x + 1][y + 1] = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (Vert(x + i, y + j)) Que.emplace(x + i, y + j);
            }
        }
    }
    int x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) x |= a[i][j];
    }
    if (x) return std::cout << -1 << '\n', 0;
    std::cout << Ans.size() << '\n';
    while (!Ans.empty()) {
        auto [x, y, c] = Ans.top();
        Ans.pop();
        std::cout << x + 1 << ' ' << y + 1 << ' ' << c << '\n';
    }
    return 0;
}