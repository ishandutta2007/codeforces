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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int sol = a[n-1] - a[0];
        sol = max(sol, a[n-1] - *min_element(a.begin(), a.end() - 1));
        sol = max(sol, *max_element(a.begin() + 1, a.end()) - a[0]);

        for (int i : ra(0, n-1)) {
            sol = max(sol, a[i] - a[i+1]);
        }

        cout << sol << '\n';
    }
}