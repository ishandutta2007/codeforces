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

int n;
llong k;
int P[200001];
llong solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> P[i];
    int x, a, y, b;
    cin >> x >> a >> y >> b >> k;
    if (x > y) swap(x, y), swap(a, b);
    sort(P + 1, P + n + 1, greater<int>());
    int s = 0, e = n + 1;
    while (s < e) {
        int m = (s + e) / 2;
        int c[4] = {};
        for (int i = 1; i <= m; ++i) {
            int bit = 0;
            if (i % a == 0) bit |= 1;
            if (i % b == 0) bit |= 2;
            ++c[bit];
        }
        llong sum = 0;
        for (int i = 1; i <= c[3]; ++i) sum += (llong)P[i] * (x + y) / 100;
        for (int i = c[3] + 1; i <= c[3] + c[2]; ++i) sum += (llong)P[i] * (y) / 100;
        for (int i = c[3] + c[2] + 1; i <= c[3] + c[2] + c[1]; ++i) sum += (llong)P[i] * (x) / 100;
        if (k <= sum) e = m;
        else s = m + 1;
    }
    return s <= n ? s : -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}