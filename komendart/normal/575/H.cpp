#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int power(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return x * power(x, p - 1) % MOD;
    return power(x * x % MOD, p / 2);
}

signed main() {
    int n;
    cin >> n;

    vector<int> fac(2 * n + 3, 1);
    for (int i = 1; i <= 2 * n + 2; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    cout << (fac[2 * n + 2] * power(fac[n + 1], 2 * (MOD - 2)) + MOD - 1) % MOD << '\n';
}