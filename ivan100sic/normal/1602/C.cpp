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
        vector<int> a(n), c(30);
        for (int& x : a) cin >> x;
        for (int i : ra(0, 30)) {
            for (int j : ra(0, n)) {
                if (a[j] & (1 << i)) {
                    c[i]++;
                }
            }
        }
        int g = accumulate(begin(c), end(c), 0, [](int x, int y) { return gcd(x, y); });
        for (int x : ra(1, n+1)) {
            if (g % x == 0) {
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
    
}