#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;
const int I = P + 1 >> 1;
const int J = (P + 1) / 6;
const int N = 1000005;

int n;

int64 ans;
int64 f[N], g[N], r[N], t[N];

int64 C2(int64 x) { return x * (x - 1) % P * I % P; }
int64 C3(int64 x) { return x * (x - 1) % P * (x - 2) % P * J % P; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    g[1] = (f[0] = g[0] = 1) + (f[1] = 2), r[1] = t[1] = 1;
    for (int i = 2; i <= n; ++i) {
        t[i] = (f[i - 1] * g[i - 2] % P + C2(f[i - 1] + 1)) % P;
        g[i] = (g[i - 1] + (f[i] = (t[i] + f[i - 1]) % P)) % P;
        r[i] = (r[i - 1] + t[i]) % P;
    }
    ans = f[n] + f[n - 1] * C2(g[n - 2] + 1) % P;
    ans += g[n - 2] * C2(f[n - 1] + 1) % P + C3(f[n - 1] + 2);
    ans = ((ans * 2 - 1) % P + P) % P;
    for (int i = 1; i < n; ++i) ans += (f[i] - 1) * t[n - i - 1] % P;
    // if (n == 1) 
    std::cout << (ans % P + P) % P << std::endl;
    return 0;
}