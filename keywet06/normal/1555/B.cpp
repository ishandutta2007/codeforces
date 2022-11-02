#include <bits/stdc++.h>

using int64 = long long;

double ans;

int T, W, H, w, h, xa, xb, ya, yb;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    std::cout << std::fixed << std::setprecision(9);
    while (T--) {
        std::cin >> W >> H;
        std::cin >> xa >> ya >> xb >> yb;
        std::cin >> w >> h;
        if (xb - xa + w > W && yb - ya + h > H) {
            std::cout << -1 << std::endl;
            continue;
        }
        ans = 1e20;
        if (xa >= w || ya >= h || xb <= W - w || yb <= H - h) {
            std::cout << double(0) << std::endl;
            continue;
        }
        if (xb - xa + w <= W) {
            ans = std::min(ans, double(w - xa));
            ans = std::min(ans, double(xb - W + w));
        }
        if (yb - ya + h <= H) {
            ans = std::min(ans, double(h - ya));
            ans = std::min(ans, double(yb - H + h));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}