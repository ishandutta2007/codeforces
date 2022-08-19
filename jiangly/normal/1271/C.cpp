#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int u = 0, d = 0, l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (y > sy)
            ++u;
        if (y < sy)
            ++d;
        if (x > sx)
            ++r;
        if (x < sx)
            ++l;
    }
    int ans = max(u, max(d, max(l, r)));
    cout << ans << "\n";
    if (u == ans) {
        ++sy;
    } else if (d == ans) {
        --sy;
    } else if (l == ans) {
        --sx;
    } else {
        ++sx;
    }
    cout << sx << " " << sy << "\n";
    return 0;
}