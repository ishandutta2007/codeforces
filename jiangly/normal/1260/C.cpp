#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    cout << (a == b || max(a, b) - 1 <= 1LL * min(a, b) * (k - 1) ? "OBEY" : "REBEL") << "\n";
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