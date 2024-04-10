#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int x[6] = {}, y[6] = {};
    for (int i = 0; i < 6; ++i) {
        cin >> x[i] >> y[i];
        x[i] *= 2;
        y[i] *= 2;
    }
    --x[2];
    ++x[3];
    --x[4];
    ++x[5];
    --y[2];
    ++y[3];
    --y[4];
    ++y[5];
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            if (x[0] <= x[i] && x[i] <= x[1] && y[0] <= y[j] && y[j] <= y[1] && (x[i] <= x[2] || x[3] <= x[i] || y[j] <= y[2] || y[3] <= y[j]) && (x[i] <= x[4] || x[5] <= x[i] || y[j] <= y[4] || y[5] <= y[j])) {
                cout << "YES" << '\n';
                return;
            }
    cout << "NO" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}