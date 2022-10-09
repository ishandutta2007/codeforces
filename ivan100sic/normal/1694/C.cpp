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

        R::reverse(a);
        ll z = 0, ok = 1;
        for (int i : ra(0, n-1)) {
            if (a[i] == 0) continue;
            z += a[i];
            if (z >= 0) ok = 0;
        }

        z += a.back();
        if (z) ok = 0;

        cout << (ok ? "YES\n" : "NO\n");
    }
    
}