#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void solve() {
    int n;
    cin >> n;
    int c[2] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++c[x % 2];
    }
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans += c[x % 2];
    }
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