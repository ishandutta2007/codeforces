#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long power(long long base, int e, int M=MOD)
{
    long long result = 1;
    base %= M;
    while (e) {
        if (e & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

// a(n) = 2^(n-1) - Sum_{d|n,d>1} a(n/d)


// sum([mobius(n/d)*2**(d - 1) for d in divisors(n)]) 
// 6:
//    1: mobius(6) * 2^0 = 1
//    2: mobius(3) * 2^1 = -2
//    3: mobius(2) * 2^2 = -4
//    6: mobius(1) * 2^5 = 32
//    59


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0 << '\n';
        return 0;
    }

    y /= x;
    if (y == 1) {
        cout << 1 << '\n';
        return 0;
    }

    // cout << (power(2, y - 1) - 1 + MOD) % MOD  << '\n';
    
    auto Y = y;
    vector<int> primes;
    for (int d = 2; d * d <= y; d++) {
        if (y % d == 0) {
            primes.push_back(d);
            while (y % d == 0) {
                y /= d;
            }
        }
    }
    if (y > 1)
        primes.push_back(y);

    long long res = 0;
    auto reset = primes;
    int total = 1 << primes.size();
    for (int i = 0; i < total; i++) {
        int cnt = 0;
        int num = 1;
        for (int j = 0; j < (int)primes.size(); j++) {
            if (i & (1 << j)) {
                cnt++;
                num *= primes[j];
            }
        }
        auto x = power(2, Y / num - 1);
        if ((cnt & 1) == 1)
            res = (res - x + MOD) % MOD;
        else
            res = (res + x + MOD) % MOD;
    }
    cout << res << endl;
}