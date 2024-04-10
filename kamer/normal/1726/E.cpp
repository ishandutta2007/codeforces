#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int MAX_VAL = 300001;
    vector<ll> fact(MAX_VAL, 1);
    vector<ll> inv(MAX_VAL, 1);
    vector<ll> inv_fact(MAX_VAL, 1);
    vector<ll> pow_2(MAX_VAL, 1);
    vector<ll> odd_fact(MAX_VAL, 1);
    vector<ll> singles(MAX_VAL, 1);

    for (ll i = 1; i < MAX_VAL; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        if (i >= 2) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        if (i >= 2) inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
        pow_2[i] = (pow_2[i - 1] * 2) % MOD;
        if (i % 2 == 0) odd_fact[i] = (odd_fact[i - 2] * (i - 1)) % MOD;
        if (i >= 2) singles[i] = (singles[i - 1] + (i - 1) * singles[i - 2]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll res = 0;
        for (int k = 0; k <= n / 2; k += 2) {
            ll k_res = fact[n - k] * inv_fact[k] % MOD * inv_fact[n - 2 * k] % MOD;
            k_res = k_res * odd_fact[k] % MOD * pow_2[k / 2] % MOD;
            k_res = k_res * singles[n - 2 * k] % MOD;
            res = (res + k_res) % MOD;
        }

        cout << res << "\n";
    }
}