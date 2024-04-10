#include <cstdio>
#include <algorithm>
using namespace std;
#define int
signed a[100000];
signed b[100002];
long long dp[100002];
signed main(){
    signed n;
    scanf("%d", &n);
    for(signed i = 0; i < n; i++) scanf("%d", a + i), b[a[i]] ++;
    for(signed i = 2; i <= 100001; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + b[i - 1] * 1ll * (i - 1));
    }
    printf("%I64d\n", dp[100001]);
}