#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    int ans = 0;
    while (ans * (ans + 1) / 2 < d || (ans * (ans + 1) / 2 - d) % 2 != 0)
        ++ans;
    cout << ans << "\n";
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