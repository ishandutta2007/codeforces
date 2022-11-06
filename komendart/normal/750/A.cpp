#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    int t = 240 - k;

    for (int i = 1; i <= n; ++i) {
        t -= 5 * i;
        if (t < 0) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}