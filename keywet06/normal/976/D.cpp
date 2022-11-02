#include <bits/stdc++.h>

const int N = 1000005;

int n, l, r, cnt;
int a[N], f[N], x[N], y[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        f[a[i]] = true;
    }
    while (a[n] > r) {
        do {
            for (int i = l + 2; i <= a[n] + 1; ++i) x[cnt] = l + 1, y[cnt++] = i;
            ++l, ++r;
        } while (!f[r]);
        --n;
    }
    std::cout << cnt << '\n';
    for (int i = 0; i < cnt; ++i) std::cout << x[i] << ' ' << y[i] << '\n';
    return 0;
}