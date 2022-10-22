#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) {
        int n, k;
        cin >> n >> k;
        int res = k / (n - 1);
        if (res * (n - 1) == k) {
            cout << n * res - 1;
        }
        else {
            cout << n * res + (k - res * (n - 1));
        }
        cout << endl;
    }
}