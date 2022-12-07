#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;

int n, k[N], s;
vector<int> g[N];
long long dp[N];

void dfs(int u, int p) {
    priority_queue<long long> Q;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        Q.push(dp[v]);
    }
    if (u != s) dp[u] = 1;
    while (k[u] && !Q.empty()) {
        dp[u] += Q.top() + 1;
        k[u]--;
        Q.pop();
    }
     for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        int Min = min(k[u], k[v]);
        k[u] -= Min, k[v] -= Min;
        dp[u] += Min * 2;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        k[i]--;
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d", &s);
    k[s]++;
    dfs(s, s);
    printf("%lld\n", dp[s]);
    return 0;
}