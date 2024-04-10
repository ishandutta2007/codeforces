#include <bits/stdc++.h>

const int N = 1002;

struct Node {
    int next[14];
    int link;
} t[N];

int cntNodes;
int val[N];

std::vector<int> e[N];

void init() {
    cntNodes = 2;
    for (int i = 0; i < 14; ++i) t[0].next[i] = 1;
}

void build() {
    std::queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int p = que.front();
        e[t[p].link].push_back(p);
        que.pop();
        for (int i = 0; i < 14; ++i) {
            if (t[p].next[i] != 0) {
                t[t[p].next[i]].link = t[t[p].link].next[i];
                que.push(t[p].next[i]);
            } else {
                t[p].next[i] = t[t[p].link].next[i];
            }
        }
    }
}

void dfs(int u) {
    for (int v : e[u]) {
        val[v] += val[u];
        dfs(v);
    }
}

int v[N];

long long f[N], dp[1 << 14][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::string s;
        std::cin >> s;
        int p = 1;
        for (char c : s) {
            if (t[p].next[c - 'a'] == 0) t[p].next[c - 'a'] = cntNodes++;
            p = t[p].next[c - 'a'];
        }
        int c;
        std::cin >> c;
        val[p] += c;
    }
    build();
    dfs(1);
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (int i = 0; i < (1 << 14); ++i) {
        std::fill(dp[i], dp[i] + cntNodes,
                  std::numeric_limits<long long>::min());
    }
    std::iota(v, v + cntNodes, 0);
    dp[0][1] = 0;
    for (char c : s) {
        if (c == '?') {
            for (int a = 0; a < (1 << 14); ++a) {
                if (__builtin_popcount(a) == cnt) {
                    for (int u = 1; u < cntNodes; ++u) {
                        if (dp[a][u] != std::numeric_limits<long long>::min()) {
                            for (int i = 0; i < 14; ++i) {
                                if (~a >> i & 1) {
                                    int x = t[v[u]].next[i];
                                    dp[a | 1 << i][x] =
                                        std::max(dp[a | 1 << i][x],
                                                 dp[a][u] + f[u] + val[x]);
                                }
                            }
                        }
                    }
                }
            }
            ++cnt;
            std::iota(v, v + cntNodes, 0);
            std::fill(f, f + cntNodes, 0);
        } else {
            for (int i = 1; i < cntNodes; ++i) {
                v[i] = t[v[i]].next[c - 'a'];
                f[i] += val[v[i]];
            }
        }
    }
    long long ans = std::numeric_limits<long long>::min();
    for (int a = 0; a < (1 << 14); ++a) {
        if (__builtin_popcount(a) == cnt) {
            for (int u = 1; u < cntNodes; ++u) {
                if (dp[a][u] != std::numeric_limits<long long>::min()) {
                    ans = std::max(ans, dp[a][u] + f[u]);
                }
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}