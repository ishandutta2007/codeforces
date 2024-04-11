#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxw = 1e5;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector< set<int> > d(maxw + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        d[x].insert(i);
    }
    int cur = 0;
    vector<int> order;
    for (int i = 1; i <= maxw; ++i) {
        while (!d[i].empty()) {
            auto it = d[i].lower_bound(cur);
            if (it == d[i].end()) {
                it = d[i].begin();
            }
            cur = *it;
            order.push_back(cur);
            d[i].erase(it);
        }
    }
    ordered_set s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    cur = -1;
    long long ans = 0;
    for (auto i: order) {
        int ncur = s.order_of_key(cur + 1);
        int ni = s.order_of_key(i + 1);
        if (i >= cur) {
            ans += ni - ncur;
        } else {
            ans += (int) (s.size()) + ni - ncur;
        }
        cur = i;
        s.erase(i);
    }
    cout << ans << '\n';
}