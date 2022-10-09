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
        map<int, vector<int>> e;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            e[x].push_back(i);
        }
        int sol = -1;
        for (auto& [k, v] : e) {
            R::adjacent_find(v, [&](int x, int y) {
                sol = max(sol, min(x, y) + min(n-x, n-y));
                return false;
            });
        }
        cout << sol << '\n';
    }
}