#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        ans += i * (i * 8);
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