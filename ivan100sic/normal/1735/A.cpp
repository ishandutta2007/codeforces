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

        int sol = -1;
        for (int a : ra(n/3-5, n/3+5)) {
            for (int b : ra(2*n/3-5, 2*n/3+5)) {
                if (1 <= a && a <= b && 1 + a + b == n-3) {
                    sol = max(sol, min(a-1, b-a));
                }
            }
        }

        cout << sol << '\n';
    }
}