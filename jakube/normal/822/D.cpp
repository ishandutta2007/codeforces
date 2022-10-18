#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, int e, int mod) {
    long long result = 1;
    while (e) {
        if (e & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        e >>= 1;
    }
    return result;
}

long long inverse(long long a, int mod) {
    return power(a, mod-2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> smallest_factor(5e6+1, 0);
    for (int i = 0; i < smallest_factor.size(); i++)
        smallest_factor[i] = i;

    for (int i = 2; i*i < smallest_factor.size(); i++) {
        if (smallest_factor[i] == i) {
            for (int j = i * i; j < smallest_factor.size(); j += i) {
                if (smallest_factor[j] == j)
                    smallest_factor[j] = i;
            }
        }
    }

    vector<long long> dp(5e6+1, 0);
    dp[1] = 1;
    for (long long i = 2; i < dp.size(); i++) {
        if (smallest_factor[i] == i) {
            dp[i] = (i * (i - 1) / 2) % MOD;
        } else {
            long long factor = smallest_factor[i];
            dp[i] = (i * (factor - 1) / 2 + dp[i / smallest_factor[i]]) % MOD;
        }
    }
   
    int t, l, r;
    cin >> t >> l >> r;
    
    long long res = 0;
    for (int i = r; i >= l; i--) {
        res = (res * t + dp[i]) % MOD;
    }
    cout << res << endl;
}