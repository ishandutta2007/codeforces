#include <stdio.h>
#include <string.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define INF 0x3f3f3f3f
int n, a[5005];

int dfs(int l, int r, int now) {
    if (l == r) return 0;
    int i, Min = INF;
    for (i = l; i < r; i++)
        Min = min(Min, a[i]);
    int ans = Min - now, L = l;
    for (i = l; i < r; i++) {
        if (a[i] == Min) {
            ans += dfs(L, i, Min);
            L = i + 1;
        }
    }
    ans += dfs(L, r, Min);
    return min(r - l, ans);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", dfs(0, n, 0));
    return 0;
}