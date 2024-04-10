#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        for (auto c : s[i]) {
            if (std::islower(c)) {
                a[i].push_back(c - 'a');
            } else {
                a[i].push_back(c - 'A' + 26);
            }
        }
    }
    
    std::vector<std::vector<std::vector<int>>> next(n);
    for (int i = 0; i < n; i++) {
        next[i].resize(s[i].length() + 1, std::vector(52, -1));
        for (int j = s[i].length() - 1; j >= 0; j--) {
            next[i][j] = next[i][j + 1];
            next[i][j][a[i][j]] = j;
        }
    }
    
    std::vector<std::vector<int>> id(n);
    std::vector<std::vector<std::vector<int>>> pos(n, std::vector<std::vector<int>>(52));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < int(a[i].size()); j++) {
            id[i].push_back(pos[i][a[i][j]].size());
            pos[i][a[i][j]].push_back(j);
        }
    }
    
    std::vector<std::pair<int, int>> states;
    for (int c = 0; c < 52; c++) {
        for (int s = 0; s < (1 << n); s++) {
            bool nice = true;
            for (int i = 0; i < n; i++) {
                if ((s >> i & 1) >= int(pos[i][c].size())) {
                    nice = false;
                }
            }
            if (!nice) {
                continue;
            }
            
            states.emplace_back(c, s);
        }
    }
    
    int N = states.size();
    std::sort(states.begin(), states.end(), [&](auto a, auto b) {
        for (int i = 0; i < n; i++) {
            int pa = pos[i][a.first][a.second >> i & 1];
            int pb = pos[i][b.first][b.second >> i & 1];
            if (pa != pb) {
                return pa < pb;
            }
        }
        return false;
    });
    
    std::vector index(52, std::vector<int>(1 << n));
    for (int i = 0; i < N; i++) {
        index[states[i].first][states[i].second] = i;
    }
    
    std::vector<int> dp(N, 1), g(N, -1);
    
    int res = 0;
    int k = -1;
    for (int i = 0; i < N; i++) {
        for (int c = 0; c < 52; c++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                int cur = pos[j][states[i].first][states[i].second >> j & 1];
                int np = next[j][cur + 1][c];
                if (np == -1) {
                    mask = -1;
                    break;
                }
                mask |= id[j][np] << j;
            }
            if (mask == -1) {
                continue;
            }
            int p = index[c][mask];
            if (dp[i] + 1 > dp[p]) {
                dp[p] = dp[i] + 1;
                g[p] = i;
            }
        }
        
        if (dp[i] > res) {
            res = dp[i];
            k = i;
        }
    }
    
    std::string str;
    while (k != -1) {
        int c = states[k].first;
        str += c < 26 ? 'a' + c : 'A' + c - 26;
        k = g[k];
    }
    
    std::reverse(str.begin(), str.end());
    std::cout << res << "\n";
    std::cout << str << "\n";
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