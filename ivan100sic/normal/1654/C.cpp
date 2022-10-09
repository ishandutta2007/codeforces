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
        multiset<ll> ms;
        ll z = 0;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            ms.insert(x);
            z += x;
        }

        multiset<ll> q;
        q.insert(z);
        bool fail = 0;
        while (q.size()) {
            ll x = *prev(q.end());
            q.erase(prev(q.end()));

            ll y = *prev(ms.end());
            if (x > y) {
                q.insert(x/2);
                q.insert(x-x/2);
            } else if (x == y) {
                ms.erase(prev(ms.end()));
            } else {
                fail = 1;
                break;
            }
        }

        cout << (!fail ? "YES\n" : "NO\n");
    }
}