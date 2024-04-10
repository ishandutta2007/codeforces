#include <bits/stdc++.h>
using namespace std;
#define MX 200
#define mod 1000000007
long long inv[MX + 5];
long long ncr(int n, int r) {
    long long ret = 1;
    for (int i = n - r + 1; i <= n; i++) ret = (ret * i) % mod;
    for (int i = 1; i <= r; i++) ret = (ret * inv[i]) % mod;
    return ret;
}
int main() {
    inv[1] = 1;
    for (int i = 2; i <= MX; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    int n, k;
    scanf("%d%d", &n, &k);
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    int curn = 1;
    for (int i = 30 - __builtin_clz(n); i >= 0; i--) {
        vector<long long> big(k + 1, 0), pw(k + 1), tmp(k + 1, 0);
        pw[0] = 1;
        for (int j = 1; j <= k; j++) pw[j] = (curn * pw[j - 1]) % mod;
        for (int j = 0; j <= min(k, curn); j++) {
            for (int l = 0; l <= j; l++)
                big[j] =
                    (big[j] + ncr(curn - l, j - l) * dp[l] % mod * pw[j - l]) %
                    mod;
        }
        for (int js = 0; js <= k; js++) {
            for (int jb = 0; jb <= k; jb++) {
                if (js + jb <= k)
                    tmp[js + jb] = (tmp[js + jb] + dp[js] * big[jb]) % mod;
            }
        }
        dp = tmp;
        curn *= 2;
        if (n & (1 << i)) {
            vector<long long> tmp(k + 1);
            tmp[0] = 1;
            for (int j = 1; j <= k; j++)
                tmp[j] = (dp[j] + curn * dp[j - 1]) % mod;
            dp = tmp;
            curn++;
        }
    }
    int ans[] = {1, 0};
    for (int j = 1; j <= k; j++) {
        ans[j % 2] = (ans[j % 2] + dp[j]) % mod;
        printf("%d ", ans[j % 2]);
    }
    printf("\n");
}