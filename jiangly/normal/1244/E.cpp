#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INFLL = 1E18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    LL k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    LL ans = a[n - 1] - a[0];
    for (int i = 0; i < (n - 1) / 2; ++i) {
        LL t = min(a[i + 1] - a[i] + a[n - i - 1] - a[n - i - 2], k / (i + 1));
        ans -= t;
        k -= t * (i + 1);
    }
    if (n % 2 == 0) {
        LL t = min(a[n / 2] - a[n / 2 - 1], k / (n / 2));
        ans -= t;
        k -= t * (n / 2);
    }
    cout << ans << "\n";
    return 0;
}