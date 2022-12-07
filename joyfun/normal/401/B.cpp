#include <stdio.h>
#include <string.h>

int x, n, vis[4005];

int main() {
    scanf("%d%d", &x, &n);
    int v, d1, d2;
    while (n--) {
        scanf("%d", &v);
        if (v == 1) {
            scanf("%d%d", &d1, &d2);
            vis[d1] = 1; vis[d2] = 1;
        }
        else {
            scanf("%d", &d2);
            vis[d2] = 1;
        }
    }
    vis[0] = 1;
    int ans1 = 0, ans2 = 0, i;
    for (i = 1; i < x; i++)
        if (!vis[i]) ans1++;
    for (i = 1; i < x; i++)
        if (!vis[i] && !vis[i - 1]) {
            ans2++;
            vis[i] = vis[i - 1] = 1;
        }
    for (i = 1; i < x; i++)
        if (!vis[i]) ans2++;
    printf("%d %d\n", ans2, ans1);
    return 0;
}