#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = a[0];
        for (int j = 1; j < n; j++) {
            if (d < j) break;
            int k = min(a[j], d / j);
            ans += k;
            d -= j * k;
        }
        cout << ans << endl;
    }
}