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
    for (int mn = 1; mn <= 3000; mn++) {
        int mx = 0;
        for (auto x : a) {
            int y = min(k, x / mn);
            if (y > 0 && y <= k) {
                mx = max(mx, x / y);
            } else {
                mx = -1;
                break;
            }
        }
        if (mx != -1) {
            ans = min(ans, mx - mn);
        }
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