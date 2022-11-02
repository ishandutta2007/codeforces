#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 500500;

bool good[N];

int n;

int64 a[N];
int64 pref[N];
int64 b[N], c[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    for (int k = 0; k <= n; k++) {
        int l = -1, r = n;
        while (r - l > 1) {
            int x = (l + r) / 2;
            (a[x] <= k + 1 ? r : l) = x;
        }
        r = max(r, k);
        b[k] = (int64)k * (k + 1) + (pref[n] - pref[r] + (int64)(r - k) * (k + 1)) -
               pref[k];
        l = -1, r = n;
        while (r - l > 1) {
            int x = (l + r) / 2;
            (a[x] <= k ? r : l) = x;
        }
        r = max(r, k);
        c[k] =
            pref[k] - (pref[n] - pref[r] + (int64)(r - k) * k) - (int64)k * (k - 1);
    }
    for (int i = 0; i < n; i++) c[i + 1] = max(c[i], c[i + 1]);
    for (int i = n - 1; i >= 0; i--) b[i] = min(b[i], b[i + 1]);
    for (int k = 0; k <= n; k++) {
        int64 l = c[k], r = b[k];
        if (k == 0)
            r = min(r, (int64)n);
        else
            r = min(r, a[k - 1]);
        if (k == n)
            l = max(l, 0LL);
        else
            l = max(l, a[k]);
        for (int64 i = l; i <= r; i++) good[i] = 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum ^= (a[i] & 1);
    bool ok = false;
    for (int i = 0; i <= n; i++) {
        if (!good[i]) continue;
        if ((i & 1) != sum) continue;
        ok = true;
        printf("%d ", i);
    }
    if (!ok) printf("-1");
    printf("\n");
    return 0;
}