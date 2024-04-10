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
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i : ra(0, n)) {
            cin >> a[i];
        }

        string z = "YES\n";
        for (int i : ra(0, n-1)) {
            for (int j : ra(0, m-1)) {
                if (a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1] == 195) {
                    z = "NO\n";
                }
            }
        }
        cout << z;
    }
}