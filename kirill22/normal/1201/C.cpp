#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n;i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    int l = a[n / 2], r = 1e12;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        bool f = false;
        int ind = upper_bound(a.begin(), a.end(), m) - a.begin() - 1;
        int sum = (ind - n / 2 + 1) * m - (pref[ind + 1] - pref[n/ 2]);
        if (sum <= k) {
            f = true;
        }
        if (f) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << l;
}