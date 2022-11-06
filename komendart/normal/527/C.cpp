#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(false);

    int w, h, n;
    cin >> w >> h >> n;

    ordered_set bw; bw.insert(0); bw.insert(w);
    ordered_set bh; bh.insert(0); bh.insert(h);
    multiset<int> lw; lw.insert(w);
    multiset<int> lh; lh.insert(h);
    for (int i = 0; i < n; i++) {
        string t; int k;
        cin >> t >> k;
        if (t == "H") {
            int right = *bh.upper_bound(k);
            int left = *bh.find_by_order(bh.order_of_key(right) - 1);
            bh.insert(k);
            lh.erase(lh.lower_bound(right - left));
            lh.insert(k - left);
            lh.insert(right - k);
        } else {
            int right = *bw.upper_bound(k);
            int left = *bw.find_by_order(bw.order_of_key(right) - 1);
            bw.insert(k);
            lw.erase(lw.lower_bound(right - left));
            lw.insert(k - left);
            lw.insert(right - k);
        }
        cout << (*lw.rbegin()) * (long long) (*lh.rbegin()) << '\n';
    }
}