#include <bits/stdc++.h>

using int64 = long long;

const int N = 10000005;

int64 n, P, c, s;
int64 f[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> P;
    f[1] = 1;
    for (int i = 1; i <= n; ++i) {
        c = (c + f[i]) % P;
        s += f[i] = (s + c) % P;
        c -= i == 1;
        for (int c = 2; c * i <= n; ++c) {
            f[c * i] += f[i], f[c * (i + 1)] -= f[i];
        }
    }
    std::cout << (f[n] + P) % P << std::endl;
    return 0;
}