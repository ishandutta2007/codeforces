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

        bool ok = true;

        for (int& x : a) {
            while (x > n) x /= 2;
        }

        vector<int> f(n+1);
        for (int x : a) f[x]++;

        for (int i=n; i>=1; i--) {
            if (f[i] > 1) {
                f[i/2] += f[i] - 1;
                f[i] = 1;
            }
        }

        ok = f[0] == 0 && *R::max_element(f) == 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
}