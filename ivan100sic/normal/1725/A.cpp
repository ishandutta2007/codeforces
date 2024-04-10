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

    ll n, m;
    cin >> n >> m;
    if (m >= 2) {
        cout << n * (m-1) << '\n';
    } else {
        cout << n-1 << '\n';
    }
}