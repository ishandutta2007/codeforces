#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, k, a, b;
    cin >> n >> m >> k >> a >> b;

    a--; b--;
    a /= k;
    b /= k;

    int x1 = a / m, y1 = a % m;
    int x2 = b / m, y2 = b % m;

    int res = 0;
    if (x1 == x2) {
        res += min(abs(y1 - y2) * 5, 10 + abs(y1 - y2));
    } else {
        res += min(y1 * 5, 10 + y1);
        res += min(y2 * 5, 10 + y2);
        res += 15 * min(abs(x1 - x2), n - abs(x1 - x2));
    }

    cout << res << endl;
}