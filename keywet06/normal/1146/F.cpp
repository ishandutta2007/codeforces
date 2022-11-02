#include <bits/stdc++.h>

const int N = 200005;
const int M = N << 1;

struct Edge {
    int to, next;
} e[M];

int head[N], top;

void add(int u, int v) {
    e[top].to = v;
    e[top].next = head[u];
    head[u] = top++;
}

const long long P = 998244353;

long long dp[N][3];

void dfs(int x) {
    bool flag = 1;
    dp[x][0] = 1;
    int i;
    for (i = head[x]; ~i; i = e[i].next) {
        flag = 0;
        dfs(e[i].to);
        dp[x][2] = (dp[x][1] * (dp[e[i].to][1] + dp[e[i].to][2]) +
                    dp[x][2] * (dp[e[i].to][0] + dp[e[i].to][1] + (dp[e[i].to][2] << 1))) %
                   P;
        dp[x][1] = (dp[x][0] * (dp[e[i].to][1] + dp[e[i].to][2]) + dp[x][1] * (dp[e[i].to][0] + dp[e[i].to][2])) % P;
        dp[x][0] = dp[x][0] * (dp[e[i].to][0] + dp[e[i].to][2]) % P;
    }
    if (flag) dp[x][0] = 0, dp[x][2] = 1;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    memset(head, 255, sizeof(head));
    int n;
    std::cin >> n;
    for (int i = 2, x; i <= n; ++i) std::cin >> x, add(x, i);
    dfs(1);
    std::cout << (dp[1][0] + dp[1][2]) % P << std::endl;
    return 0;
}