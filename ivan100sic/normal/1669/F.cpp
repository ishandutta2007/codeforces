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

        int l = 0, u = 0, r = n-1, v = 0, sol = 0;
        while (l <= r) {
            if (u == v) {
                sol = max(sol, l + n - r);
            }
            if (u > v) {
                v += a[r--];
            } else {
                u += a[l++];
            }
        }
        if (u == v) {
            sol = max(sol, l + n - r);
        }
        cout << sol-1 << '\n';
    }
    
}