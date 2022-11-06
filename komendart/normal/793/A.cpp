#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int mi = *min_element(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] - mi) % k != 0) {
            cout << -1 << '\n';
            return 0;
        }
        ans += (a[i] - mi) / k;
    }
    cout << ans << endl;
}