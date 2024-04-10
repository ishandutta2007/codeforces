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
        vector<int> c(n+1);
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            c[x]++;
        }

        multiset<int> unused;
        ll cost = 0, covered = 0;
        for (int x : ra(0, n+1)) {
            ll ans;
            if (covered != x) {
                ans = -1;
            } else {
                ans = cost + c[x]; 
            }

            cout << ans << ' ';

            for (int i : ra(0, c[x])) {
                unused.insert(x);
            }

            while (unused.size() && covered != x+1) {
                auto it = unused.upper_bound(covered);
                if (it != unused.begin()) {
                    --it;
                    cost += covered - *it;
                    covered++;
                    unused.erase(it);
                } else {
                    break;
                }
            }
        }

        cout << '\n';
    }
    
}