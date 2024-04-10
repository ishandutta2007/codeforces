#include <bits/stdc++.h>
using namespace std;

main() {
    int n, d, e;
    cin >> n >> d >> e;
    e *= 5;
    int ans = 1e9;
    for (int i = 0; i <= n; i += d) {
        ans = min(ans, (n - i) % e);
    }
    cout << ans;
    return 0;
}