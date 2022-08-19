#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> sum(2 * n + 1), pos(2 * n + 1, -n);
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        --x;
        sum[i + 1] = sum[i] + (x == 1 ? 1 : -1);
    }
    for (int i = 0; i <= n; ++i)
        pos[sum[i] + n] = i;
    int ans = 2 * n;
    for (int i = n; i <= 2 * n; ++i)
        ans = min(ans, i - pos[sum[i] - sum.back() + n]);
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