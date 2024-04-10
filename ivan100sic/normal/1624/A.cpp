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
        int a=0, b=1e9;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            a = max(a, x);
            b = min(b, x);
        }
        cout << a-b << '\n';
    }
}