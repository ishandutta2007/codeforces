#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = n - 1;
    while (x < n && s[x] == '0') ++x;
    while (y >= 0 && s[y] == '0') --y;
    if (x == n) cout << n << "\n";
    else cout << 2 * (n - min(x, n - y - 1)) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}