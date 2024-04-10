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

        vector<pair<int, int>> sol;

        auto go = [&](int i, int j) {
            if ((a[i] + a[j]) % 2) {
                a[j] = a[i];
            } else {
                a[i] = a[j];
            }
            sol.emplace_back(i+1, j+1);
        };

        if (n > 1) {
            go(0, n-1);
        }
        
        for (int i=1; i<n-1; i++) {
            if ((a[i] + a[0]) % 2) {
                go(0, i);
            } else {
                go(i, n-1);
            }
        }

        cout << sol.size() << '\n';
        for (auto [x, y] : sol) cout << x << ' ' << y << '\n';
    }
    
}