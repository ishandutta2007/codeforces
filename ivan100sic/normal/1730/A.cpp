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
        int n, c;
        cin >> n >> c;

        map<int, int> mp;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            mp[x]++;
        }

        ll sol = 0;
        for (auto [k, v] : mp) {
            sol += min(v, c);
        }

        cout << sol << '\n';
    }
}