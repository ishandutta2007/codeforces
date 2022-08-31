#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = (a + c - 1) / c;
    int y = (b + d - 1) / d;
    if (x + y <= k) cout << x << " " << y << "\n";
    else cout << "-1\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}