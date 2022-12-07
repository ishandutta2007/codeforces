#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 100005;

int n, num, vis[5005], Max, ans;

void init() {
    ans = 0;
    scanf("%d", &n); Max = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        Max = max(Max, num);
        vis[num]++;
    }
}

void solve() {
    int i, flag = 0, res[N], resn = 0;
    if (vis[Max] >= 2) flag = 1;
    for (i = 0; i <= Max; i++) {
        if (vis[i] >= 2) {
            vis[i]--;
            ans++;
            res[resn++] = i;
        }
    }
    if (flag) Max--;
    for (i = Max; i >= 0; i--) {
        if (vis[i] >= 1) {
            vis[i]--;
            ans++;
            res[resn++] = i;
            
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < resn - 1; i++)
        printf("%d ", res[i]);
    printf("%d\n", res[resn - 1]);
}

int main() {
    init();
    solve();
    return 0;
}