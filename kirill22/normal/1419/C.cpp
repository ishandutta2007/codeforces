#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

void solve() {
    int n, x, s = 0, f = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        if (a[i] == x) f = true;
    }
    sort(all(a));
    if (a[0] == a[n - 1] && a[0] == x) {
        cout << 0 << '\n';
        return;
    }
    if (s == n * x || f) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
}