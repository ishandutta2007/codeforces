// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int cb(int n, int b) {
    int m = 1 << (b + 1);
    int q = n / m;
    int r = n % m;
    return q * (m/2) + max(0, r - m/2 + 1);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int sol = r-l+1;
        for (int b=0; b<20; b++) {
            sol = min(sol, (r-l+1) - (cb(r, b) - cb(l-1, b)));
        }
        cout << sol << '\n';
    }
    
}