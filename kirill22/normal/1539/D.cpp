#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ve<pii> a(n);
    forn (i, n) cin >> a[i].fi >> a[i].se;
    sort(all(a), [&] (pii x, pii y) { return x.se < y.se; });
    int ans = 0, cnt = 0;
    int j = 0;
    while (j < sz(a)) {
        while (j < sz(a) && cnt < a[j].se) {
            int x, y;
            tie(x, y) = a.back();
            if (x + cnt < a[j].se) {
                ans += 2 * x;
                cnt += x;
                a.pop_back();
            }
            else {
                int z = a[j].se - cnt;
                a.back().fi -= z;
                cnt += z;
                ans += 2 * z;
            }
        }
        if (j < sz(a)) {
            ans += a[j].fi;
            cnt += a[j].fi;
            j++;
        }
    }
    cout << ans;
}