#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int ans = -1;
    for (int i = 0; i < k1; ++i) {
        int x;
        cin >> x;
        if (x == n)
            ans = 0;
    }
    for (int i = 0; i < k2; ++i) {
        int x;
        cin >> x;
        if (x == n)
            ans = 1;
    }
    cout << (ans == 0 ? "YES" : "NO") << "\n";
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