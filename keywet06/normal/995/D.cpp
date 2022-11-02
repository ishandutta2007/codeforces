#include <bits/stdc++.h>

using int64 = long long;

const int N = 500005;

int n, q;

int64 a[N];

int main() {
    scanf("%d%d", &n, &q);
    n = 1 << n;
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        ans += a[i];
    }
    printf("%.13lf\n", (double)ans / n);
    while (q--) {
        int v;
        scanf("%d", &v);
        ans -= a[v];
        scanf("%lld", &a[v]);
        ans += a[v];
        printf("%.13lf\n", (double)ans / n);
    }
    return 0;
}