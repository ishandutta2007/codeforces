#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        cout << (upper_bound(a.begin(), a.end(), t) - a.begin()) << '\n';
    }
}