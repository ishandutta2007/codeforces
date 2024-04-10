#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i % k] = max(a[i % k], x);
    }
    cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
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