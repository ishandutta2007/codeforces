#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (auto x : a) ans += x;
    for (int i = 0; i < min(n, k); i++) {
        if (b[n - i - 1] > a[i]) {
            ans += b[n - i - 1] - a[i];
        }
        else break;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}