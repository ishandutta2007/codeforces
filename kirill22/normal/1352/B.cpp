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
        if (n >= k && k % 2 == n % 2) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) cout << 1 << " ";
            cout << n - (k - 1) << endl;
        }
        else if (n % 2 == 0 && 2 * k <= n) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) cout << 2 << " ";
            cout << n - 2 * (k - 1) << endl;
        }
        else cout << "NO\n";
    }
}