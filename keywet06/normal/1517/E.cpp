#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;
const int N = 200005;

int T, n, p;
int a[N];

int64 sum, ans, rsu, lim, c, u;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, sum = rsu = ans = 0, ++ans;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], sum += a[i];

        lim = (sum - 1) / 2;
        for (int i = n; rsu + a[i] <= lim && i; --i) rsu += a[i], ++ans;

        // std::cout << "Debug: " << ans, c = ans;

        rsu = a[2], p = 1, ans += n > 2 && rsu <= lim;
        while (p <= n - 3 && rsu + a[p + 2] <= lim) rsu += a[++++p];
        ans += p / 2;
        for (int i = 4; i <= n - 1; ++++i) {
            rsu += a[i];
            while (p > 1 && rsu > lim) rsu -= a[p], ----p;
            ans += p / 2 + (rsu <= lim);
        }

        // std::cout << ' ' << ans - c, c = ans;

        rsu = a[1], p = 1, ans += rsu <= lim;
        while (p <= n - 3 && rsu + a[p + 2] <= lim) rsu += a[++++p];
        ans += p / 2;
        for (int i = 2; i <= n - 1; ++++i) {
            rsu += a[i];
            while (p > 1 && rsu > lim) rsu -= a[p], ----p;
            ans += p / 2 + (rsu <= lim);
        }

        // std::cout << ' ' << ans - c, c = ans;

        rsu = a[2] + a[n], p = 1, ans += n > 3 && rsu <= lim;
        while (p < n - 3 && rsu + a[p + 2] <= lim) rsu += a[++++p];
        ans += p / 2;
        for (int i = 4; i < n - 1; ++++i) {
            rsu += a[i];
            while (p > 1 && rsu > lim) rsu -= a[p], ----p;
            ans += p / 2 + (rsu <= lim);
        }

        // std::cout << ' ' << ans - c, c = ans;
        
        rsu = a[1] + a[n], p = 1, ans += rsu <= lim;
        while (p < n - 3 && rsu + a[p + 2] <= lim) rsu += a[++++p];
        ans += p / 2;
        for (int i = 2; i < n - 1; ++++i) {
            rsu += a[i];
            while (p > 1 && rsu > lim) rsu -= a[p], ----p;
            ans += p / 2 + (rsu <= lim);
        }

        // std::cout << ' ' << ans - c << ' ', c = ans;

        std::cout << ans % P << '\n';
    }
    return 0;
}