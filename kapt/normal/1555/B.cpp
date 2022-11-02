#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    cout.precision(15);
    while (tst--) {
        int W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        if (w > x1 + W - x2 && h > y1 + H - y2) {
            cout << -1 << "\n";
            continue;
        }
        int ans = 1e9;
        if (x2 - x1 + w <= W) {
            ans = min(ans, w - x1);
            ans = min(ans, x2 - W + w);
        }
        if (y2 - y1 + h <= H) {
            ans = min(ans, h - y1);
            ans = min(ans, y2 - H + h);
        }
        if (ans < 0) {
            ans = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}