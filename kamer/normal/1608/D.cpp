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
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;

    ll root = pow(a, n / 2);
    if (n % 2 == 0) return (root * root) % MOD;
    else return ((root * root) % MOD) * a % MOD;
}

ll inv(ll a) {
    return pow(a, MOD - 2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n;
    cin >> n;

    if (n == 1) {
        string s;
        cin >> s;
        if (s == "WW" || s == "BB") {
            cout << "0\n";
        } else if (s == "??") {
            cout << "2\n";
        } else {
            cout << "1\n";
        }

        return 0;
    }

    int w_first = 0, q_first = 0, b_last = 0, q_last = 0;
    bool all_wb = true, all_bw = true;
    ll res = MOD - 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s[0] == 'W') w_first++;
        if (s[0] == '?') q_first++;
        if (s[1] == 'B') b_last++;
        if (s[1] == '?') q_last++;

        if (s[0] == 'B' || s[1] == 'W') all_wb = false;
        if (s[0] == 'W' || s[1] == 'B') all_bw = false;
    
        if (s == "WW" || s == "BB") res = 0;
        else if (s == "??") res = (res * 2) % MOD;
    }

    ll a = w_first, b = q_first, c = b_last, d = q_last;

    if (c + d < a || a + b < c) {
        cout << "0\n";
        return 0;
    }

    ll d_adder = max(a, c) - c;
    ll b_adder = max(a, c) - a;

    vector<ll> fact(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<ll> inv(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    vector<ll> inv_fact(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
    }

    for (int i = 0; i <= n; i++) {
        // cout << "facts " << fact[i] << " " << inv_fact[i] << "\n";
    }

    for (ll i = 0; i <= min(d - d_adder, b - b_adder); i++) {
        ll comb_b = fact[b] * inv_fact[b_adder + i] % MOD * inv_fact[b - b_adder - i] % MOD;
        ll comb_d = fact[d] * inv_fact[d_adder + i] % MOD * inv_fact[d - d_adder - i] % MOD;
        res = (res + comb_b * comb_d) % MOD;
        // cout << "adding " << b << " " << b_adder << " " << d << " " << d_adder << " " << i << "\n";
        // cout << "res " << res << "\n";
    }

    if (all_wb) res++;
    if (all_bw) res++;
    res = (res + MOD) % MOD;

    cout << res << "\n";
}