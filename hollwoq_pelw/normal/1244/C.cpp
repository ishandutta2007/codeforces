#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    for (int y = 0; y < w; y++) {
        int r = p - y * d;
        if (r >= 0 && r % w == 0 && y + r / w <= n) {
            cout << r / w << ' ' << y << ' ' << n - (r / w) - y;
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}