#include <bits/stdc++.h>

constexpr std::pair<int, int> moves[] { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    
    std::vector<int> belong(n * n, -1), siz(n * n);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (s[x][y] == '.' && belong[x * n + y] == -1) {
                std::queue<int> que;
                que.push(x * n + y);
                belong[x * n + y] = x * n + y;
                while (!que.empty()) {
                    int u = que.front();
                    que.pop();
                    ++siz[belong[u]];
                    int x = u / n, y = u % n;
                    for (auto [dx, dy] : moves) {
                        int x1 = x + dx;
                        int y1 = y + dy;
                        int v = x1 * n + y1;
                        if (0 <= x1 && x1 < n && 0 <= y1 && y1 < n && s[x1][y1] == '.' && belong[v] == -1) {
                            belong[v] = belong[u];
                            que.push(v);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    std::vector<bool> vis(n * n);
    for (int x = 0; x <= n - k; ++x) {
        for (int i = x; i < x + k; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                if (belong[i * n + j] != -1) {
                    --siz[belong[i * n + j]];
                }
            }
        }
        for (int y = 0; y <= n - k; ++y) {
            for (int i = x; i < x + k; ++i) {
                if (belong[i * n + y + k - 1] != -1) {
                    --siz[belong[i * n + y + k - 1]];
                }
            }
            int res = k * k;
            std::vector<int> u;
            if (x > 0) {
                for (int i = y; i < y + k; ++i) {
                    u.push_back((x - 1) * n + i);
                }
            }
            if (x + k < n) {
                for (int i = y; i < y + k; ++i) {
                    u.push_back((x + k) * n + i);
                }
            }
            if (y > 0) {
                for (int i = x; i < x + k; ++i) {
                    u.push_back(i * n + y - 1);
                }
            }
            if (y + k < n) {
                for (int i = x; i < x + k; ++i) {
                    u.push_back(i * n + y + k);
                }
            }
            for (auto v : u) {
                if (belong[v] != -1 && !vis[belong[v]]) {
                    res += siz[belong[v]];
                    vis[belong[v]] = true;
                }
            }
            for (auto v : u) {
                if (belong[v] != -1) {
                    vis[belong[v]] = false;
                }
            }
            ans = std::max(ans, res);
            for (int i = x; i < x + k; ++i) {
                if (belong[i * n + y] != -1) {
                    ++siz[belong[i * n + y]];
                }
            }
        }
        for (int i = x; i < x + k; ++i) {
            for (int j = n - k + 1; j < n; ++j) {
                if (belong[i * n + j] != -1) {
                    ++siz[belong[i * n + j]];
                }
            }
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}