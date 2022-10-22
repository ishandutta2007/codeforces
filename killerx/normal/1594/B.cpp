#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
    int n, k;
    scanf("%d %d", &n, &k);
    const int mod = 1e9 + 7;
    int ans = 0, e = 1;
    for (int i = 0; i < 30; ++ i) {
        if (k >> i & 1) ans = (ans + e) % mod;
        e = 1LL * e * n % mod;
    }
    printf("%d\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}