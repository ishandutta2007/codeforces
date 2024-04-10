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
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        int l = 1123123123;
        for (int i : ra(0, n)) {
            if (b[i] > 0) {
                l = a[i] - b[i];
            }
        }

        bool ok = true;
        if (l >= 0) {
            for (int i : ra(0, n)) {
                if (max(a[i] - l, 0) != b[i]) {
                    ok = false;
                }
            }
        } else {
            ok = false;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}