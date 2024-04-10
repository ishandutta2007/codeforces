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
        int n, z = 0;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        auto lm = [&](int i) {
            return i > 0 && i < n-1 && a[i] > a[i-1] && a[i] > a[i+1];
        };

        for (int i : ra(1, n)) {
            if (lm(i-1)) {
                a[i] = max(a[i-1], i+1 == n ? -1 : a[i+1]);
                z++;
            }
        }

        cout << z << '\n';
        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
    
}