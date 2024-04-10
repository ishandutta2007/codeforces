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
        int n, x;
        cin >> n >> x;
        ll sol = 0;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        ll z = 0, q = 1;
        bool ok = 1;
        while (ok) {
            for (int i : ra(0, n)) {
                if (a[i] == -1) {
                    ok = 0;
                    break;
                } else if (a[i] % x == 0) {
                    z += q * a[i];
                    a[i] /= x;
                } else {
                    z += q * a[i];
                    a[i] = -1;
                }
            }
            q *= x;
        }

        cout << z << '\n';
    }
    
}