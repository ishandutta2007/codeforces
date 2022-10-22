#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> b;
    for (int i = 0; i < n; i++) b.insert(a[i]);
    if (b.size() > k) {
        cout << -1 << endl;
        return;
    }
    int j = 1;
    while (b.size() < k) {
        if (b.find(j) == b.end()) {
            b.insert(j);
        }
        j++;
    }
    cout << n * k << endl;
    for (int i = 0; i < n; i++) {
        for (auto el : b) cout << el << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) solve();
}