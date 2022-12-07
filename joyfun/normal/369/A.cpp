#include <stdio.h>
#include <string.h>

int main() {
    int n, m, k, i, a = 0, b = 0, ans = 0;
    int aa[1005];
    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i < n; i ++) {
        scanf("%d", &aa[i]);
        if (aa[i] == 1)
            a ++;
        if (aa[i] == 2)
            b ++;
    }
        if (a > m) {
            ans += a - m;
            m = 0;
        }
        else {
            m = m - a;
        }
        if (b > k + m) {
            ans += b - k - m;
        }
    printf("%d\n", ans);
    return 0;
}