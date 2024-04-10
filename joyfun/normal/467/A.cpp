#include <cstdio>

int main() {
    int n, p, q;
    int ans = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &p, &q);
        if (q - p >= 2) ans++;
    }
    printf("%d\n", ans);
    return 0;
}