#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int n, m, k;

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int solve() {
    if (k > n || k == 1) return pow_mod(m, n);
    if (k == n) return pow_mod(m, (n + 1) / 2);
    if (k % 2) return m + m * (m - 1);
    return m;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", solve());
    return 0;
}