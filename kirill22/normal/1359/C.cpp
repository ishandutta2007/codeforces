#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define all(a) a.begin(), a.end()

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    if (t * 2 <= h + c) {
        cout << 2 << endl;
        return;
    }
    if (t == h) {
        cout << 1 << endl;
        return;
    }
    int n = (t - h) / (h + c - 2 * t);
    long double res = (long double) ((n + 1) * h + n * c) / (2 * n + 1);
    long double res2 = (long double) ((n + 2) * h + (n + 1) * c) / (2 * n + 3);
    if (abs(res - t) <= abs(res2 - t)) cout << 2 * n + 1 << endl;
    else cout << 2 * n + 3 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}