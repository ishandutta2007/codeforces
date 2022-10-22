#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x - a[i];
    }
    sort(a.rbegin(), a.rend());
    multiset<int> b;
    for (auto x : a) {
        b.insert(x);
    }
    int ans = 0;
    for (auto x : a) {
        if (x < 0) {
            continue;
        }
        if (b.find(x) == b.end()) {
            continue;
        }
        b.erase(b.find(x));
        auto it = b.lower_bound(-x);
        if (it != b.end()) {
            ans++;
            b.erase(it);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}