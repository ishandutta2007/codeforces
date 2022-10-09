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

    int n, q;
    cin >> n >> q;

    vector<int> parent(n+1);
    iota(begin(parent), end(parent), 0);

    const int inf = 1e9;
    vector<int> leave(n+1, inf);

    auto root_impl = [&](int x, auto self) {
        if (x == inf) return inf;
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = self(parent[x], self);
    };

    auto root = [&](int x) {
        return root_impl(x, root_impl);
    };

    auto merge = [&](int x, int y) {
        x = root(x);
        y = root(y);
        // cerr << "merge " << x << " into " << y << '\n';
        if (x != y) {
            parent[x] = y;
            leave[y] = min(leave[y], leave[x]);
        }
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 1) {
                l--;
                leave[root(l)] = min(leave[root(l)], r);
            } else {
                // big merge
                l--;
                while (root(l) != root(r)) {
                    int x = root(l);
                    merge(x, x+1);
                }
            }
        } else {
            int k;
            cin >> k;
            if (root(k-1) == root(k)) {
                cout << "NO\n";
            } else if (root(leave[root(k-1)]) == root(k)) {
                // cerr << root(k-1) << '\n';
                // cerr << leave[root(k-1)] << '\n';
                // cerr << root(leave[root(k-1)]) << '\n';
                // cerr << root(k) << '\n';
                cout << "YES\n";
            } else {
                cout << "N/A\n";
            }
        }
    }
}