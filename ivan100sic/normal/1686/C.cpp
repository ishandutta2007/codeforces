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

        if (n % 2) {
            cout << "NO\n";
            continue;
        }

        R::sort(a);

        auto v2 = [&] {
            for (int i : ra(0, n/2)) {
                b[2*i+1] = a[n-1-i];
                b[2*i] = a[n-1-i-n/2];
            }
        };

        auto v1 = [&] {
            for (int i : ra(0, n/2)) {
                b[2*i] = a[i];
                b[2*i+1] = a[i+n/2];
            }
        };

        v1();

        bool ok = 1;
        for (int i : ra(0, n)) {
            if (b[i] == b[(i+1) % n]) {
                ok = 0;
            }
        }

        if (ok) {
            cout << "YES\n";
            for (int x : b) cout << x << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    
}