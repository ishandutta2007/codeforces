#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, p, d, w;
    cin >> n >> p >> d >> w;
    LL y = 0;
    while (y < d && (p - w * y) % d != 0) ++y;
    if (y < d) {
        LL x = (p - w * y) / d;
        LL z = n - x - y;
        if (x >= 0 && z >= 0) cout << x << " " << y << " " << z << "\n";
        else cout << "-1\n";
    } else cout << "-1\n";
    return 0;
}