#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(0, 2 * (max(a, max(b, c)) - min(a, min(b, c)) - 2)) << "\n";
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