#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int n, cnt[N];
int l[N], r[N];

int pow_mod(int x, int k, int mod) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        k >>= 1;
    }
    return ans;
}

int get(int x) {
    return 1LL * x * (x + 1) / 2 % (MOD - 1);
}

int main() {
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    l[0] = 1;
    for (int i = 1; i <= 200000; i++)
        l[i] = 1LL * l[i - 1] * (cnt[i] + 1) % (MOD - 1);
    r[200001] = 1;
    for (int i = 200000; i >= 1; i--)
        r[i] = 1LL * r[i + 1] * (cnt[i] + 1) % (MOD - 1);
    int ans = 1;
    for (int i = 1; i <= 200000; i++) {
        int zs = 1LL * l[i - 1] * r[i + 1] % (MOD - 1) * get(cnt[i]) % (MOD - 1);
        ans = 1LL * ans * pow_mod(i, zs, MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}