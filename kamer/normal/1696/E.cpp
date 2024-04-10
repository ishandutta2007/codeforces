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

ll MOD = 1'000'000'007;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    ll n;
    cin >> n;

    ll MAX_NUM = 500'000;

    vector<ll> inv(MAX_NUM, (ll) 1);
    for (ll i = 2; i < MAX_NUM; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    vector<ll> fact(MAX_NUM, (ll) 1);
    for (ll i = 2; i < MAX_NUM; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<ll> inv_fact(MAX_NUM, (ll) 1);
    for (ll i = 2; i < MAX_NUM; i++) {
        inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
    }

    ll result = 0;
    for (ll i = 0; i <= n; i++) {
        ll a;
        cin >> a;

        if (i == 0) {
            result = a;
        } else if (a != 0) {
            result = (result + fact[i + a] * inv_fact[i + 1] % MOD * inv_fact[a - 1] % MOD) % MOD;
        }
    }

    cout << result << "\n";
}