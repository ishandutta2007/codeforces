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
        bool ok = 1;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        for (int i : ra(0, n)) {
            int q = 0;
            for (int j=2;; j++) {
                if (a[i] % j) {
                    q = j;
                    break;
                }
            }
            if (q > i+2) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    
}