#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = (int) 1e9;
    for (int mn = 1; mn <= a[0]; mn++) {
        int mx = 0;
        for (int y = 1; y * 1ll * mn <= a.back(); y++) {
            int it = lower_bound(a.begin(), a.end(), mn * (y + 1)) - a.begin() - 1;
            if (it >= 0 && a[it] / mn == y) {
                int Y = min(k, a[it] / mn);
                mx = max(mx, a[it] / Y);
            }
        }
        ans = min(ans, mx - mn);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}