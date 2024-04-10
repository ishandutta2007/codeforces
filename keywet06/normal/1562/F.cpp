#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

bool is[N + 1];

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

auto gcd = std::__gcd<int64>;

int64 query(int x, int y) {
    std::cout << "? " << x + 1 << " " << y + 1 << std::endl;
    int64 ret;
    std::cin >> ret;
    return ret;
}

void solve() {
    int n;
    std::cin >> n;
    int64 a[n];
    std::memset(a, 0, sizeof(a));
    if (int64(n) * (n - 1) / 2 <= n + 5000) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; j++) {
                int64 x = query(i, j);
                a[i] = gcd(a[i], x);
                a[j] = gcd(a[j], x);
            }
        }
        if (n == 3 && a[0] % 2 == 0 && a[1] % 2 == 0 && a[2] % 2 == 0) {
            *std::max_element(a, a + 3) /= 2;
        }
    } else {
        int ids[n];
        std::iota(ids, ids + n, 0);
        std::shuffle(ids, ids + n, rnd);
        int u = -1;
        for (int i = 0; i < std::min(200, n); ++i) {
            int x = ids[i];
            for (int j = 0; j < 25; j++) {
                int y;
                do {
                    y = rnd() % n;
                } while (y == x);
                a[x] = gcd(a[x], query(x, y));
            }
            if (is[a[x]] && (u == -1 || a[x] > a[u])) u = x;
        }
        for (int i = 0; i < n; ++i) {
            if (i != u) a[i] = query(i, u) / a[u];
        }
    }
    std::cout << "!";
    for (int i = 0; i < n; ++i) std::cout << " " << a[i];
    std::cout << std::endl;
}

int main() {
    std::fill(is + 2, is + N + 1, true);
    for (int i = 2; i * i <= N; ++i) {
        if (!is[i]) continue;
        for (int j = i * i; j <= N; j += i) is[j] = false;
    }
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}