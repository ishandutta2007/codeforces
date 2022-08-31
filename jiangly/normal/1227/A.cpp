#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int mx = 0, mn = 1E9;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        mx = max(mx, l);
        mn = min(mn, r);
    }
    cout << max(0, mx - mn) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}