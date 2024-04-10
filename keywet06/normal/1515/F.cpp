#include <algorithm>
#include <cstdio>
#include <vector>

const int MAXV = 300005;
const int MAXE = 300005;

int N, M, X;
long long as[MAXV];

int elist[MAXE * 2];
int head[MAXV];
int prev[MAXE * 2];
int tot = 0;

bool vis[MAXV];

int ans[MAXV];
int front, back;

void dfs(int u) {
    vis[u] = true;
    for (int e = head[u]; e != -1; e = prev[e]) {
        int v = elist[e ^ 1];
        if (vis[v]) continue;
        dfs(v);
        if (as[u] + as[v] >= X) {
            as[u] += as[v] - X;
            ans[front++] = e >> 1;
        } else {
            ans[--back] = e >> 1;
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &X);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &as[i]);
        total += as[i];
    }
    if (total < 1LL * (N - 1) * X) {
        printf("NO\n");
        return 0;
    }
    std::fill(head, head + N, -1);
    for (int i = 0; i < M * 2; i++) {
        int U;
        scanf("%d", &U);
        U--;
        prev[i] = head[U];
        head[U] = i;
        elist[i] = U;
    }
    back = N - 1;
    dfs(0);
    printf("YES\n");
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", ans[i] + 1);
    }
}