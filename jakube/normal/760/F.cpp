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

long long inverse(int a, int mod) {
    return power(a, mod-2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string compress;
    for (char c : s) {
        if (compress.empty() || c != compress.back()) {
            compress += c;
        }
    }

    vector<vector<long long>> dp(compress.size() + 1, vector<long long>(26, 0));
    for (char c : compress) {
        dp[1][c - 'a'] = 1;
        for (int len = 2; len <= compress.size(); len++) {
            long long sum = 0;
            for (int ord = 0; ord < 26; ord++) {
                if (ord != c - 'a') {
                    sum += dp[len - 1][ord];
                }
            }
            dp[len][c - 'a'] = sum % MOD;
        }
    }

    vector<int> cnts;
    transform(dp.begin(), dp.end(), back_inserter(cnts), [](auto l){ return (int)(accumulate(l.begin(), l.end(), 0LL) % MOD); });

    vector<long long> factorial(n);
    factorial[0] = 1;
    for (int i = 1; i < n; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }

    long long result = 0;
    for (int i = 1; i <= compress.size(); i++) {
        long long factor = factorial[n-1];
        factor = (factor * inverse(factorial[i - 1], MOD)) % MOD;
        factor = (factor * inverse(factorial[n - i], MOD)) % MOD;
        factor = (factor * cnts[i]) % MOD;
        result = (result + factor) % MOD;
    }

    cout << result << endl;

    return 0;
}