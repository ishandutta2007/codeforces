#include <bits/stdc++.h>

using i64 = long long;

const std::pair<int, int> moves[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::string s[n];
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::vector<int> adj[n * m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                std::vector<int> v;
                for (auto [dx, dy] : moves) {
                    int x = i + dx;
                    int y = j + dy;
                    if (s[x][y] == '.') {
                        v.push_back(x * m + y);
                    }
                }
                if (v.size() % 2 != 0) {
                    std::cout << "NO\n";
                    return 0;
                }
                for (int k = 0; k < int(v.size()); k += 2) {
                    adj[v[k]].push_back(v[k + 1]);
                    adj[v[k + 1]].push_back(v[k]);
                }
            }
        }
    }
    
    std::queue<int> que;
    int res[n][m] = {};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] > 0 || s[i][j] == 'X') {
                continue;
            }
            res[i][j] = 1;
            que.push(i * m + j);
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (auto v : adj[u]) {
                    if (res[v / m][v % m] == 0) {
                        res[v / m][v % m] = res[u / m][u % m] ^ 5;
                        que.push(v);
                    }
                }
            }
        }
    }
    
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                for (auto [dx, dy] : moves) {
                    int x = i + dx;
                    int y = j + dy;
                    if (s[x][y] == '.') {
                        res[i][j] += res[x][y];
                    }
                }
            }
            std::cout << res[i][j] << " \n"[j == m - 1];
        }
    }
    
    return 0;
}