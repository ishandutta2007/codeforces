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

    int n, p;
    cin >> n >> p;

    vector<int> a(n), sol;
    for (int& x : a) cin >> x;
    R::sort(R::reverse_view(a));

    for (int x=1; x<=4000; x++) {
        int q = 1;
        for (int i=0; i<n; i++) {
            q = (1ll * q * clamp(n - i + x - a[i], 0, n-i)) % p;
        }

        if (q) {
            sol.push_back(x);
        }
    }

    cout << sol.size() << '\n';
    for (int x : sol) cout << x << ' ';
    cout << '\n';
}