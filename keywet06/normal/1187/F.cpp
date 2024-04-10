#include <bits/stdc++.h>

const int N = 2e5 + 5;
const int P = 1e9 + 7;

int n;
int l[N], r[N], p[N], x[N];

int Pow(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = 1ll * ans * a % P;
        a = 1ll * a * a % P,
        b >>= 1;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> l[i];
    for (int i = 1; i <= n; ++i) std::cin >> r[i], ++r[i];
    for (int i = 1; i <= n; ++i) x[i] = Pow(r[i] - l[i], P - 2);
    int sum = 1;
    for (int i = 1; i <= n - 1; ++i) {
        p[i] =
            1ll *
            std::max(0, std::min(r[i], r[i + 1]) - std::max(l[i], l[i + 1])) *
            x[i] % P * x[i + 1] % P;
        sum = (sum + 1 - p[i]) % P;
    }
    int ans = 1ll * sum * sum % P;
    for (int i = 1; i <= n - 1; ++i) {
        ans = (ans + 1ll * p[i] * (1 - p[i])) % P;
    }
    for (int i = 1; i <= n - 2; ++i) {
        ans =
            (ans - 2ll * p[i] * p[i + 1] +
             2ll *
                 std::max(0, std::min(r[i], std::min(r[i + 1], r[i + 2])) -
                                 std::max(l[i], std::max(l[i + 1], l[i + 2]))) *
                 x[i] % P * x[i + 1] % P * x[i + 2]) %
            P;
    }
    std::cout << (ans + P) % P << std::endl;
    return 0;
}