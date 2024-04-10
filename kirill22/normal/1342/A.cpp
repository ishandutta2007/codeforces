#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int ans = 0;
        int res = abs(x - y);
        ans += a * res;
        ans += min(b * min(x, y), min(x, y) * 2 * a);
        cout << ans << '\n';
    }
}