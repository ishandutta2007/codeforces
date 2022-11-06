#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mi = *min_element(a.begin(), a.end());
    int ma = *max_element(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != mi && a[i] != ma) {
            ++ans;
        }
    }
    cout << ans << '\n';
}