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

        int g = 0;
        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                g = gcd(g, abs(a[i] - a[j]));
            }
        }

        if (g == 0) {
            g = -1;
        }
        
        cout << g << '\n';
    }    
}