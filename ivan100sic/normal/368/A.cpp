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

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    R::sort(a);

    int m;
    cin >> m;
    if (m <= n) {
        cout << accumulate(a.begin(), a.begin() + m, 0) << '\n';
    } else {
        cout << accumulate(a.begin(), a.end(), 0) - (m-n) * d << '\n';
    }
}