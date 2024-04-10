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
    int n, k, x;
    cin >> n >> k >> x;
    ve<int> a(n);
    forn (i, n) cin >> a[i];
    sort(all(a));
    int ans = 1;
    ve<int> b;
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        if (d <= x) continue;
        ans++;
        b.pb(d);
    }
    sort(all(b));
    for (auto y : b) {
        int z = (y - 1) / x;
        if (k >= z) {
            ans--;
            k -= z;
        }
    }
    cout << ans;
}