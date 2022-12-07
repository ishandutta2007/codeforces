#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int n, k;
int l[N], r[N], h[N * 2], hn, sum[N * 2];
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

int C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return 1LL * f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int main() {
    scanf("%d%d", &n, &k);
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = 1LL * f[i - 1] * i % MOD;
    rf[n] = pow_mod(f[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) rf[i] = 1LL * rf[i + 1] * (i + 1) % MOD;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l[i], &r[i]);
        r[i]++;
        h[hn++] = l[i]; h[hn++] = r[i];
    }
    sort(h, h + hn);
    hn = unique(h, h + hn) - h;
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(h, h + hn, l[i]) - h;
        r[i] = lower_bound(h, h + hn, r[i]) - h;
        sum[r[i]]--; sum[l[i]]++;
    }
    for (int i = 1; i < hn; i++)
        sum[i] = sum[i] + sum[i - 1];
    int ans = 0;
    for (int i = 0; i < hn - 1; i++)
        ans = (ans + 1LL * (h[i + 1] - h[i]) * C(sum[i], k) % MOD) % MOD;
    printf("%d\n", ans);
    return 0;
}