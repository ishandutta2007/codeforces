#include <cstdio>
#include <cstring>

const int N = 2005;

int n;
int c1[N], c2[N];

int main() {
    int x, y;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &x, &y);
        c1[x + y]++;
        c2[x - y + 1000]++;
    }
    long long ans = 0;
    for (int i = 0; i < 2000; i++) {
        ans += 1LL * c1[i] * (c1[i] - 1) / 2;
        ans += 1LL * c2[i] * (c2[i] - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}