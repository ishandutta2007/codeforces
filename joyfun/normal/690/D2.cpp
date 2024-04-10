#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000001;
const int MOD = 1000003;

int n, c;
int f[N], rf[N];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int C(int n, int m) {
    return 1LL * f[n] * rf[m] % MOD * rf[n - m] % MOD;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = 1LL * f[i - 1] * i % MOD;
    rf[N - 1] = pow_mod(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) rf[i] = 1LL * rf[i + 1] * (i + 1) % MOD;
    scanf("%d%d", &n, &c);
    printf("%d\n", (C(n + c, c) - 1 + MOD) % MOD);
    return 0;
}