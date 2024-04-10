#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    int a[4] = {};
    int total = 0;
    for (int &i : a) {
        cin >> i;
        total += i;
    }
    if (2 * a[0] == total || 2 * a[1] == total || 2 * a[2] == total || 2 * a[3] == total || 2 * (a[0] + a[1]) == total || 2 * (a[0] + a[2]) == total || 2 * (a[0] + a[3]) == total)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}