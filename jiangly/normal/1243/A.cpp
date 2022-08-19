#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, min(i + 1, a[i]));
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