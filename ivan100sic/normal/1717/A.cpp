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

        int sol = 0;
        const auto n3 = ra(1, 4);

        for (int x : n3) {
            for (int y : n3) {
                if (gcd(x, y) == 1 && x*y <= 3) {
                    sol += n/max(x, y);
                }
            }
        }

        cout << sol << '\n';
    }
    
}