#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

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

std::vector<int> compute_primes(int n)
{
    std::vector<bool> m(n + 1, false);

    int root = std::sqrt(n) + 1;
    for (int i = 1; i <= root; i++) {
        for (int j = 1; j <= root; j++) {
            int a = 4 * i * i + j * j;
            int b = 3 * i * i + j * j;
            int c = 3 * i * i - j * j;

            if (a <= n && (a % 12 == 1 || a % 12 == 5))
                m[a].flip();
            if (b <= n && b % 12 == 7)
                m[b].flip();
            if (i > j && c <= n && c % 12 == 11)
                m[c].flip();
        }
    }

    for (int i = 5; i * i <= n; i++) {
        if (m[i]) {
            for (int j = 1; j * i * i <= n; j++)
                m[j * i * i] = false;
        }
    }

    std::vector<int> primes = {2, 3};
    for (int i = 5; i < n; i++) {
        if (m[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto primes = compute_primes(70);
    vector<int> mapping(71);

    for (int i = 1; i < 71; i++) {
        int r = 0;
        int num = i;
        for (int j = 0; j < (int)primes.size(); j++) {
            while (num % primes[j] == 0) {
                num /= primes[j];
                if (primes[j] < 35)
                    r ^= 1 << j;
            }
        }
        mapping[i] = r;
    }

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<long long> dp(2<<11, 0);
    dp[0] = 1;
    sort(v.begin(), v.end());
    vector<int> cnt(71, 0);
    for (int x : v)
        cnt[x]++;

    for (int i = 1; i <= 71; i++) {
        if (cnt[i]) {
            if (i > 35 && count(primes.begin(), primes.end(), i))
                continue;
            auto pw = power(2, cnt[i] - 1);
            auto dp2 = dp;
            for (auto& x : dp2) {
                x = (x * pw) % MOD;
            }
            for (int j = 0; j < (int)dp.size(); j++) {
                int k = j ^ mapping[i];
                dp2[k] = (dp2[k] + dp[j] * pw) % MOD;
            }
            dp = dp2;
        }
    }

    long long res = dp.front();
    for (int i = 36; i < 71; i++) {
        if (cnt[i] && count(primes.begin(), primes.end(), i)) {
            res = (res * power(2, cnt[i] - 1)) % MOD;
        }
    }

    cout << (res + MOD - 1) % MOD << endl;
}