#include <bits/stdc++.h>
using namespace std;

int MOD = 1'000'000'007;

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

std::vector<long long> factorial, inv;

void precompute_factorial(int ma)
{
    factorial.push_back(1);
    inv.push_back(1);
    for (int i = 1; i <= ma; i++) {
        factorial.push_back((factorial.back() * i) % MOD);
        inv.push_back(power(factorial.back(), MOD - 2));
    }
}

long long f(string a, string b) {
    vector<int> cnt(26, 0);
    for (char c : a) {
        cnt[c - 'a']++;
    }

    int n = b.size();
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long x = factorial[n - 1 - i];
        for (int k = 0; k < 26; k++) {
            x = (x * inv[cnt[k]]) % MOD;
        }
        for (int j = 0; j < b[i] - 'a'; j++) {
            if (cnt[j]) {
                auto z = (x * factorial[cnt[j]]) % MOD;
                cnt[j]--;
                z = (z * inv[cnt[j]]) % MOD;
                res += z;
                cnt[j]++;
            }
        }
        if (cnt[b[i] - 'a'])
            cnt[b[i] - 'a']--;
        else
            break;
        res %= MOD;
    }
    res %= MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorial(1'000'005);

    string a, b;
    cin >> a >> b;

    auto res = f(a, b);
    res -= f(a, a);
    res -= 1;
    res += 2 * MOD;
    res %= MOD;
    
    cout << res << endl;
}