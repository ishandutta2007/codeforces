#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i].first * i + 1);
    }
    cout << ans << endl;
    for (auto c : a) {
        cout << c.second << " ";
    }
}