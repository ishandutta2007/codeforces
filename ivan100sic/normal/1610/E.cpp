// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i : ra(0, n)) {
            cin >> a[i];
        }

        int sol = 0;
        for (int i : ra(0, n-1)) {
            int z = 0;
            int j = upper_bound(a+i+1, a+n-1, a[i]) - a;
            z += j - i + 1;
            while (j < n) {
                j = lower_bound(a+j+1, a+n, 2*a[j] - a[i]) - a;
                if (j == n) break;
                z++;
            }

            sol = max(sol, z);
        }

        cout << n - sol << '\n';
    }
}