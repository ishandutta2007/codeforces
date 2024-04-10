#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + a[i];
    for (int i = 2 * k - 1; i < n; ++i)
        a[i] += a[i - k];
    for (int i = 0; i < k - 1; ++i)
        a[i] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (sum[(i + 1) % k] + a[i] <= p)
            ans = i + 1;
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