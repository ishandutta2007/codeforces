#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
std::vector<long long> factorial;

void precompute_factorial(int ma)
{
    factorial.push_back(1);
    for (int i = 1; i <= ma; i++)
        factorial.push_back((factorial.back() * i) % MOD);
}

long long power(long long base, int e)
{
    long long result = 1;
    while (e) {
        if (e & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    precompute_factorial(n+1);
    vector<long long> inv_factorial(n+1, 1);
    for (int i = 2; i < n + 1; i++)
        inv_factorial[i] = power(factorial[i], MOD - 2);

    vector<long long> inv(n+2);
    for (int i = 1; i < n + 2; i++)
        inv[i] = power(i, MOD - 2);

    if (k == 0) {
        cout << ((factorial[n] - factorial[n-1] + MOD) % MOD) << endl;
        return 0;
    }

    vector<long long> dp2(n+1, 1);
    vector<long long> xxx(n+1, 1);
    long long sum = 0;
    for (int i = 1; i < n+1; i++) {
        sum = (sum + xxx[i-1]) % MOD;
        if (i - 1 - k >= 0) {
            sum = (sum + MOD - xxx[i - 1 - k]) % MOD;
        }
        dp2[i] = (sum * factorial[i-1]) % MOD;
        xxx[i] = (dp2[i] * inv_factorial[i]) % MOD;
    }

    vector<long long> dp(n+1, 0);
    long long last = 0;
    long long total = 0;

    for (int i = k + 2; i <= n; i++) {
        long long y = i - k - 2;
        // long long tt = (factorial[y] - dp[y]) % MOD;
        long long tt = dp2[y];
        tt = (tt + MOD) % MOD;
        tt = (tt * inv_factorial[y]) % MOD;
        tt = (tt * inv[i-1]) % MOD;
        last += tt;
        last %= MOD;
        total += last;
        total %= MOD;
        dp[i] = (factorial[i-1] * total) % MOD;
    }
    cout << dp.back() << endl;
}