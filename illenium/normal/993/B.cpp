#include <bits/stdc++.h>
using namespace std;

int n, m, a[20][2], b[20][2];

inline int common(int x, int y)
{
    int cnt = 0, ans;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a[x][i] == b[y][j]) ++cnt, ans = a[x][i];
    return cnt == 1 ? ans : 0;
}

inline void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i][0], &a[i][1]);
    for (int i = 1; i <= m; i++) scanf("%d%d", &b[i][0], &b[i][1]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int x;
            if (!(x = common(i, j))) continue;
            for (int k = 1; k <= m; k++)
                if (common(i, k) && common(i, k) != x) {puts("-1"); return; }
            for (int k = 1; k <= n; k++)
                if (common(k, j) && common(k, j) != x) {puts("-1"); return; }
            if (!ans) ans = x;
            else if (x != ans) {puts("0"); return; }
        }
    printf("%d\n", ans);
}

int main() {work(); return 0; }