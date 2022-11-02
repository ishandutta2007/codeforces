#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;
const int N = 1000005;

int n;

int64 ans;
int64 pre[N];

inline int64 power(int64 x, int y) {
    return y ? power(x * x % P, y >> 1) * (y & 1 ? x : 1) % P : 1;
}

inline int64 inv(int64 x) {
    return power(x, P - 2);
}

inline int64 C(int m, int n) {
    if (m < 0 || n < 0 || m - n < 0) return 0;
    return pre[m] * inv(pre[n] * pre[m - n] % P) % P;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    pre[0] = 1;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * i % P;
    for (int i = 2; i <= n; ++++i) {
        ans += pre[i] * (C(i, n - i) + C(i - 1, n - i - 1)) % P;
    }
    std::cout << ans * 2 % P << std::endl;
    return 0;
}