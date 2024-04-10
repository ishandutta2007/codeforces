#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = n;
        vector<int> b(n / 2), c(n / 2);
        for (int i = 0; i < n / 2; i++) {
            b[i] = max(a[i] + k, a[n - i - 1] + k);
            c[i] = min(a[i] + 1, a[n - i - 1] + 1);
        }
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        vector<int> d(2 * k + 1, 0);
        for (int i = 0; i < n / 2; i++) {
            d[a[i] + a[n - i - 1]]++;
        }
        int _b = -1, _c = -1;
        for (int i = 1; i <= 2 * k; i++) {
            int res = n / 2 - d[i];
            while (_b + 1 < b.size() && b[_b + 1] < i) _b++;
            while (_c + 1 < c.size() && c[_c + 1] <= i) _c++;
            res += (_b + 1) + ((int) c.size() - _c - 1);
            ans = min(ans, res);
        }
        cout << ans  << endl;
    }
}