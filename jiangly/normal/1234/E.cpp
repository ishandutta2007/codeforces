#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int &i : x) {
        cin >> i;
        --i;
    }
    vector<LL> ans(n + 1);
    for (int i = 0; i < m - 1; ++i) {
        int a = x[i], b = x[i + 1];
        if (a > b)
            swap(a, b);
        if (a == b)
            continue;
        ans[0] += b - a;
        ans[a] -= b - a;
        ans[a] += b;
        ans[a + 1] -= b;
        ans[a + 1] += b - a - 1;
        ans[b] -= b - a - 1;
        ans[b] += a + 1;
        ans[b + 1] -= a + 1;
        ans[b + 1] += b - a;
        ans[n] -= b - a;
    }
    for (int i = 0; i < n; ++i)
        ans[i + 1] += ans[i];
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}