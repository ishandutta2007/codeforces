#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b)
        swap(a, b);
    cout << b - a - max(0, min(c + r, b) - max(c - r, a)) << "\n";
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