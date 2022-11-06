#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;
    if (a % k != 0 && b < k || b % k != 0 && a < k) {
        cout << -1 << '\n';
        return 0;
    }

    cout << a / k + b / k << '\n';
}