#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
const int M = N * N;
const int MOD = 1000000007;
typedef long long ll;

int k, c[N];
int f[M], rf[M];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = (ll)ans * x % MOD;
        x = (ll)x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int C(int n, int m) {
    if (m > n || n < 0 || m < 0) return 0;
    return (ll)f[n] * rf[n - m] % MOD * rf[m] % MOD;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (ll)f[i - 1] * i % MOD;
    rf[N - 1] = pow_mod(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) rf[i] = (ll)rf[i + 1] * (i + 1) % MOD;
    scanf("%d", &k);
    int sum = 0;
    int ans = 1;
    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    for (int i = k - 1; i >= 0; i--) {
        ans = (ll)ans * C(sum - 1, c[i] - 1) % MOD;
        sum -= c[i];
    }
    printf("%d\n", ans);
    return 0;
}