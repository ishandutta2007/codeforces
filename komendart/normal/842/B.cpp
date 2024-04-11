#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int R, d, n;
    cin >> R >> d >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        int dist = x * x + y * y;
        if (r <= R && dist <= (R - r) * (R - r) && dist >= (R + r - d) * (R + r - d)) {
            ++ans;
        }
    }
    cout << ans << '\n';
}