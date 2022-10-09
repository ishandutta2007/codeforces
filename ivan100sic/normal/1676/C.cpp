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
        for (auto& s : a) cin >> s;

        int z = 2e9;
        for (int i : ra(0, n)) {
            for (int j : ra(i+1, n)) {
                int d = 0;
                for (int k : ra(0, m)) {
                    d += abs(a[i][k] - a[j][k]);
                }
                z = min(z, d);
            }
        }

        cout << z << '\n';
    }
}