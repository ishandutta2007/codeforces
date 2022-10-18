#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    set<int> reduce_set(v.begin(), v.end());
    vector<int> reduce_vec(reduce_set.begin(), reduce_set.end());
    for (auto& x : v) {
        x = lower_bound(reduce_vec.begin(), reduce_vec.end(), x) - reduce_vec.begin();
    }

    vector<int> cnts(reduce_set.size(), 0);
    for (int x : v) {
        cnts[x] = x ? cnts[x-1] + 1 : 1;
    }
    int ma = *max_element(cnts.begin(), cnts.end());
    cout << n - ma << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}