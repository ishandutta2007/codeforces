#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
    long long n;
    scanf("%lld", &n);
    n *= 2;
    long long s = 1;
    while (n % 2 == 0) s *= 2, n /= 2;
    // l + r == n
    // r - l + 1 == s
    // r = l + s - 1
    // 2l + s - 1 = n
    // n + 1 - s = 2l
    long long l = (n + 1 - s) / 2;
    long long r = l + s - 1;
    printf("%lld %lld\n", l, r);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}