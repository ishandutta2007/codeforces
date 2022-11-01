#include <cstdio>
#include <algorithm>

long long a[200000];
long long a_copy[200000];

long long get_ans(int n, int limit, int rounds) {
    // fprintf(stderr, "> %d\n", rounds);

    std::copy_n(a_copy, n, a);

    long long ans = 0;
    for (int r = rounds - 1; r >= 0; r--) {
        for (int i = n - 1; i >= 0; i--) {
            long long buy = std::min(
                    (long long) limit,
                    a[i] - ((long long) r * (r - 1) / 2 * n +
                            (long long) r * (i + 1)));
            if (buy <= 0)
                return 0;
            a[i] -= buy;
            ans += buy;
            limit = buy - 1;
            // fprintf(stderr, "r=%d i=%d buy=%d\n", r, i, buy);
        }
    }
    return ans;
}

int main() {
    int n, m;
    std::scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        std::scanf("%lld", a_copy + i);

    long long ans = 0;
    int min_r = 1, max_r = m / n;
    while (min_r < max_r) {
        int mid_r = (min_r + max_r * 2) / 3;
        long long ans_mid = get_ans(n, m, mid_r);
        ans = std::max(ans, ans_mid);
        long long ans_mid_plus_1 = get_ans(n, m, mid_r + 1);
        ans = std::max(ans, ans_mid_plus_1);

        if (ans_mid < ans_mid_plus_1) {
            min_r = mid_r + 2;
        } else {
            max_r = mid_r - 1;
        }
    }
    if (min_r == max_r)
        ans = std::max(ans, get_ans(n, m, min_r));

    std::printf("%lld\n", ans);
}