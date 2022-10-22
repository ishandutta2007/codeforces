#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    for (auto [x, y] : a) {
        ans += min(y, c);
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