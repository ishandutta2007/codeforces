#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 300005;

int n, m, dp[2][N];

struct Edge {
    int u, v, w;
} e[N];

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e, e + m, cmp);
    for (int i = 0; i < m; i++) {
        int j;
        for (j = i; e[i].w == e[j].w; j++)
            dp[1][e[j].v] = max(dp[1][e[j].v], dp[0][e[j].u] + 1);
        for (j = i; e[i].w == e[j].w; j++)
            dp[0][e[j].v] = dp[1][e[j].v];
        i = j - 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[0][i]);
    printf("%d\n", ans);
    //system("pause");
    return 0;
}