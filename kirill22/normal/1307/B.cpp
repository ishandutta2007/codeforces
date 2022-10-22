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
        bool f = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == d) f = true;
        }
        sort(a.rbegin(), a.rend());
        if (f) {
            cout << 1 << endl;
            continue;
        }
        int z = (d + a[0] - 1) / a[0];
        cout << max(z, 2ll) << endl;
    }
}