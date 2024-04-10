#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.rbegin(), b.rend());
    int res = 0;
    int mx = 1e18;
    for (int i = 0; i < k; i++) {
        res += b[i];
        if (b[i] < mx) {
            mx = b[i];
        }
    }
    cout << res << " ";
    res = 1;
    const int mod = 998244353;
    int tmp = 0;
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] >= mx) {
            if (p == -1) p = i;
            else {
                res = (res * (i - p)) % mod;
                p = i;
            }
        }
    }
    cout << res;
}