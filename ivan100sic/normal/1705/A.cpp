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
        vector<int> a(2*n);
        for (int& x : a) cin >> x;
        R::sort(a);
        int ok = 1;
        for (int i : ra(0, n)) {
            if (a[i+n] - a[i] < x) {
                ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    
}