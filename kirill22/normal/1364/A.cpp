#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define ld long double
#define pb push_back

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (s % x != 0) {
        cout << n << endl;
    }
    else {
        int l = 0, r = n - 1;
        while (l < n && a[l] % x == 0) {
            l++;
        }
        while (r >= 0 && a[r] % x == 0) {
            r--;
        }
        int res = -1;
        if (l < n - 1) {
            res = n - l - 1;
        }
        if (r > 0) {
            res = max(res, r);
        }
        cout << res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}