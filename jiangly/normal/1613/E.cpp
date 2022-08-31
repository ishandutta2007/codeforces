#include <bits/stdc++.h>

const std::pair<int, int> moves[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int lab = -1;
    
    std::vector<int> deg(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                for (auto [dx, dy] : moves) {
                    int x = i + dx;
                    int y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '#') {
                        deg[i * m + j]++;
                    }
                }
            } else if (s[i][j] == 'L') {
                lab = i * m + j;
            }
        }
    }
    
    deg[lab] = -1;
    std::queue<int> q;
    q.push(lab);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int x = u / m;
        int y = u % m;
        
        if (u != lab) {
            s[x][y] = '+';
        }
        
        for (auto [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '#' && deg[nx * m + ny] != -1) {
                deg[nx * m + ny]--;
                if (deg[nx * m + ny] <= 1) {
                    deg[nx * m + ny] = -1;
                    q.push(nx * m + ny);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << s[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}