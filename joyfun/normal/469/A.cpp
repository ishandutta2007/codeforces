#include <cstdio>
#include <cstring>

int n, p, q, vis[105];

bool solve() {
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    scanf("%d", &p);
    int tmp;
    for (int i = 0; i < p; i++) {
        scanf("%d", &tmp);
        vis[tmp] = 1;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &tmp);
        vis[tmp] = 1;
    }
    printf("%s\n", solve() ? "I become the guy." : "Oh, my keyboard!");
    return 0;
}