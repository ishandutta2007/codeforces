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
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
        R::sort(a);
        R::sort(b, greater<int>());

        bool ok = true;
        for (int i : ra(0, n)) {
            if (a[i] + b[i] > x) {
                ok = false;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    
}