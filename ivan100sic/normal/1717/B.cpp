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
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        r--, c--;

        int rem = (((r-c) % k) + k) % k;

        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                cout << (((i-j) % k + k) % k == rem ? 'X' : '.');
            }
            cout << '\n';
        }
    }
}