#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int n, m, dp[N];

int main() {
    scanf("%d%d", &n, &m);
    int ans = 1;
    int sum = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (2LL * dp[i - 1] % MOD - sum + MOD) % MOD * m % MOD;
        sum = (1LL * sum * (m - 1) % MOD + dp[i - 1]) % MOD;
    }
    printf("%d\n", dp[n]);
    return 0;
}