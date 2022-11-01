#include <bits/stdc++.h>

long long tab[1000007];
#define int long long

std::pair<std::pair<int, int>, int> reuc(int a, int b) {
    int x = 1, y = 0, r = 0, s = 1;
    while (b != 0) {
        int c = a % b, q = a / b;
        a = b;
        b = c;

        int rp = r, sp = s;
        r = x - q * r;
        s = y - q * s;
        x = rp;
        y = sp;
    }
    return {{x, y}, a};
}

int32_t main() {
    int n;
    scanf("%lld", &n);
    long long sa = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        sa += a;
        tab[i] = b - a;
    }
    std::sort(tab + 1, tab + n + 1);
//    printf("DEBUG SA=%lld\n", sa);
//    printf("DEBUG ");
//    for (int i = 1; i <= n; i++) {
//        printf("%lld ", tab[i]);
//    }
    printf("\n");
    std::pair<long long, int> maxpoint;
    for (int i = n; i >= 1; i--) {
        tab[i] += tab[i + 1];
        maxpoint = std::max(maxpoint, {tab[i], i});
    }
//    printf("DEBUG ");
//    for (int i = 1; i <= n; i++) {
//        printf("%lld ", tab[i]);
//    }
//    printf("\n");
    long long aimfor = maxpoint.second - 1;
    int m;
    scanf("%lld", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        auto P = reuc(a, b);
        int x = P.first.first, y = P.first.second, d = P.second;
        if (n % d != 0) {
//            printf("DEBUG %lld nie dzieli %lld\n", d, n);
            printf("-1\n");
            continue;
        }
        int bp = b / d;
        long long k = ((n / d) * x) % bp;
//        printf("DEBUG %lld\n", k);
        if (k < 0)
            k += bp;
        k *= a;
        long long dod = a * bp;
        if (k > n) {
//            printf("DEBUG Min k too large\n");
            printf("-1\n");
            continue;
        }
        long long before = ((aimfor - k) / dod) * dod + k;
        long long after = before + dod;
//        printf("DEBUG before after %lld %lld\n", before, after);
        long long best = -1;
        if (before <= n) {
            best = std::max(best, tab[before + 1] + sa);
        }
        if (after <= n) {
            best = std::max(best, tab[after + 1] + sa);
        }
        printf("%lld\n", best);
    }
    return 0;
}