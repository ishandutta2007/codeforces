#include <bits/stdc++.h>

using int64 = long long;

const int64 P = 998244353;
const int N = 200005;

int n, x, y;
int a[N], s[N];

int64 ans;
int64 q[N], r[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> y >> s[i];
        x = std::lower_bound(a, a + i, y) - a;
        q[i] = a[i] - y + r[i] - r[x], q[i] %= P;
        r[i + 1] = r[i] + q[i], r[i + 1] %= P;
    }
    ans = a[n - 1] + 1;
    for (int i = 0; i < n; i++) ans += s[i] ? q[i] : 0;
    std::cout << (ans % P + P) % P << "\n";
    return 0;
}