#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long fastpow(long long base, long long exp) {
    long long ret = 1;
    for (long long p = base; exp > 0; p = p*p % MOD, exp >>= 1)
        if (exp & 1)
            ret = ret*p % MOD;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    long long s = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s += tmp;
    }
    s %= MOD;

    int sign = 2*(k % 2) - 1;
    long long binom = 1, ans = 0;
    
    for (int i = 0; i <= k-1; i++) {
        long long term = binom * fastpow(1+i, n-2) % MOD;
        if (sign == -1)
            term = MOD - term;
        
        ans = (ans + term*(n-1) % MOD + term*(1+i) % MOD) % MOD;
        
        binom = binom * (k-1-i) % MOD;
        binom = binom * fastpow(1+i, MOD-2) % MOD;
        sign *= -1;
    }

    ans = ans * s % MOD;
    for (int i = 1; i <= k-1; i++)
        ans = ans * fastpow(i, MOD-2) % MOD;

    cout << ans << endl;
}