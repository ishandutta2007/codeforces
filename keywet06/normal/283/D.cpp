#include <bits/stdc++.h>

using int64 = long long;

const int N = 6005;

int n;
int f[N];
int64 a[N];

void run() {
    int ans = n;
    f[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int64 x = a[i];
        f[i] = i - 1;
        int tp;
        for (int j = i - 1; j; --j) {
            if (!(x & 1)) {
                x >>= 1;
                if (a[j] % x != 0 || !((a[j] / x) & 1)) continue;
            } else if (a[j] % x != 0) {
                continue;
            }
            tp = f[j] + i - j - 1;
            if (f[i] > tp) f[i] = tp;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int tp = f[i] + n - i;
        if (ans > tp) ans = tp;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    run();
    return 0;
}