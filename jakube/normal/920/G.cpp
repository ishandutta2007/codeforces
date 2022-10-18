#include <bits/stdc++.h>
using namespace std;

vector<int> prime_factors(int x) {
    vector<int> f;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            f.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        f.push_back(x);
    return f;
}

long long coprime(long long x, vector<int> const& odd, vector<int> const& even) {
    long long res = 0;
    for (auto v : even)
        res += x / v;
    for (auto v : odd)
        res -= x / v;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --> 0) {
        int x, p, k;
        cin >> x >> p >> k;
        auto primes = prime_factors(p);
        int n = (int)primes.size();
        vector<int> odd, even;
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0;
            int val = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt ^= 1;
                    val *= primes[i];
                }
            }
            if (cnt)
                odd.push_back(val);
            else
                even.push_back(val);
        }

        k += coprime(x, odd, even);
        long long L = x;
        long long R = std::numeric_limits<long long>::max() / 3;
        while (L + 1 < R) {
            auto M = (L + R) / 2;
            if (coprime(M, odd, even) >= k)
                R = M;
            else
                L = M;
        }
        cout << R << '\n';
    }
}