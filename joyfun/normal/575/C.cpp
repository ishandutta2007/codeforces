#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 25;
const int INF = 0x3f3f3f3f;

int n, left[N][N], lx[N][N], ly[N][N], G[2][N][N], g[N][N], slack[N], use[N], pre[N];
int now;
int ans;

void km(int u) {
    now = u;
    for (int i = 0; i <= n; i++) {
        left[u][i] = left[u - 1][i];
        lx[u][i] = lx[u - 1][i];
        ly[u][i] = ly[u - 1][i];
        slack[i] = INF;
        use[i] = 0;
    }
    left[u][0] = now;
    int r = 0;
    while (left[u][r]) {
        use[r] = 1;
        int d = INF, v;
        for (int i = 1; i <= n; i++) {
            if (use[i]) continue;
            int tmp = lx[u][left[u][r]] + ly[u][i] - g[left[u][r]][i];
            if (tmp < slack[i]) {slack[i] = tmp; pre[i] = r;}
            if (slack[i] < d) {d = slack[i]; v = i;}
        }
        for (int i = 0; i <= n; i++) {
            if (use[i]) {lx[u][left[u][i]] -= d; ly[u][i] += d;}
            else slack[i] -= d;
        }
        r = v;
    }
    while (r) {
        left[u][r] = left[u][pre[r]];
        r = pre[r];
    }
}

void dfs(int u, int cnt) {
    if (u == n + 1) {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += lx[n][i] + ly[n][i];
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (cnt + i > n / 2 || (u - cnt - i) > n / 2) continue;
        for (int j = 1; j <= n; j++)
            g[u][j] = G[i][u][j];
        km(u);
        dfs(u + 1, cnt + i);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                scanf("%d", &G[i][j][k]);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}