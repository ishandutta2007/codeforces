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

        int rem = n % 4;
        if (rem < 3) rem += 4;

        for (int i : ra(0, rem-1)) {
            cout << (1 << i) << ' ';
        }

        cout << ((1 << (rem-1)) - 1) << ' ';
    
        for (int i : ra(0, n - rem)) {
            cout << 256 + i << ' ';
        }
        cout << '\n';
    }
}