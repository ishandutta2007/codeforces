// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ld solve(ld c, ld m, ld p, ld v) {
    ld z = 0;

    if (c > 1e-9) {
        ld c2 = max(0.0L, c - v);
        ld m2 = m, p2 = p;
        if (m > 1e-9 && p > 1e-9) {
            m2 = m + (c-c2) / 2;
            p2 = p + (c-c2) / 2;
        } else if (m > 1e-9) {
            m2 += c - c2;
        } else if (p > 1e-9) {
            p2 += c - c2;
        }
        z += c * (1 + solve(c2, m2, p2, v));
    }

    if (m > 1e-9) {
        ld m2 = max(0.0L, m - v);
        ld c2 = c , p2 = p;
        if (c > 1e-9 && p > 1e-9) {
            c2 += (m-m2) / 2;
            p2 += (m-m2) / 2;
        } else if (c > 1e-9) {
            c2 += m - m2;
        } else if (p > 1e-9) {
            p2 += m - m2;
        }
        z += m * (1 + solve(c2, m2, p2, v));
    }

    if (p > 1e-9) {
        z += p;
    }

    // cerr << "solve " << c << ' ' << m << ' ' << p << " -> " << z << '\n';
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(14) << fixed;

    int t;
    cin >> t;
    while (t--) {
        double c, m, p, v;
        cin >> c >> m >> p >> v;
        cout << solve(c, m, p, v) << '\n';
    }
}