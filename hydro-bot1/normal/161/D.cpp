// Hydro submission #62e49b67c03957ab19855dc8@1659149159807
#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;
const int N = 5e4 + 10;
const int K = 505;
int n, k, cnt;
int dp[N][K], head[N];
long long ans = 0;

struct edge{
    int to, nxt;
}e[N << 1];

inline void add(int u, int v){
    e[++cnt] = {v, head[u]};
    head[u] = cnt;
}

inline void dfs(int u, int fa){
    dp[u][0] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 0; j < k; ++j) {
            ans += dp[u][j] * dp[v][k - j - 1];
        }
        for (int j = 1; j <= k; ++j) {
            dp[u][j] += dp[v][j - 1];
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, x, y; i <= n - 1; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, -1);
    printf("%lld\n", ans);
    return 0;
}