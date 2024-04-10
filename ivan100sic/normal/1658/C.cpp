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

        int i = 0, c = 0;
        for (int j : ra(0, n)) {
            if (a[j] == 1) {
                i = j;
                c++;
            }
        }

        if (c != 1) {
            cout << "NO\n";
            continue;
        }

        rotate(a.begin(), a.begin() + i, a.end());
        bool ok = 1;
        for (int i=1; i<n; i++) {
            if (a[i] - a[i-1] >= 2) {
                ok = 0;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    
}