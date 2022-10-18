#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long pow(long long base, int exp) {
    long long result = 1;
    while (exp) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long comp_inverse(long long x) {
    return pow(x, MOD - 2);
}

vector<long long> fact, ifact;

long long nCr(long long n, long long k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return (((fact[n] * ifact[k]) % MOD) * ifact[n - k]) % MOD;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    fact.resize(1e5 + 2);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++) 
        fact[i] = (fact[i - 1] * i) % MOD;
    ifact.resize(1e5 + 2);
    ifact[0] = 1;
    for (int i = 1; i < fact.size(); i++)
        ifact[i] = (ifact[i - 1] * comp_inverse(i)) % MOD;

    int f, w, h;
    cin >> f >> w >> h;

    if (w == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (f == 0) {
        cout << (w > h ? 1 : 0) << endl;
        return 0;
    }
    
    long long all_arrangements = 0;
    long long good_arrangements = 0;

    for (long long k = 1; k <= w; k++) {
        long long good_w = nCr(w + k - 1 - k * (h + 1), k-1);
        if (k - 1 <= f) {
            all_arrangements += (nCr(w-1, k-1) * nCr(f-1, k-2)) % MOD;
            good_arrangements += (good_w * nCr(f-1,  k-2)) % MOD;
        }
        if (k <= f) {
            all_arrangements += (nCr(w-1, k-1) * nCr(f-1, k-1) * 2) % MOD;
            good_arrangements += (good_w * nCr(f-1, k-1) * 2) % MOD;
        }
        if (k + 1 <= f) {
            all_arrangements += (nCr(w-1, k-1) * nCr(f-1, k)) % MOD;
            good_arrangements += (good_w * nCr(f-1, k)) % MOD;
        }
        all_arrangements %= MOD;
        good_arrangements %= MOD;
    }

    cout << (good_arrangements * comp_inverse(all_arrangements)) % MOD << endl;

    return 0;
}