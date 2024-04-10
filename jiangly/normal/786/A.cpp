#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> dp[2];
    for (int i = 0; i < 2; ++i) {
        dp[i].assign(n, -1);
    }
    
    std::vector<int> s[2];
    for (int i = 0; i < 2; ++i) {
        int k;
        std::cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> s[i][j];
        }
    }
    
    std::vector<int> deg[2];
    for (int i = 0; i < 2; ++i) {
        deg[i].assign(n, s[i].size());
    }
    
    std::queue<int> que;
    dp[0][0] = dp[1][0] = 0;
    que.push(0);
    que.push(n);
    while (!que.empty()) {
        int t = que.front() / n;
        int u = que.front() % n;
        que.pop();
        for (auto x : s[!t]) {
            int v = (u - x + n) % n;
            if (dp[!t][v] != -1) {
                continue;
            }
            if (dp[t][u] == 0) {
                dp[!t][v] = 1;
                que.push((!t) * n + v);
            } else if (--deg[!t][v] == 0) {
                dp[!t][v] = 0;
                que.push((!t) * n + v);
            }
        }
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < n; ++j) {
            if (dp[i][j] == 1) {
                std::cout << "Win";
            } else if (dp[i][j] == 0) {
                std::cout << "Lose";
            } else {
                std::cout << "Loop";
            }
            std::cout << " \n"[j == n - 1];
        }
    }
    
    return 0;
}