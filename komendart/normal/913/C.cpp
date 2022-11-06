#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> c(30, 1e18);
    int n, L;
    cin >> n >> L;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i < 30; ++i) {
        c[i] = min(c[i], 2 * c[i - 1]);
    }
    int sum = 0;
    int ans = 1e18;
    for (int i = 29; i >= 0; --i) {
        if (L & (1 << i)) sum += c[i];
        ans = min(ans, sum + c[i]);
    }
    ans = min(ans, sum);
    cout << ans << endl;
}