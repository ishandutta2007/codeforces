#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    int x = abs(a - b) / 5;
    int ans = x + (abs(a - b) % 5 + 1) / 2;
    if (a > b && a - (x + 1) * 5 >= 0)
        ans = min(ans, x + 1 + (b - a + (x + 1) * 5 + 1) / 2);
    cout << ans << "\n";
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