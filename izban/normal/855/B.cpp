#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 19;
const int MOD = (int)1e9 + 7;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        ll p, q, r;
        scanf("%lld%lld%lld", &p, &q, &r);
        vector<ll> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

        vector<ll> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = p * a[i];
            if (i > 0) {
                pref[i] = max(pref[i], pref[i - 1]);
            }
        }
        vector<ll> suf(n);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = r * a[i];
            if (i < n - 1) {
                suf[i] = max(suf[i], suf[i + 1]);
            }
        }
        ll ans = -8e18;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pref[i] + a[i] * q + suf[i]);
        }
        printf("%lld\n", ans);
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}