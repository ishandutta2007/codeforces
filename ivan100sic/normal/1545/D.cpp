// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int m, k;
int a[1005][1005];
ll b[1005], c[1005];

array<ll, 3> qerp(ll t) {
    ll a2 = (2*c[t] + 3*t*c[t] + t*t*c[t] - 4*t*c[t+1] - 2*t*t*c[t+1] + t*c[t+2] + t*t*c[t+2]) / 2;
    ll b2 = (-3*c[t] - 2*t*c[t] + 4*c[t+1] + 4*t*c[t+1] - c[t+2] - 2*t*c[t+2]) / 2;
    ll c2 = (c[t] - 2*c[t+1] + c[t+2]) / 2;
    return {a2, b2, c2};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> m >> k;
    for (int i=0; i<k; i++) {
        for (int j=0; j<m; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            b[i] += x;
            c[i] += x*x;
        }
    }

    ll a1 = b[0];
    ll t[5] = {b[1] - b[0], b[2] - b[1], b[3] - b[2], b[4] - b[3], b[5] - b[4]};
    sort(t, t+5);
    ll b1 = t[2];

    ll bad = -1;
    for (int i=0; i<k; i++) {
        if (b[i] != a1 + b1 * i) {
            bad = i;
            break;
        }
    }

    ll d_lin = b[bad] - (a1 + b1 * bad);

    auto [a2, b2, c2] = qerp(bad >= 3 ? 0 : k - 3);

    ll d_quad = c[bad] - (a2 + b2 * bad + c2 * bad * bad);



    cout << bad << ' ' << (d_quad/d_lin - d_lin) / 2 << '\n' << flush;
}