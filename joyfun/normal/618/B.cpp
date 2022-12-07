#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55;
int n, g[N][N], vis[N], ans[N];

bool judge(int v, int x) {
    for (int i = 1; i <= n; i++) {
        if (g[v][i] > x) return false;
        if (g[i][v] > x) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (judge(j, i)) {
                ans[j] = i;
                vis[j] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}