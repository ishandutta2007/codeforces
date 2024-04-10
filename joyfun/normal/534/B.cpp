#include <cstdio>
#include <cstring>

int v1, v2, t, d;

int main() {
    scanf("%d%d%d%d", &v1, &v2, &t, &d);
    int ans = v1;
    for (int i = 2; i <= t; i++) {
        if (v1 + d - (t - i) * d > v2) {
            v1 = (t - i) * d + v2;
            ans += v1;
            for (int j = 0; j < (t - i); j++) {
                v1 -= d;
                ans += v1;
            }
            break;
        }
        v1 += d;
        ans += v1;
    }
    printf("%d\n", ans);
    return 0;
}