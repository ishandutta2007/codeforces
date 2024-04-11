#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define double long double

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, U;
    cin >> n >> U;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double ans = 0;
    for (int i = n - 3; i >= 0; --i) {
        int j = i + 1;
        int k = upper_bound(a.begin(), a.end(), a[i] + U) - a.begin();
        --k;
        if (k > j) {
            ans = max(ans, (double) (a[k] - a[j]) / (a[k] - a[i]));
        }
    }
    cout << fixed; cout.precision(12);
    if (ans == 0) cout << -1 << '\n';
    else cout << ans << '\n';
    
}