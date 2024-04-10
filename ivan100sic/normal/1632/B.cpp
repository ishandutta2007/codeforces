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
        int p = 1;
        while (2*p < n) p *= 2;

        for (int i=p-1; i>=0; i--) cout << i << ' ';
        for (int i=p; i<n; i++) cout << i << ' ';
        cout << '\n';
    }
}