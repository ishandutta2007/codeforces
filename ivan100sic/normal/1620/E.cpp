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

    int len = 0, q;
    cin >> q;
    map<int, list<int>> e;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            e[x].push_back(len++);
        } else {
            int x, y;
            cin >> x >> y;
            if (x != y) {
                e[y].splice(e[y].end(), e[x]);
            }
        }
    }

    vector<int> a(len);
    for (auto [k, v] : e) {
        for (int i : v) a[i] = k;
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
}