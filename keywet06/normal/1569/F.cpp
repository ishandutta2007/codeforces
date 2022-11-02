#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    
    bool adj[12][12] = {};
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u][v] = adj[v][u] = true;
    }
    
    int64 pw[n + 1];
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * n;
    }
    std::vector<int64> answer;
    int N = n / 2;
    int u[N], v[N];
    
    std::function<void(int, int, int64)> dfs1 = [&](int s, int x, int64 mask) {
        if (s == 0) {
            answer.push_back(mask);
            return;
        }
        int a = __builtin_ctz(s);
        s &= s - 1;
        mask += x * (pw[u[a]] + pw[v[a]]);
        for (int t = s; ; t = (t - 1) & s) {
            int64 nmask = mask;
            for (int i = 0; i < N; i++) {
                if (t >> i & 1) {
                    nmask += x * (pw[u[i]] + pw[v[i]]);
                }
            }
            dfs1(s & ~t, x + 1, nmask);
            if (t == 0) {
                break;
            }
        }
    };
    
    std::function<void(int, int)> dfs = [&](int s, int x) {
        if (x == N) {
            
            bool dp[1 << N][N] = {};
            for (int i = 0; i < N; i++) {
                dp[1 << i][i] = true;
            }
            
            for (int s = 1; s < (1 << N); s++) {
                for (int i = 0; i < N; i++) {
                    if (~s >> i & 1) {
                        continue;
                    }
                    if (!dp[s][i]) {
                        continue;
                    }
                    for (int j = 0; j < N; j++) {
                        if (s >> j & 1) {
                            continue;
                        }
                        if ((adj[u[i]][u[j]] && adj[v[i]][v[j]]) || (adj[u[i]][v[j]] && adj[v[i]][u[j]])) {
                            dp[s | (1 << j)][j] = true;
                        }
                    }
                }
            }
            
            bool res = false;
            for (int i = 0; i < N; i++) {
                res |= adj[u[i]][v[i]] && dp[(1 << N) - 1][i];
            }
            
            if (res) {
                dfs1((1 << N) - 1, 0, 0);
            }
            
            return;
        }
        
        u[x] = __builtin_ctz(s);
        s &= (s - 1);
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                v[x] = i;
                dfs(s ^ (1 << i), x + 1);
            }
        }
    };
    dfs((1 << n) - 1, 0);
    
    int64 res = 0;
    std::sort(answer.begin(), answer.end());
    answer.erase(std::unique(answer.begin(), answer.end()), answer.end());
    
    int64 f[N + 1];
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = f[i - 1] * (k - i + 1);
    }
    
    for (auto p : answer) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = std::max(mx, int(p / pw[i] % n) + 1);
        }
        res += f[mx];
    }
    
    std::cout << res << "\n";
    
    return 0;
}