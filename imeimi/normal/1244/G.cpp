#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

llong mx[1000001];
int P[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int n;
    llong k;
    cin >> n >> k;
    llong base = n * (n + 1ll) / 2;
    k -= base;
    if (k < 0) {
        printf("-1\n");
        return 0;
    }
    mx[1] = 0;
    for (int i = 2; i <= n; ++i) {
        mx[i] = mx[i - 1] + i / 2;
        if (i <= 10) debug("mx[%d]=%lld\n", i, mx[i]);
    }
    if (k == 0) {
        printf("%lld\n", base);
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        printf("\n");
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        printf("\n");
        return 0;
    }
    if (mx[n] <= k) {
        printf("%lld\n", base + mx[n]);
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        printf("\n");
        for (int i = 1; i <= n; ++i) printf("%d ", n + 1 - i);
        printf("\n");
        return 0;
    }
    printf("%lld\n", base + k);
    for (int i = 1; i <= n; ++i) printf("%d ", i);
    printf("\n");
    int l;
    for (l = n - 1; l > 0; --l) {
        if (mx[l] <= k) break;
    }
    for (int i = 1; i <= l; ++i) P[i] = l + 1 - i;
    for (int i = l + 1; i <= n; ++i) P[i] = i;
    for (int i = 1; i <= l; ++i) {
        if (mx[l] - max(P[i], i) + l + 1 == k) {
            swap(P[i], P[l + 1]);
            break;
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", P[i]);
    printf("\n");
    return 0;
}