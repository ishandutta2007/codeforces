#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int n, k, q;
vector<int> fac[N];
int cnt[N], phi[N];
int f[200005], rf[200005];

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
    if (n < 0 || m < 0 || n < m) return 0;
    return 1LL * f[n] * rf[m] % MOD * rf[n - m] % MOD;
}

int cal(int a) {
    int ans = 0;
    for (int i = 0; i < fac[a].size(); i++) {
        int x = fac[a][i];
        ans = (ans + 1LL * C(cnt[x], k - 1) * phi[x] % MOD) % MOD;
    }
    return ans;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < 200005; i++)
        f[i] = 1LL * f[i - 1] * i % MOD;
    rf[200004] = pow_mod(f[200004], MOD - 2);
    for (int i = 200003; i >= 0; i--)
        rf[i] = 1LL * rf[i + 1] * (i + 1) % MOD;
    for (int i = 1; i < N; i++) {
        phi[i] = (phi[i] + i) % MOD;
        for (int j = i; j < N; j += i) {
            fac[j].push_back(i);
            if (i != j) phi[j] = (phi[j] - phi[i] + MOD) % MOD;
        }
    }
    scanf("%d%d%d", &n, &k, &q);
    int a;
    int ans = 0;
    for (int i = 1; i <= n + q; i++) {
        scanf("%d", &a);
        ans = (ans + cal(a)) % MOD;
        if (i > n) printf("%d\n", ans);
        for (int j = 0; j < fac[a].size(); j++)
            cnt[fac[a][j]]++;
    }
    return 0;
}