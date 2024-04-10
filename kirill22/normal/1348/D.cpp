#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    n--;
    for (int k = 1; true; k++) {
        int res = 0;
        for (int i = 1; i <= k; i++) res += (1ll << i);
        if (res >= n) {
            cout << k << endl;
            vector<int> a(k);
            for (int i = 0; i < k; i++) a[i] = (1ll << (i + 1));
            res -= n;
            for (int i = k - 1; i >= 0; i--) {
                int mx = min(res, a[i] / 2);
                a[i] -= mx;
                res -= mx;
            }
            if (a[0] == 1) cout << 0 << " ";
            else cout << 1 << " ";
            for (int i = 1; i < k; i++) {
                cout << a[i] - a[i - 1] << " ";
            }
            cout << endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) solve();
}