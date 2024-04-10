#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    int ans = 0;
    vector<int> c(n), t(n), sum(n + 1), p(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return t[i] < t[j];
    });
    for (int i = n - 1; i >= 0; --i)
        sum[i] = sum[i + 1] + c[p[i]];
    long long nec = 0;
    int ti = t[p[0]] - 1;
    if (ti >= 1LL * (n - sum[0]) * a) {
        ans = max(ans, min(n, n - sum[0] + (ti - (n - sum[0]) * a) / b));
    } else if (ti >= 0) {
        ans = max(ans, (ti - int(nec)) / a);
    }
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && t[p[i]] == t[p[j]]) {
            nec += c[p[j]] == 0 ? a : b; 
            ++j;
        }
        int ti = j == n ? T : t[p[j]] - 1;
        if (ti >= nec + 1LL * (n - j - sum[j]) * a) {
            ans = max(ans, min(n, n - sum[j] + (ti - int(nec) - (n - j - sum[j]) * a) / b));
        } else if (ti >= nec) {
            ans = max(ans, j + (ti - int(nec)) / a);
        }
        i = j;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}