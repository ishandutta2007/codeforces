#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, q;
    cin >> d >> q;
    vector<int> p;
    for (int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            p.push_back(i);
            while (d % i == 0) d /= i;
        }
    }
    if (d != 1) p.push_back(d);
    int n = p.size();
    vector<int> fact(1e4, 1);
    for (int i = 2; i < 1e4; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int C[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        vector<int> _a(n), _b(n);
        for (int i = 0; i < n; i++) {
            while (a % p[i] == 0) {
                a /= p[i];
                _a[i]++;
            }
            while (b % p[i] == 0) {
                b /= p[i];
                _b[i]++;
            }
        }
        int res = 1;
        vector<int> mn, mx;
        int _n = 0, _x = 0;
        for (int i = 0; i < n; i++) {
            if (_a[i] == _b[i]) continue;
            int z = _a[i] - _b[i];
            if (z > 0) {
                mn.push_back(z);
                _n += z;
            }
            else if (z < 0) {
                mx.push_back(-z);
                _x += -z;
            }
        }
        for (int i = 0; i < mn.size(); i++) {
            res = (res * C[_n][mn[i]]) % mod;
            _n -= mn[i];
        }
        for (int i = 0; i < mx.size(); i++) {
            res = (res * C[_x][mx[i]]) % mod;
            _x -= mx[i];
        }
        cout << res << '\n';
    }
}