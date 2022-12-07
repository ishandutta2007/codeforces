#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;

int n, m;
int g[N][N];
int col[N];

int cnt;

bool dfs(int u, int c) {
    if (col[u] != -1) return col[u] == c;
    col[u] = c;
    cnt++;
    for (int i = 1; i <= n; i++) {
        if (i == u) continue;
        if (g[u][i]) {
            if (!dfs(i, !c)) return false;
        }
    }
    return true;
}

bool judge() {
    int tot = 0;
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            cnt = 0;
            if (dfs(i, 0) == 0) return false;
            if (cnt > 1) tot++;
            else if (cnt == 1) {
                col[i] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 2) continue;
        for (int j = i + 1; j <= n; j++) {
            if (col[j] == 2) continue;
            if (col[i] != col[j] && g[i][j] == 0) return false;
        }
    }
    return tot <= 1;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            g[i][j] = 1;
    }
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 0;
    }
    if (judge()) {
        printf("Yes\n");
        for (int i = 1; i <= n; i++) {
            if (col[i] == 0) printf("a");
            else if (col[i] == 1) printf("c");
            else printf("b");
        }
        printf("\n");
    } else printf("No\n");
    return 0;
}