#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fast(ll k, ll a, ll d, vector<ll> t) {
    int n = t.size();
    t.push_back(4e18);
    n++;
    sort(t.begin(), t.end());

    ll ans = 1;
    ll last = min(t[0], a);
    for (int i = 0; i < n; i++) {
        if (last + d >= t[i]) continue;
        
        ll l = 0, r = k + 1;
        while (r - l > 1) {
            ll x = (l + r) / 2;
            if (x * a > last + d) r = x;
            else l = x;
        }
        if (r != k + 1) {
            //ll t1 = r * (k + 1);
            ll t1 = r * a;
            if (t1 <= t[i]) {
                ll cnt = d / a + 1;

                // r, r + cnt, r + 2cnt, ....
                // max z: r + z*cnt <= k    and
                //        a * (r + z * cnt) <= t[i]
                ll z1 = (k - r) / cnt;
                ll z2 = (t[i] / a - r) / cnt;
                ll z = min(z1, z2);

                assert(z >= 0);
                ans += z + 1;
                last = (r + z * cnt) * a;
            }
        }
        if (last + d >= t[i]) continue;
        last = t[i];
        ans++;
        continue;
    }
    return ans - 1;
}

ll slow(ll k, ll a, ll d, vector<ll> t) {
    for (ll i = 1; i <= k; i++) t.push_back(a * i);
    sort(t.begin(), t.end());

    ll ans = 0;
    for (int i = 0; i < (int)t.size(); i++) {
        int j = i;
        while (j + 1 < (int)t.size() && t[j + 1] - t[i] <= d) j++;
        ans++;
        i = j;
    }
    return ans;
}

void stress() {
    for (int it = 0;; it++) {
        srand(it);
        cerr << it << endl;

        ll k = rand() % 55 + 1;
        ll a = rand() % 55 + 1;
        ll d = rand() % 55 + 1;
        int n = rand() % 55 + 1;
        vector<ll> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = rand() % 200 + 1;
        }
        sort(t.begin(), t.end());

        auto ans1 = fast(k, a, d, t);
        auto ans2 = slow(k, a, d, t);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << k << " " << n << " " << a << " " << d << endl;
            for (ll x : t) cout << x << " "; cout << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();

    ll k, a, d;
    int n;
    while (scanf("%lld%d%lld%lld", &k, &n, &a, &d) == 4) {
        vector<ll> t(n);
        for (int i = 0; i < n; i++) scanf("%lld", &t[i]);

        printf("%lld\n", fast(k, a, d, t));
    }
    
    return 0;
}