#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;
const int B = 20;
const int X = 9;
const int Y = 1 << X;
const int Z = Y - 1;

int T, n, x, y, z, ans, r;
int lg[N];

int64 now;
int64 a[N][B];

inline int64 gcd(int64 x, int64 y) { return y ? gcd(y, x % y) : x; }

inline int64 get(int l, int r) {
    if (l == r) return 0;
    return gcd(a[l][lg[r - l]], a[r - (1 << lg[r - l])][lg[r - l]]);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    lg[1] = 0;
    for (int i = 2; i < N; ++i) lg[i] = lg[i - 1] + (i == 1 << lg[i - 1] + 1);
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i][0];
        --n, ans = 0;
        for (int i = 0; i < n; ++i) {
            a[i][0] = std::abs(a[i + 1][0] - a[i + 2][0]);
        }
        for (int i = 1; i < B; ++i) {
            for (int j = 0; j + (1 << i) < n; ++j) {
                a[j][i] = gcd(a[j][i - 1], a[j + (1 << i - 1)][i - 1]);
            }
        }
        r = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            now = get(i, r);
            while (now != 1 && r < n) now = gcd(now, a[r++][0]);
            ans = std::max(ans, r - i - (now == 1));
        }
        std::cout << ans + 1 << '\n';
    }
    return 0;
}