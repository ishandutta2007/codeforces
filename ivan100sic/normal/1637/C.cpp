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

        a.erase(a.begin());
        a.erase(--a.end());
        n -= 2;

        ll sol = -1;

        if (n == 1) {
            if (a[0] % 2 == 0) {
                sol = a[0] / 2;
            }
        } else {
            if (R::count(a, 1) != n) {
                sol = 0;
                for (int x : a) {
                    sol += x/2 + x%2;
                }
            }
        }

        cout << sol << '\n';
    }
}