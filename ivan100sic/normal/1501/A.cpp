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
        vector<int> a(n+1), b(n+1), tm(n+1);
        for (int i : ra(1, n+1)) cin >> a[i] >> b[i];
        for (int i : ra(1, n+1)) cin >> tm[i];

        int t = 0;
        for (int i : ra(1, n)) {
            t += a[i] - b[i-1] + tm[i];
            t = max({t, b[i], t + (b[i] - a[i] + 1) / 2});
        }

        t += a[n] - b[n-1] + tm[n];
        cout << t << '\n';
    }
    
}