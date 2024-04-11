#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(12);

    double a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        double x, y, v;
        cin >> x >> y >> v;
        double dx = x - a, dy = y - b;
        ans = min(ans, sqrt(dx * dx + dy * dy) / v);
    }

    cout << ans << endl;
}