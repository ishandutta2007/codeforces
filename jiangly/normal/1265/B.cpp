#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        p[x] = i;
    }
    int mn = n, mx = 0;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, p[i]);
        mx = max(mx, p[i]);
        cout << (i == mx - mn);
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}