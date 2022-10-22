#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    q = 1;
    while (q--) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        int i = 0, j = 0;
        for (i = 0; i < n; i++) {
            if (a[i] % p != 0) break;
        }
        for (j = 0; j < m; j++) {
            if (b[j] % p != 0) break;
        }
        cout << i + j << endl;
    }
}