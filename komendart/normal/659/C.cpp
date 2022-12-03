#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.insert(t);
    }
    vector<int> ans;
    for (int i = 1; m - i >= 0; i++) {
        if (a.find(i) == a.end()) {
            m -= i;
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (auto i: ans) {
        cout << i << ' ';
    }
}