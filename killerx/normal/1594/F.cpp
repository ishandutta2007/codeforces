#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
    long long s, n, k;
    scanf("%lld %lld %lld", &s, &n, &k);
    // [0, s]
    // [0, k - 1]
    // p, (s - p) / k + 1
    long long bound = s % k;
    long long max = std::max(0LL, s / k + 1);
    long long min = std::max(0LL, max - 1);
    long long cmax = bound + 1;
    long long cmin = k - 1 - bound;
//    eprintf("%lld %lld %lld %lld\n", max, cmax, min, cmin);
    long long ans = (max + 1) / 2 * cmax + (min + 1) / 2 * cmin;
    ans -= (max + 1) / 2;
    if (s % k == 0) {
        if (max <= 2) return puts("YES"), void();
        if (max == 3) ans += 2;
        else ans += (max - 4 + 1) / 2 + 2;
    } else {
        ans -= (max + 1) / 2;
        rep(ss, 2) {
            if (max == 1) ans += 1;
            else ans += (max - 2 + 1) / 2 + 1;
        }
    }
//    eprintf("%lld\n", ans);
    puts(ans < n + 1 ? "YES" : "NO");
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}