#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long d = a + b * (c - 1);
        long long a2, b2, c2;
        cin >> a2 >> b2 >> c2;
        long long d2 = a2 + b2 * (c2 - 1);
        if (b2 % b) {
            cout << 0 << '\n';
            continue;
        }
        if ((a % b + b) % b != (a2 % b + b) % b || d2 > d || a2 < a) {
            cout << 0 << '\n';
            continue;
        }
        if (d == d2 || a == a2) {
            cout << -1 << '\n';
            continue;
        }
        long long ans = 0;
        int f = 0;
        auto upd = [&] (long long x) {
            long long z = x * b / __gcd(b, x);
            if (z == b2) {
                if (d2 + b2 > d) {
                    f = 1;
                }
                if (a2 - b2 < a) {
                    f = 1;
                }
                ans = (ans + (b2 / x) * (b2 / x)) % mod;
            }
        };
        for (long long x = 1; x * x <= b2; x++) {
            if (b2 % x == 0) {
                upd(x);
                if (x * x != b2) {
                    upd(b2 / x);
                }
            }
        }
        if (f) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans << '\n';
    }
}