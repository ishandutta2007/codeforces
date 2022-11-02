#include <bits/stdc++.h>

using int64 = long long;

const int N = 40;
const int Q = 200000;

int n, q;
int cnt[N];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &cnt[i]);
    for (int i = 1; i <= q; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int pos, val;
            scanf("%d%d", &pos, &val);
            cnt[pos] = val;
        } else {
            int x;
            int64 k;
            scanf("%d%lld", &x, &k);
            int64 sum = 0;
            __int128 num = 0;
            for (int i = 0; i <= x; i++) {
                sum += cnt[i];
                num += 1ll * cnt[i] * ((1ll << i) - 1);
            }
            if (sum >= k) {
                puts("0");
                continue;
            }
            int64 ans = 0;
            int cur = n;
            for (int i = x + 1; i < n; i++) {
                if (sum + 1ll * cnt[i] * (1ll << (i - x)) >= k) {
                    ans +=
                        (k - sum) / (1ll << (i - x)) * ((1ll << (i - x)) - 1);
                    cur = i;
                    num += (__int128)(k - sum) / (1ll << (i - x)) *
                           (1ll << (i - x)) * ((1ll << x) - 1);
                    sum += (k - sum) / (1ll << (i - x)) * (1ll << (i - x));
                    break;
                }
                ans += 1ll * cnt[i] * ((1ll << (i - x)) - 1);
                sum += 1ll * cnt[i] * (1ll << (i - x));
                num += (__int128)cnt[i] * (1ll << (i - x)) * ((1ll << x) - 1);
            }
            if (cur == n) {
                if (k - sum <= num) {
                    ans += k - sum;
                } else {
                    ans = -1;
                }
                printf("%lld\n", ans);
                continue;
            }
            for (int i = cur; i > x && sum < k; i--) {
                if ((1ll << (i - 1 - x)) + sum <= k) {
                    ans += (1ll << (i - 1 - x));
                    sum += (1ll << (i - 1 - x));
                    num += (__int128)(1ll << (i - 1 - x)) * ((1ll << x) - 1);
                } else {
                    if (sum + num >= k) {
                        ans += k - sum;
                        sum = k;
                    } else {
                        ans++;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}