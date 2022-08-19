#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, a, b, s;
    cin >> a >> b >> n >> s;
    if (1LL * min(a, s / n) * n + b >= s)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
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