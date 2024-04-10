#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

static inline ll safe_mod(ll a) {
    ll res = a % MOD;
    if (res < 0) res += MOD;
    return res;
}

static inline tuple<ll, ll> mult(tuple<ll, ll> a, tuple<ll, ll> b) {
    auto [a0, a1] = a;
    auto [b0, b1] = b;
    return { safe_mod((a0 * b0) - (a1 * b1)), safe_mod(a0 * b1 + a1 * b0 - a1 * b1) };
}

static inline tuple<ll, ll> diff (tuple<ll, ll> a, tuple<ll, ll> b) {
    return { safe_mod(get<0>(a) - get<0>(b)), safe_mod(get<1>(a) - get<1>(b)) };
}

static inline tuple<ll, ll> add(tuple<ll, ll> a, tuple<ll, ll> b) {
    return { (get<0>(a) + get<0>(b)) % MOD, (get<1>(a) + get<1>(b)) % MOD };
}

static inline vector<tuple<ll, ll>> divide(vector<tuple<ll, ll>> p, tuple<ll, ll> c) {
    int n = p.size();
    vector<tuple<ll, ll>> r(n - 1);
    for (int i = n - 1; i >= 1; i--) {
        r[i - 1] = p[i];
        p[i - 1] = diff(p[i - 1], mult(p[i], c));
    }

    return r;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, q;
    cin >> n >> q;
    vector<ll> coeffs(3 * n + 4, 1);
    vector<ll> inv(3 * n + 4, 1);
    for (int i = 2; i < 3 * n + 4; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    for (ll i = 1; i < 3 * n + 4; i++) {
        coeffs[i] = (((coeffs[i - 1] * (3 * n + 4 - i)) % MOD) * inv[i]) % MOD;
        if (coeffs[i] < 0) cout << "OOOOOO " << i << " " << coeffs[i] << "\n";
    }

    vector<ll> e_poly_1(3 * n + 4), e_poly_e(3 * n + 4), e2_poly_1(3 * n + 4), e2_poly_e(3 * n + 4);
    for (int i = 0; i < 3 * n + 4; i++) {
        if (i % 3 == 0) {
            e_poly_1[i] = coeffs[i];
            e_poly_e[i] = 0;
            e2_poly_1[i] = coeffs[i];
            e2_poly_e[i] = 0;
        } else if (i % 3 == 1) {
            e_poly_1[i] = MOD - coeffs[i];
            e_poly_e[i] = MOD - coeffs[i];
            e2_poly_1[i] = 0;
            e2_poly_e[i] = coeffs[i];
        } else {
            e_poly_1[i] = 0;
            e_poly_e[i] = coeffs[i];
            e2_poly_1[i] = MOD - coeffs[i];
            e2_poly_e[i] = MOD - coeffs[i];
        }
    }

    vector<ll> e_div_1(3 * n + 3);
    vector<ll> e_div_e(3 * n + 3);
    for (int i = 3 * n + 3; i >= 1; i--) {
        ll a = e_poly_1[i], b = e_poly_e[i];
        e_div_1[i - 1] = a;
        e_div_e[i - 1] = b;

        e_poly_1[i - 1] = safe_mod(e_poly_1[i - 1] + a + b);
        e_poly_e[i - 1] = safe_mod(e_poly_e[i - 1] + 2 * b - a);
    }

    vector<ll> e2_div_1(3 * n + 3);
    vector<ll> e2_div_e(3 * n + 3);
    for (int i = 3 * n + 3; i >= 1; i--) {
        ll a = e2_poly_1[i], b = e2_poly_e[i];
        e2_div_1[i - 1] = a;
        e2_div_e[i - 1] = b;

        e2_poly_1[i - 1] = safe_mod(e2_poly_1[i - 1] + 2 * a - b);
        e2_poly_e[i - 1] = safe_mod(e2_poly_e[i - 1] + b + a);
    }
    

    ll inv_3 = inv[3];

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        ll res = coeffs[k + 1];
        if (k % 3 == 0) {
            res = res + e_div_1[k] + e2_div_1[k];
        } else if (k % 3 == 1) {
            res = res - e_div_e[k] + e2_div_e[k] - e2_div_1[k];
            res = res % MOD;
            if (res < 0) res += MOD;
        } else {
            res = res + e_div_e[k] - e_div_1[k] - e2_div_e[k];
            res = res % MOD;
            if (res < 0) res += MOD;
        }

        cout << (res * inv_3) % MOD << "\n";
    }
}