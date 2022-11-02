#include <bits/stdc++.h>

const int N = 1000010;
const int P = 1000000007;

int n, k;
int a[N], s[N], l[N], r[N], *t = s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> k, --k, *t = -1;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        while (t > s && a[*t] < a[i]) r[*t--] = i;
        l[i] = *t, *++t = i;
    }
    while (t > s) r[*t--] = n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x = i - l[i] - 1, y = r[i] - i - 1, u, v, w;
        if (x > y) w = x, x = y, y = w;
        u = x / k, v = y / k, w = (x + y) / k;
        sum = (sum + (u * (u + 1ll) / 2 * k + u + (v - u) * (x + 1ll) - (v + w + 1ll) * (w - v) / 2 * k +
                      (x + y + 1ll) * (w - v)) %
                         P * a[i]) %
              P;
    }
    std::cout << sum << std::endl;
    return 0;
}