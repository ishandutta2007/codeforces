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
        int n, k;
        cin >> n >> k;
        vector<int> a(n*k);
        for (int& x : a) cin >> x;

        ll z = 0;
        int g = (n+2)/2;
        for (int i : ra(0, k)) {
            z += a[n*k - (i+1)*g];
        }

        cout << z << '\n';
    }
    
}