#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnt++;
            pos.push_back(i);
        }
    }
    if (cnt % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    long long ans = 0;
    if (cnt >= 4) {
        ans = y * 1ll * cnt / 2;
    } else if (cnt == 2) {
        if (pos[0] + 1 == pos[1]) {
            ans = min(x, 2 * y);
        } else {
            ans = y;
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