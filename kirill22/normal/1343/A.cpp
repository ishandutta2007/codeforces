#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int ans = 0, tmp = 1;
        for (int i = 1; true; i++) {
            tmp += (1ll << i);
            if (n % tmp == 0) {
                ans = n / tmp;
                break;
            }
        }
        cout << ans << endl;
    }
}