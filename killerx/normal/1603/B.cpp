#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x <= y) {
        int k = (y + x) / x - 1;
        long long n = (1LL * k * x + y) / 2;
        assert(n % x == y % n);
        printf("%lld\n", n);
    } else printf("%d\n", x + y);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}