#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += i * a[i].first + 1;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i].second + 1;
        if (i < n - 1)
            cout << ' ' ;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}