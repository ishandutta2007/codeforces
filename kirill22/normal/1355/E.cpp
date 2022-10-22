#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, A, R, M;
    cin >> n >> A >> R >> M;
    int ans = 1e18;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    set<int> b;
    for (auto x : a) {
        b.insert(x);
    }
    for (int i = 1; i < n; i++) {
        int s = (i) * a[i] - pref[i], s2 = pref[n] - pref[i] - (n - i) * a[i];
        int k = s - s2;
        int r = k / n;
        int x = a[i] - r;
        b.insert(x);
    }
    for (auto x : b) {
        if (x < 0) continue;
        int l = -1, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[m] < x) l = m;
            else r = m;
        }
        int s = (l + 1) * x - pref[l + 1], s2 = pref[n] - pref[l + 1] - (n - l - 1) * x;
        if (s > s2) {
            ans = min(ans, s2 * M + (s - s2) * A);
        }
        else {
            ans = min(ans, s * M + (s2 - s) * R);
        }
        ans = min(ans, s * A + s2 * R);
    }
    cout << ans;
}