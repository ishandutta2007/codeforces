#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int buben = 3 * 316228;

ll solve(ll c, ll n, ll alpha, ll cnt) {
    ll val = n - cnt + alpha - c * n;
    if (val < 0) {
        return -1;
    }
    ll rg = val / (c + 1);
    rg = min(rg, n);

    if (c == 0) {
        if (alpha < 0) {
            return -1;
        }
    } else {
        val = alpha - c * n;
        if (val < 0) {
            return -1;
        }
        rg = min(rg, val / c);
    }

    ll lf = 0;
    if (c == 0) {
        if (alpha - cnt > 0) {
            return -1;
        }
    } else {
        val = alpha - cnt - c * n;
        if (val >= 0) {
            lf = (val + c - 1) / c;
        }
    }

    

    val = alpha - c * n;
    if (val >= 0) {
        lf = max(lf, (val + c) / (c + 1));
    }
    if (lf > rg) {
        return -1;
    }
    return rg;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    ll ans = -1;

    vector<ll> vct = {0};
    for (int i = 1; i <= buben && i <= k; ++i) {
        vct.pb(i);
        vct.pb(k / i);
        if (k / i - 1 >= 0) {
            vct.pb(k / i - 1);
        }
    }
    ll cnt;
    if (r >= l) {
        cnt = r - l + 1;
    } else {
        cnt = r + n - l + 1;
    }

    for (ll c : vct) {
        if (k < cnt || c > k / n) {
            continue;
        }
        ans = max(ans, solve(c, n, k - cnt, cnt));
    }

    for (ll c : vct) {
        if (k < cnt + 2 * c || c > k / n) {
            continue;
        }
        ll s = solve(c, n - 1, k - cnt - 2 * c, cnt - 1);
        if (s != -1) {
            ans = max(ans, s + 1);
        }
    }

    cout << ans << "\n";
    
}