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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    llong u, v;
    cin >> u >> v;
    if (u > v || ((u & 1) != (v & 1))) {
        printf("-1\n");
        return 0;
    }
    llong a = (v - u) / 2;
    int s = 0, e = 1e6;
    while (s < e) {
        int m = (s + e) / 2;
        llong aa = a;
        for (int i = 60; i--; ) {
            int cnt = min(aa >> i, m / 2 + 5ll) * 2 + ((u >> i) & 1);
            while (cnt > m) cnt -= 2;
            if (cnt < 0) {
                aa = 1;
                break;
            }
            aa -= cnt / 2 * (1ll << i);
        }
        if (aa == 0) e = m;
        else s = m + 1;
    }
    int cnt[60] = {};
    for (int i = 60; i--; ) {
        cnt[i] = min(a >> i, s / 2 + 5ll) * 2 + ((u >> i) & 1);
        while (cnt[i] > s) cnt[i] -= 2;
        a -= cnt[i] / 2 * (1ll << i);
    }
    printf("%d\n", s);
    for (int i = 0; i < s; ++i) {
        llong x = 0;
        for (int j = 0; j < 60; ++j) {
            if (cnt[j] > i) x |= 1ll << j;
        }
        printf("%lld ", x);
    }
    return 0;
}