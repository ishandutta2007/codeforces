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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int t = 0;
        for (int i : ra(1, n-1)) {
            if (a[i] > a[i-1] + a[i+1]) {
                t++;
            }
        }

        if (k >= 2) {
            cout << t << '\n';
        } else {
            cout << (n-1)/2 << '\n';
        }
    }
    
}