// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ordered_set<pair<int, int>> os;
        ll sol = 0;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            int sl = os.order_of_key({x, -1});
            int sg = i - os.order_of_key({x, 123123123});
            sol += min(sl, sg);
            os.insert({x, i});
        }

        cout << sol << '\n';
    }
}