#include <cstdio>

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i + 1;
        int r = i + m;
        ans += r / 5 - (l - 1) / 5;
    }
    printf("%lld\n", ans);
    return 0;
}