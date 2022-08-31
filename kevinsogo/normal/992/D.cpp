#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 201111;

ll a[N], lf[N], rg[N], ps[N], sm[N];
int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll m = 1, b = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        m = max(m, a[i]);
        if (a[i] != 1) {
            ps[b++] = i;
        }
        sm[i + 1] = sm[i] + a[i];
        if (k == 1) ans += a[i] == 1;
    }
    for (int i = 0; i < b; i++) {
        lf[i] = rg[i] = ps[i];
        while (lf[i] - 1 >= 0 && a[lf[i] - 1] == 1) lf[i]--;
        while (rg[i] + 1 < n && a[rg[i] + 1] == 1) rg[i]++;
        lf[i] = ps[i] - lf[i];
        rg[i] = rg[i] - ps[i];
    }
    ll bound = n * m * k * 2 + 1;
    for (int i = 0; i < b; i++) {
        ll pd = 1;
        for (int j = i; j < b; j++) {
            if (pd > bound / a[ps[j]]) break;
            pd *= a[ps[j]];
            if (pd % k == 0) {
                ll s = sm[ps[j] + 1] - sm[ps[i]];
                // 0 <= x <= lf[i]
                // 0 <= y <= rg[j]
                // x + y = pd / k - s
                ll t = pd / k - s;
                // 0 <= x <= lf[i]
                // t - rg[j] <= x <= t
                ll l = max(0LL, t - rg[j]);
                ll r = min(lf[i], pd / k - s);
                if (l <= r) ans += r - l + 1;
            }
        }
    }
    printf("%lld\n", ans);
}