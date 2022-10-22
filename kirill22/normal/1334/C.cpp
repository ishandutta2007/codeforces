#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define all(a) a.begin(), a.end()

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        bool f = true;
        int n, x;
        cin >> n;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
        for (int i = 0; i < n; i++) b[i] = a[(i + 1) % n].fi - max(0ll, a[(i + 1) % n].fi - a[i].se);
        sort(b.begin(), b.end());
        int ans = b[0];
        for (int i = 0; i < n; i++) {
            ans += max(0ll, a[(i + 1) % n].fi - a[i].se);
        }
        cout << ans << '\n';
    }
}