#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int ans = 1, s = 0;
        while (ans < n) {
            s += ans;
            ans *= 3;
        }
        if (s >= n) {
            if (ans != 1) {
                int k = ans;
                while (k) {
                    k /= 3;
                    if (s - k >= n) {
                        s -= k;
                    }
                }
                ans = min(ans, s);
            }
        }
        cout << ans << endl;
    }
}