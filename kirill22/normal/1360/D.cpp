#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int x = i, y = n / i;
            if (n <= k * x) ans = min(ans, x);
            if (n <= k * y) ans = min(ans, y);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}