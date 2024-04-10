#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min((a + b + c) / 2, min(a + b, min(a + c, b + c))) << "\n";
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