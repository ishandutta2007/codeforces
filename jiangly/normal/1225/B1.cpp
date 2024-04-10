#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2E5, K = 1E6;
int T;
int n, k, d, tmp;
int c[K], a[N];
void solve() {
    cin >> n >> k >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    tmp = 0;
    for (int i = 0; i < d; ++i)
        tmp += c[a[i]]++ == 0;
    int ans = tmp;
    for (int i = d; i < n; ++i) {
        tmp += c[a[i]]++ == 0;
        tmp -= --c[a[i - d]] == 0;
        ans = min(ans, tmp);
    }
    for (int i = n - d; i < n; ++i)
        --c[a[i]];
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
        solve();
    return 0;
}