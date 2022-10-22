#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef unsigned long long u64;

u64 calc(u64 n) {
    u64 ans = 0;
    u64 e, c;
    for (e = 1, c = 1; e * 10 <= n; e *= 10, ++ c) {
        u64 l = n - (e * 10 - 1) + 1, r = n - e + 1;
        ans += ((l + r) * (r - l + 1) / 2) * c;
    }
    u64 l = n - n + 1, r = n - e + 1;
    ans += ((l + r) * (r - l + 1) / 2) * c;
    return ans;
}

u64 calc0(u64 n) {
    u64 ans = 0;
    u64 e, c;
    for (e = 1, c = 1; e * 10 <= n; e *= 10, ++ c) ans += e * 9 * c;
    ans += (n - e + 1) * c;
    return ans;
}

void Main() {
    u64 K;
    scanf("%llu", &K);
    int lb = 1, rb = 1e9;
    while (lb < rb) {
        int md = (lb + rb + 1) >> 1;
        if (calc(md) <= K) lb = md;
        else rb = md - 1;
    }
    int n = lb;
    if (calc(n) == K) {
        printf("%d\n", n % 10);
        return ;
    }
    K -= calc(n);
    ++ n;
    lb = 1, rb = n;
    while (lb < rb) {
        int md = (lb + rb + 1) >> 1;
        if (calc0(md) <= K) lb = md;
        else rb = md - 1;
    }
    int x = lb;
    if (calc0(x) == K) {
        printf("%d\n", x % 10);
        return ;
    }
    K -= calc0(x);
    ++ x;
    std::stringstream ss; ss << x;
    std::string s = ss.str();
    printf("%d\n", s[K - 1] - '0');
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
	return 0;
}