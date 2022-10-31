// Hydro submission #626b7d269f31360077e45501@1651211559307
#include <bits/stdc++.h>

using namespace std;

const auto N = 10;

using ll = long long;
using i64 = int64_t;

auto solve() -> void {
    i64 x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << min(abs(x - y) * a + min(x, y) * b, (x + y) * a) << endl;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    auto T = 1;
    // read(T);
    // scanf("%d", &T);
    cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}