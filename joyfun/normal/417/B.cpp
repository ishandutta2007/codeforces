#include <stdio.h>
#include <string.h>

const int N = 100005;
int n, vis[N];
struct Solu {
    int x, k;
} s[N];

bool judge() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        int x = s[i].x, k = s[i].k;
        if (x == vis[k])
            vis[k]++;
        else if (x > vis[k])
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &s[i].x, &s[i].k);
    if (judge()) printf("YES\n");
    else printf("NO\n");
    return 0;
}