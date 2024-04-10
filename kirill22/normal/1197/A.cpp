#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
         int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = n - 2;
        sort(a.begin(), a.end());
        ans = min(ans, a[n - 2] - 1);
        cout << ans << endl;
    }

}