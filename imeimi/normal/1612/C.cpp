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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        ll k, x;
        cin >> k >> x;
        if (k * k < x) {
            printf("%lld\n", 2 * k - 1);
            continue;
        }
        ll s = 1, e = 2 * k - 1;
        if (k * (k + 1) / 2 < x) s = k + 1;
        else e = k;
        while (s < e) {
            ll m = (s + e) / 2;
            ll n = 2 * k - 1 - m;
            ll y = m <= k ? m * (m + 1) / 2 : k * k - n * (n + 1) / 2;
            if (y < x) s = m + 1;
            else e = m;
        }
        printf("%lld\n", s);
    }
    return 0;
}