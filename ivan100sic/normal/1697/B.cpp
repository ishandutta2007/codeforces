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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    R::sort(a);

    vector<ll> z(n+1);
    for (int i : ra(0, n)) {
        z[i+1] = z[i] + a[i];
    }

    for (int i : ra(0, q)) {
        int x, y;
        cin >> x >> y;
        x -= y;
        cout << z[n-x] - z[n-x-y] << '\n';
    }
}