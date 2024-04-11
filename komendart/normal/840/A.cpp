#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector< pair<int, int> > b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    sort(a.rbegin(), a.rend());
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[b[i].second] = a[i];
    }
    for (auto i: ans) {
        cout << i << ' ';
    }
}