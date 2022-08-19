#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long sum = 0;
    pair<int, int> mx, ans;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        mx = max(mx, make_pair(a[i], i + 1));
        if (sum - mx.first <= s)
            ans = max(ans, make_pair(i, mx.second));
        if (sum <= s)
            ans = max(ans, make_pair(i + 1, 0));
    }
    cout << ans.second << "\n";
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