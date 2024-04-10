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
        int n, q;
        cin >> n >> q;
        deque<pair<int, int>> a(n);
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            a[i] = {x-1, i};
        }

        vector<vector<int>> w(n);
        for (int i : ra(0, n)) {
            auto x = a[0];
            auto y = a[1];
            a.pop_front();
            a.pop_front();
            w[max(x, y).second].push_back(i);
            a.push_front(max(x, y));
            a.push_back(min(x, y));
        }

        while (q--) {
            int i, k;
            cin >> i >> k;
            i--;
            if (k <= n) {
                cout << R::lower_bound(w[i], k) - begin(w[i]) << '\n';
            } else {
                if (a[0].second == i) {
                    cout << k-n+w[i].size() << '\n';
                } else {
                    cout << w[i].size() << '\n';
                }
            }
        }
    }
}