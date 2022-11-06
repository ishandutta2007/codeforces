#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxw = 1e6;

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(1);
    a.push_back(maxw);
    sort(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 0; i < sz(a) - 1; ++i) {
        ans = min(ans, max(a[i] - 1, maxw - a[i + 1]));
    }
    cout << ans << '\n';



}