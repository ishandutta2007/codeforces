#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int w = sqrt(n);
    while (w * w <= n) ++w;
    while (w * w > n) --w;
    n -= w * w;
    int ans = w * 4;
    if (n > 0) {
        ans += 2;
        n -= w;
    }
    if (n > 0) {
        ans += 2;
    }
    cout << ans << endl;
}