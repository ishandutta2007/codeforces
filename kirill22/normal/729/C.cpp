#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
    sort(all(a));
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];
    b.pb(0);
    b.pb(s);
    sort(all(b));
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = max(pref[i], a[i].se);
    int l = -1, r = n;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int ttime = 0, tmp = pref[m + 1];
        for (int j = 1; j < b.size(); j++) {
            int c = b[j] - b[j - 1];
            if (tmp < c) {
                ttime = 1e18;
                break;
            }
            int z = min(c, tmp - c);
            ttime += z * 1 + (c - z) * 2;
        }
        if (ttime <= t) r = m;
        else l = m;
    }
    cout << (r == n ? -1 : a[r].fi);
}