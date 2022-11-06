#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    int tmp = n * (n - 1) / 2;
    int res = 0;
    for (int i = 1; i <= k && n >= 2; i++) {
        res += 2 * (n - 2) + 1;
        n -= 2;
    }

    res = min(res, tmp);
    cout << res << endl;
}