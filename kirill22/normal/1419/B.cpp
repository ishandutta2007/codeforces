#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int x = 1; ; x = x * 2 + 1) {
        if ((x * (x + 1)) / 2 <= n) ans++, n -= (x * (x + 1)) / 2;
        else break;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
}