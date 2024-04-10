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
        int n, k, z = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> b(n);
        for (int i : ra(0, n-1)) {
            b[i+1] = b[i] + (a[i] < 2*a[i+1]);
        }

        for (int i : ra(0, n-k)) {
            z += (b[i+k] - b[i] == k);
        }

        cout << z << '\n';
    }
    
}