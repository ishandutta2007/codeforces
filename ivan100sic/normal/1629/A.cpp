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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), c(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
    
        bool f = 1;
        while (f) {
            f = 0;
            for (int i : ra(0, n)) {
                if (!c[i] && a[i] <= k) {
                    c[i] = 1;
                    k += b[i];
                    f = 1;
                }
            }
        }

        cout << k << '\n';
    }
}