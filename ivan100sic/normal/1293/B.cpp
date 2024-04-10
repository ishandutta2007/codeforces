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

    double z = 0;
    int n;
    cin >> n;
    for (int i : ra(1, n+1)) {
        z += 1.0 / i;
    }

    cout << setprecision(14) << fixed << z << '\n';
}