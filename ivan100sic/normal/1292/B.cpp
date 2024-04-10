// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const ll toobig = 2e16;
ll x[100], y[100], xs, ys, ax, ay, bx, by, t;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;

    for (int i=1; i<100; i++) {
        x[i] = min(x[i-1], toobig) * ax + bx;
        y[i] = min(y[i-1], toobig) * ay + by;
    }

    int sol = 0;

    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);

            d += min(
                abs(x[i] - xs) + abs(y[i] - ys),
                abs(x[j] - xs) + abs(y[j] - ys));
            
            if (d <= t) {
                sol = max(sol, j-i+1);
            }
        }
    }

    cout << sol << "\n";
}