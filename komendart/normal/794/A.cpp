#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (b < x && x < c) ++ans;
    }
    cout << ans << '\n';
}