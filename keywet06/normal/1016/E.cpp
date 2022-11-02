#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, q, sy, a, b, l[N], r[N];
long long sl[N], sr[N];

int main() {
    scanf("%d %d %d %d", &sy, &a, &b, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        sl[i] = sl[i - 1] + l[i], sr[i] = sr[i - 1] + r[i];
    }
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        auto get = [&](int z) {
            return 1LL * y * z + 1LL * (z - x) * -sy;
        };
        auto calc = [&](int i) {
            return max(0LL, min(1LL * b * y, get(r[i])) - max(1LL * a * y, get(l[i])));
        };
        int l = 1, r = n, p1 = n + 1, p2 = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(::l[mid]) >= 1LL * a * y) r = (p1 = mid) - 1;
            else l = mid + 1;
        }
        l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(::r[mid]) <= 1LL * b * y) l = (p2 = mid) + 1;
            else r = mid - 1;
        }
        __int128 ans = 0;
        if (p1 > p2) {
            for (int i = p2 - 1; i <= p1 + 1; i++) {
                if (i >= 1 && i <= n) ans += calc(i);
            }
        } else {
            if (p1 > 1) ans += calc(p1 - 1);
            if (p2 < n) ans += calc(p2 + 1);
            ans += (__int128)(y - sy) * (sr[p2] - sr[p1 - 1] - sl[p2] + sl[p1 - 1]);
        }
        printf("%.9f\n", 1.0 * ans / y);
    }
    return 0;
}