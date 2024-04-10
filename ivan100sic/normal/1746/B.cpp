// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> of(n+1), zb(n+1);

        for (int i : ra(0, n)) {
            of[i+1] = of[i] + (a[i] == 1);
            zb[i+1] = zb[i] + (a[n-1-i] == 0);
        }

        int sol = n;
        for (int i : ra(0, n+1)) {
            sol = min(sol, max(of[i], zb[n-i]));
        }

        cout << sol << '\n';
    }
}