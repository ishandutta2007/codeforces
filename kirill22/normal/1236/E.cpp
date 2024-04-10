#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int s = 1e7, BEGIN = 5 * 1e6;
    vector<int> l(s), r(s);
    for (int i = 0; i < s; i++) {
        l[i] = i - m - 1;
        r[i] = i + m  + 1;
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int R = (m - i) + a[i] + BEGIN;
        int L = a[i] - (m - i) + BEGIN;
        l[R] = l[R + 1];
        r[L] = r[L - 1];
        //cout << L << " " << r[L] << endl;
    }
    for (int i = 1; i <= n; i++) {
        ans += min(n, r[i + BEGIN] - BEGIN) - max(1ll, l[i + BEGIN] - BEGIN) + 1;
        //cout << r[i + BEGIN] << " " << l[i + BEGIN] << endl;
    }
    cout << ans;
}