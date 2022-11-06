#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        sort(a.begin(), a.begin() + k);
        long long t = 0;
        for (int i = k - 1; i >= 0; i -= 2) {
            t += a[i];
        }
        if (t <= h) {
            ans = k;
        }
    }
    cout << ans << endl;
}